def makePrefixObjectType(handle_value, prefix):
    return_string=prefix
    value=''

    # Save the extension and get rid of it so we don't parse it out
    extension = ''
    if handle_value.endswith('KHR'):
        extension = '_KHR'
        value = handle_value[2:-3]
    elif handle_value.endswith('EXT'):
        extension = '_EXT'
        value = handle_value[2:-3]
    elif handle_value.endswith('AMD'):
        extension = '_AMD'
        value = handle_value[2:-3]
    elif handle_value.endswith('NVX'):
        extension = '_NVX'
        value = handle_value[2:-3]
    elif handle_value.endswith('NV'):
        extension = '_NV'
        value = handle_value[2:-2]
    elif handle_value.endswith('INTEL'):
        extension = '_INTEL'
        value = handle_value[2:-5]
    elif handle_value.endswith('FUCHSIA'):
        extension = '_FUCHSIA'
        value = handle_value[2:-7]
    else:
        value = handle_value[2:]

    for index, cur_char in enumerate(value):
        if index > 0 and cur_char.isupper():
            return_string += '_'
        return_string += cur_char

    if len(extension) > 0:
        return_string += extension

    return return_string.upper()

def makeObjectType(handle_value):
    return makePrefixObjectType(handle_value, 'VK_OBJECT_TYPE_')
