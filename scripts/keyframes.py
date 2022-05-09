#!/usr/bin/env python3
"""Given a file with a set of (ASCII) commands, identify "interesting"
keyframes based on distinct maximal function sets used in a frame.  Keyframes
selected in this way tend to exercise more distinct parts of the trace,
as many frames will use the same "footprint" of functions as other frames;
by collapsing to maximal function sets, keyframes can be selected that more
thoroughly exercise the graphics API.

The selected keyframes can be further refined through the use of filter
operations.

To use on a trace captured by gfxreconstruct, the trace must be converted
to an ASCII command file containing one function or method name per line, e.g.:

    ...
    vkDestroyImageView
    vkBeginCommandBuffer
    vkCmdPipelineBarrier
    vkCmdWriteTimestamp
    vkAcquireNextImageKHR
    vkCmdPipelineBarrier
    vkCmdBeginRenderPass
    vkCmdBindPipeline
    vkCmdBindDescriptorSets
    vkCmdSetViewport
    vkCmdBindIndexBuffer
    vkCmdDrawIndexed
    vkCmdPipelineBarrier
    vkCmdWriteTimestamp
    vkCmdEndRenderPass
    vkCmdResetQueryPool
    vkEndCommandBuffer
    vkFlushMappedMemoryRanges
    vkResetFences
    vkQueueSubmit
    vkQueuePresentKHR
    ...

The command file must include frame marker functions (e.g. vkQueuePresentKHR
for Vulkan, or Present for DX12); if it does not, no frame boundaries can
be established, and keyframes cannot be calculated.

The gfxrecon-toascii tool can be used to create such a file from a trace
file, using an editor or a script to extract only the function or method
name associated with each captured call.

Then using this script will yield the keyframes, e.g.:

    $ python3 keyframes.py commandfile.txt
    INFO: processing the command file commandfile.txt...
    INFO: sorting 70 function sets by cardinality...
    INFO: collapsing into maximal distinct sets...
    INFO: filtering 10 keyframes from 22 maximal sets...
    INFO: Keyframes in priority order: 0,1908,1051,1910,2086,4280,5329,1616,2088,4281
    INFO: Keyframes in sorted order:   0,1051,1616,1908,1910,2086,2088,4280,4281,5329
"""

import argparse
import logging
import sys

log = logging.getLogger(__name__)

class KeyframeException(Exception):
    """Exception class for this module."""

##################################################################
# Filter functions.  Each of these provides a condition that can
# be used to disqualify frames from selection.

class Filter:
    """This represents a keyframe filter that can be used to limit the
    choices of keyframes."""

    # The filter name is used by the '--filters' switch.
    name = None
    description = None

    def __init__(self):
        """Filter-specific initialization."""

    def preArgumentParse(self, parser):
        """Add any command-line arguments used by this filter to the
        argument parser."""

    def postArgumentParse(self, args):
        """Parse any command-line arguments needed by this filter."""

    def allowed(self, frame, keyframes):
        """Return True if the given frame can be added to the given
        list of existing keyframes.  Return False if it cannot."""
        raise NotImplementedError

def getFilterByName(name):
    """Return an instance of a keyframe filter that has a class.name field
    that matches the given "name"."""
    for filter_subclass in Filter.__subclasses__():
        if filter_subclass.name == name:
            return filter_subclass()
    raise KeyframeException(f'no keyframe filter named "{name}" is available')

class FilterDistance(Filter):
    """Require that two keyframes be a minimum number of frames apart."""
    name = 'distance'
    description = 'require keyframes be a minimum number of frames apart'

    def __init__(self):
        super().__init__()
        self.distance = None

    def preArgumentParse(self, parser):
        """Add the distance filter arguments."""
        distance_group = parser.add_argument_group(f'{self.name} filter arguments')
        distance_group.add_argument('-d', '--distance', type=int, default=30,
                                    help='the minimum distance between two keyframes [%(default)s]')

    def postARgumentParse(self, args):
        """Process the distance filter arguments."""
        self.distance = args.distance

    def allowed(self, frame, keyframes):
        """Return False if the new candidate frame is too close to any of the existing
        keyframes."""
        for keyframe in keyframes:
            if keyframe - self.distance < frame < keyframe + self.distance:
                return False
        return True

##################################################################
# Utility functions.

def Ranges(values):
    """Given a sorted list of unique integers, convert them into a list
    of lists of consecutive items, e.g. [1,2,3, 7,8,9,  15, 17,18] =>
    [[1,2,3], [7,8,9], [15], [17,18]]."""

    # There is a Python recipe using itertools.groupby().  It's hard
    # to understand, so I'm using a more straightforward generator.
    first = last = values[0]
    for value in values[1:]:
        if value == last + 1:
            # Consecutive - keep searching
            last = value
        else:
            # Next value is not consecutive - return the last group
            yield first, last
            # and when we come back, advance to the next
            first = last = value
    # Yield the last group, then we're done
    yield first, last

# The set of commands that identify where frames end.
FRAME_END_FUNCTIONS = {
    # Vulkan
    'vkQueuePresentKHR',
    # DX12
    'Present',
}

def getCommandFileFootprintsToFrames(commandfile):
    """Given the name of a commandfile, returns a dictionary indexed
    by frame "footprints" (i.e. sets of API commands that were used
    in a frame), each of which is associated with a list of frame
    numbers that have that same "footprint"."""

    # gfxreconstruct numbers frames starting from 1.
    frame_number = 1
    footprints_to_frames = {}
    frame_footprint = set()

    log.info("processing the command file %s...", commandfile)
    with open(commandfile, "rt") as f:
        for line in f:
            # Right now command lines are just function names.
            function_name = line.strip()

            # If it's a normal function, just save it and keep going.
            if function_name not in FRAME_END_FUNCTIONS:
                frame_footprint.add(function_name)
                continue

            # Here, we're done with the frame.  Freeze the set to make it
            # hashable, so we can use it in hashmaps.
            log.debug('    finishing frame %s...', frame_number)

            frozen_footprint = frozenset(frame_footprint)
            try:
                footprints_to_frames[frozen_footprint].append(frame_number)
            except KeyError:
                footprints_to_frames[frozen_footprint] = [frame_number]

            # Get ready for the next set.
            frame_footprint.clear()
            frame_number += 1

        # end for line in f
    # end with open

    # Note that it's possible that there are functions after the last complete
    # frame.  We're generally not interested in these because they are never
    # presented, so we can ignore them safely.

    # If there are no sets, something is terribly wrong.
    if not footprints_to_frames:
        raise KeyframeException(f'no frame separators found in command file {commandfile}')

    return footprints_to_frames

def getMaximalSets(sets):
    """Given a list of sets, return a list of maximal sets from the list, sorted
    by set cardinality (the number of elements in the set).  A "maximal set" is
    one that is not a subset of any other set in the list."""

    # Start with the largest sets and work our way down.
    log.info('sorting %s function sets by cardinality...', len(sets))
    sets_by_cardinality = sorted(sets, key=len, reverse=True)

    # The largest set is certainly maximal, as it cannot be a subset of any other.
    maximal_sets = [sets_by_cardinality.pop(0)]

    # For each remaining set, discard it if it is a proper subset of
    # any of the current maximal sets.
    for next_set in sets_by_cardinality:
        for maximal_set in maximal_sets:
            if next_set < maximal_set:
                break
        # "else" on a for loop is triggered only if the loop falls through
        # without a break.  In this case, that means that the set was
        # *not* a subset of any existing maximal set, which means it's our
        # next entry.
        else:
            maximal_sets.append(next_set)

    return maximal_sets

def getKeyframes(maximal_footprints, footprints_to_frames, max_keyframes, filters):
    """Given a sorted list of frame footprints and a mapping of those footprints to lists
    of frames, select at most one frame from each footprint, up to the
    "max_keyframes" given, and return the list of keyframes (in order of discovery,
    i.e. the frame from the most maximal footprint comes first).  If filters are
    provided, they can disqualify a frame from consideration, which can result in
    no frames being selected from a particular footprint."""

    log.info('filtering %s keyframes from %s maximal footprints...',
             max_keyframes, len(maximal_footprints))
    keyframes = []
    for footprint in maximal_footprints:
        # Done if we've selected all we need.
        if len(keyframes) >= max_keyframes:
            break

        # Get a list of candidate frames from this footprint.
        candidate_frames = footprints_to_frames[footprint]

        # Select a frame; attempt all the filters on the frame.
        for first_frame, last_frame in Ranges(candidate_frames):
            frame = int((first_frame + last_frame)/2)
            for f in filters:
                if not f.allowed(frame, keyframes):
                    # Break means this frame failed the filter.
                    break
            else:
                # Here, we got through all the filters, so this frame
                # is a good candidate.
                keyframes.append(frame)
                # break here means we've found a good frame and can exit the "for frame" loop.
                break
        # end for each frame range
    # end for each footprint

    return keyframes


##################################################################
# Main program.
def main():
    """Main program function."""
    LOG_LEVELS = ['CRITICAL', 'ERROR', 'WARNING', 'INFO', 'DEBUG']
    LOG_FORMAT = '%(levelname)s: %(message)s'

    parser = argparse.ArgumentParser(description='identify interesting keyframes')
    parser.add_argument('--log-level', type=str.upper, default='INFO', choices=LOG_LEVELS,
                        help='the desired logging level [%(default)s]')
    common = parser.add_argument_group('common arguments')
    common.add_argument('-n', type=int, default=10,
                        help="how many keyframes to return [%(default)s]")

    filter_descriptions = [f'{x.name} ({x.description})' for x in Filter.__subclasses__()]
    filter_help = ('comma-separated list of keyframe filters to use [none]; available filters are: '
                   + '; '.join(filter_descriptions))
    common.add_argument('-f', '--filters', help=filter_help)
    common.add_argument('commandfile',
                        help="The command file to read")

    # Add command-line switches for all filters.
    for filter_class in Filter.__subclasses__():
        f = filter_class()
        f.preArgumentParse(parser)

    # Parse arguments.
    args = parser.parse_args()

    # Set up logging.
    logging.basicConfig(stream=sys.stdout, format=LOG_FORMAT, level=args.log_level)

    # Prepare a list of filters that we're actually going to use.
    filters = []
    if args.filters is not None:
        for filter_name in args.filters.split(','):
            f = getFilterByName(filter_name)
            filters.append(f)
            # Let active filters manage their arguments.
            f.postArgumentParse(args)

    # Read frames from the command file and convert to footprints.
    footprints_to_frames = getCommandFileFootprintsToFrames(args.commandfile)

    # Extract the maximal footprints from the dictionary.
    maximal_footprints = getMaximalSets(footprints_to_frames.keys())

    # Select a frame from each of our maximal footprints, until we
    # have the count we want or until we run out of footprints.
    keyframes = getKeyframes(maximal_footprints, footprints_to_frames, args.n, filters)

    # Give our output.
    log.info("Keyframes in priority order: %s", ",".join([str(x) for x in keyframes]))
    keyframes.sort()
    log.info("Keyframes in sorted order:   %s", ",".join([str(x) for x in keyframes]))

##################################################################
if __name__ == '__main__':
    main()
