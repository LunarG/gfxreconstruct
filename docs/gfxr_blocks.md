# GFXReconstruct Schema Documentation

This file documents the existing block types in GFXReconstruct as of 10/2025.
This file is manually maintained for now, and so may be out of date with respect to what currently exists in the source code.
## Index

- [File overview](#file-overview)
- [Block Type and Payloads](#block-type-and-payloads)
- [Enums](#enums)
- [Primitives](#primitives)
- [Special Field Kinds](#special-field-kinds)
- [Complex Types](#complex-types)
## File overview
A GFXReconstruct file is effectively a series of "blocks" layed out contiguously in memory:

<table style="border: 1px solid;">
    <tr style="border: 1px solid;">
        <td><a href="#complex-type-FileHeader">FileHeader</a></td>
    </tr>
    <tr><td>
        <table style="border: 1px solid;">
            <tr>
                <td><a href="#complex-type-BlockHeader">BlockHeader</a></td>
            </tr>
            <tr>
                <td><a href="#block-payloads">Block Payload</a></td>
            </tr>
        </table>
    </td></tr>
    <tr><td>
        <table style="border: 1px solid;">
            <tr>
                <td><a href="#complex-type-BlockHeader">BlockHeader</a></td>
            </tr>
            <tr>
                <td><a href="#block-payloads">Block Payload</a></td>
            </tr>
        </table>
    </td></tr>
    <tr><td>...</td></tr>
</table>

Each <a href="#enum-BlockType">BlockType</a> can have a custom header that derives from
<a href="#complex-type-BlockHeader">BlockHeader</a> to allow for additional block meta data that may
not be provided by the block payload. e.g., the FunctionCallHeader contains an <a href="#enum-ApiCallId">ApiCallId</a>
indicating which API the payload is associated with as well as a thread ID indicating the thread the API was executed from.

A **block payload** is a sequence of bytes directly following the (possibly subclass
of) <a href="#complex-type-BlockHeader">BlockHeader</a>. This sequence of bytes is _processed_ in the following way:
1. Decode:
   done using a subclass of [ApiDecoder](../framework/decode/api_decoder.h)
   and effectively deserializes function arguments, structs, etc.
2. Consume: an operation performed on the deserialized data from the decoder.

Typically a `Consumer` will be a member of a `Decoder` and the consumer is called after decoding (this
is usually defined through code generation). It may also make sense to have multiple consumers within
a decoder. For example, a decoder for handling OpenXR may have 2 consumers: 1 for OpenXR API calls,
and one for the graphics API being used in the application.

## Compression

A compression algorithm may be specified via a <a href="#complex-type-FileOptionPair">FileOptionPair</a> in the 
<a href="#complex-type-FileHeader">FileHeader</a> and defines how block payloads <i>may</i> be compressed.
(<a href="#complex-type-BlockHeader">BlockHeader</a>s are not compressed).
The most significant bit in the <code>BlockType</code> indicates whether or not that block's payload
is compressed using the algorithm defined in the [FileHeader](#complex-type-FileHeader)
(i.e., <code>payload_compressed == (type & 0x80000000) != 0</code>).

The supported compression types are indicated by the `CompressionType` enum in [format.h](../framework/format/format.h).

Below is a generated snapshot of block definitions for reference.
See the code, specifically [format.h](../framework/format/format.h), for the current defintions of each block.

## Block Type and Payloads

### Table Legend

#### "Count" special valuesBy default, the `Count` of a block field is a positive integer indicating the number of consecutive elements a particular field represents.
However, a field can also have a non-constant size as indicated in the following table:
<table style="border: 1px solid">
  <tr>
    <td>
      <code>$remaining</code>
    </td>
    <td>
      <code>BlockHeader::size - sizeof(all fields preceding this field)</code>
    </td>
  </tr>
  <tr>
    <td>
      <code>variable</code>
    </td>
    <td>
      <p>A reference to a variable within the current context (struct), indicating the count is the runtime value of this variable</p>
    </td>
  </tr>
  <tr>
    <td>
      <code>infix mathematical expression</code>
    </td>
    <td>
      <p>e.g., <code>label_length + data_length</code>
      </p>
    </td>
  </tr>
</table>

Table cells <span style="background-color: #9b1c1c57">with this background color</span> indicate a field that must be further processed and is not part of the uncompressed `BlockHeader` fields.

<table style="border: 1px solid">
  <thead>
    <tr>
      <th rowspan="2" style="text-align: center; vertical-align: middle;">Name</th>
      <th rowspan="2" style="text-align: center; vertical-align: middle;">Block Type Enum</th>
      <th colspan="4" style="border: 1px solid; text-align: center; vertical-align: middle;">Payload</th>
    </tr>
    <tr>
      <th style="border-left: 1px solid; text-align: center; vertical-align: middle;">Name</th>
      <th style="text-align: center; vertical-align: middle;">Type</th>
      <th style="text-align: center; vertical-align: middle;">Count</th>
      <th style="text-align: center; vertical-align: middle;">Details</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td rowspan="3" style="border-bottom: 5px solid;">FunctionCall</td>
      <td rowspan="3" style="border-bottom: 5px solid; border-right: 1px solid;">kFunctionCallBlock</td>
      <td>
        <code>api_call_id</code>
      </td>
      <td>
        <a href="#enum-ApiCallId">ApiCallId</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>thread_id</code>
      </td>
      <td>
        <a href="#primitive-u64">u64</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td>Uniquely identifies the thread that made the API call.</td>
    </tr>
    <tr style="background-color: #9b1c1c57;">
      <td style="border-bottom: 5px solid">
        <code>parameter_buffer</code>
      </td>
      <td style="border-bottom: 5px solid">
        <a href="#special-compressible_bytes">compressible_bytes</a>
      </td>
      <td style="border-bottom: 5px solid">
        <code>$remaining</code>
      </td>
      <td style="border-bottom: 5px solid">
        <p>Process function: <code>BlockParser::ParseFunctionCall</code>
          <p>A sequence of bytes containing the serialized parameters for the API call. The number of bytes in the buffer is encoded the first 8 uncompressed bytes.</p>
        </p>
      </td>
    </tr>
    <tr>
      <td rowspan="4" style="border-bottom: 5px solid;">MethodCall</td>
      <td rowspan="4" style="border-bottom: 5px solid; border-right: 1px solid;">kMethodCallBlock</td>
      <td>
        <code>api_call_id</code>
      </td>
      <td>
        <a href="#enum-ApiCallId">ApiCallId</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>object_id</code>
      </td>
      <td>
        <a href="#primitive-u64">u64</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td>Handle to the object this function call was invoked on.</td>
    </tr>
    <tr>
      <td>
        <code>thread_id</code>
      </td>
      <td>
        <a href="#primitive-u64">u64</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td>Uniquely identifies the thread that made the API call.</td>
    </tr>
    <tr style="background-color: #9b1c1c57;">
      <td style="border-bottom: 5px solid">
        <code>parameter_buffer</code>
      </td>
      <td style="border-bottom: 5px solid">
        <a href="#special-compressible_bytes">compressible_bytes</a>
      </td>
      <td style="border-bottom: 5px solid">
        <code>$remaining</code>
      </td>
      <td style="border-bottom: 5px solid">
        <p>Process function: <code>BlockParser::ParseMethodCall</code>
          <p> The number of bytes in the buffer is encoded the first 8 uncompressed bytes.</p>
        </p>
      </td>
    </tr>
    <tr>
      <td rowspan="2" style="border-bottom: 5px solid;">FrameMarker</td>
      <td rowspan="2" style="border-bottom: 5px solid; border-right: 1px solid;">kFrameMarkerBlock</td>
      <td>
        <code>marker_type</code>
      </td>
      <td>
        <a href="#enum-MarkerType">MarkerType</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td style="border-bottom: 5px solid">
        <code>frame_number</code>
      </td>
      <td style="border-bottom: 5px solid">
        <a href="#primitive-u64">u64</a>
      </td>
      <td style="border-bottom: 5px solid">
        <code>1</code>
      </td>
      <td style="border-bottom: 5px solid"></td>
    </tr>
    <tr>
      <td rowspan="2" style="border-bottom: 5px solid;">StateMarker</td>
      <td rowspan="2" style="border-bottom: 5px solid; border-right: 1px solid;">kStateMarkerBlock</td>
      <td>
        <code>marker_type</code>
      </td>
      <td>
        <a href="#enum-MarkerType">MarkerType</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td style="border-bottom: 5px solid">
        <code>frame_number</code>
      </td>
      <td style="border-bottom: 5px solid">
        <a href="#primitive-u64">u64</a>
      </td>
      <td style="border-bottom: 5px solid">
        <code>1</code>
      </td>
      <td style="border-bottom: 5px solid"></td>
    </tr>
    <tr>
      <td rowspan="4" style="border-bottom: 5px solid;">Annotation</td>
      <td rowspan="4" style="border-bottom: 5px solid; border-right: 1px solid;">kAnnotation</td>
      <td>
        <code>annotation_type</code>
      </td>
      <td>
        <a href="#enum-AnnotationType">AnnotationType</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>label_length</code>
      </td>
      <td>
        <a href="#primitive-u32">u32</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>data_length</code>
      </td>
      <td>
        <a href="#primitive-u64">u64</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr style="background-color: #9b1c1c57;">
      <td style="border-bottom: 5px solid">
        <code>combined_buffer</code>
      </td>
      <td style="border-bottom: 5px solid">
        <a href="#primitive-u8">u8</a>
      </td>
      <td style="border-bottom: 5px solid">
        <code>$remaining</code>
      </td>
      <td style="border-bottom: 5px solid">
        <p>Process function: <code>BlockParser::ParseAnnotation</code>
          <p>Uncompressed bytes containing both label and data (label first if present followed immediately by data if present).
The first label_length bytes (which could be 0) contain the label entry. The data entry (if present) will be the
next data_length bytes immediately following the label.
</p>
        </p>
      </td>
    </tr>
    <tr>
      <td rowspan="4" style="border-bottom: 5px solid;">MetaData</td>
      <td rowspan="4" style="border-bottom: 5px solid; border-right: 1px solid;">kMetaDataBlock</td>
      <td>
        <code>meta_data_id</code>
      </td>
      <td>
        <a href="#primitive-u32">u32</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>meta_data_type</code>
      </td>
      <td>
        <a href="#enum-MetaDataType">MetaDataType</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td style="border-bottom: 5px solid" colspan="4">
        <i>See the <a href="#metadata-block-variants">MetaData Blocks</a> table below for individual command variants.</i>
      </td>
    </tr>
  </tbody>
</table>

## MetaData Block Variants

Meta data blocks are processed in `BlockParser::ParseMetaData` which then processes the block payload based on the [meta_data_type](../framework/format/format.h) field.

<table style="border: 1px solid">
  <thead>
    <tr>
      <th style="text-align: center; vertical-align: middle;" rowspan="2">Variant Type Enum</th>
      <th colspan="4" style="border: 1px solid; text-align: center; vertical-align: middle;">Payload</th>
    </tr>
    <tr>
      <th style="border-left: 1px solid; text-align: center; vertical-align: middle;">Name</th>
      <th style="text-align: center; vertical-align: middle;">Type</th>
      <th style="text-align: center; vertical-align: middle;">Count</th>
      <th style="text-align: center; vertical-align: middle;">Details</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td rowspan="2" style="border-bottom: 5px solid; border-right: 1px solid;">kDisplayMessageCommand</td>
      <td>
        <code>thread_id</code>
      </td>
      <td>
        <a href="#primitive-u64">u64</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr style="background-color: #9b1c1c57;">
      <td style="border-bottom: 5px solid">
        <code>message</code>
      </td>
      <td style="border-bottom: 5px solid">
        <a href="#primitive-u8">u8</a>
      </td>
      <td style="border-bottom: 5px solid">
        <code>$remaining</code>
      </td>
      <td style="border-bottom: 5px solid"></td>
    </tr>
    <tr>
      <td rowspan="5" style="border-bottom: 5px solid; border-right: 1px solid;">kFillMemoryCommand</td>
      <td>
        <code>thread_id</code>
      </td>
      <td>
        <a href="#primitive-u64">u64</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>memory_id</code>
      </td>
      <td>
        <a href="#primitive-u64">u64</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>memory_offset</code>
      </td>
      <td>
        <a href="#primitive-u64">u64</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>memory_size</code>
      </td>
      <td>
        <a href="#primitive-u64">u64</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr style="background-color: #9b1c1c57;">
      <td style="border-bottom: 5px solid">
        <code>data</code>
      </td>
      <td style="border-bottom: 5px solid">
        <a href="#special-compressible_bytes">compressible_bytes</a>
      </td>
      <td style="border-bottom: 5px solid">
        <code>memory_size</code>
      </td>
      <td style="border-bottom: 5px solid"></td>
    </tr>
    <tr>
      <td rowspan="4" style="border-bottom: 5px solid; border-right: 1px solid;">kResizeWindowCommand</td>
      <td>
        <code>thread_id</code>
      </td>
      <td>
        <a href="#primitive-u64">u64</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>surface_id</code>
      </td>
      <td>
        <a href="#primitive-u64">u64</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>width</code>
      </td>
      <td>
        <a href="#primitive-u32">u32</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td style="border-bottom: 5px solid">
        <code>height</code>
      </td>
      <td style="border-bottom: 5px solid">
        <a href="#primitive-u32">u32</a>
      </td>
      <td style="border-bottom: 5px solid">
        <code>1</code>
      </td>
      <td style="border-bottom: 5px solid"></td>
    </tr>
    <tr>
      <td rowspan="6" style="border-bottom: 5px solid; border-right: 1px solid;">kSetSwapchainImageStateCommand</td>
      <td>
        <code>thread_id</code>
      </td>
      <td>
        <a href="#primitive-u64">u64</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>device_id</code>
      </td>
      <td>
        <a href="#primitive-u64">u64</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>swapchain_id</code>
      </td>
      <td>
        <a href="#primitive-u64">u64</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>last_presented_image</code>
      </td>
      <td>
        <a href="#primitive-u32">u32</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>image_info_count</code>
      </td>
      <td>
        <a href="#primitive-u32">u32</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td style="border-bottom: 5px solid">
        <code>image_state</code>
      </td>
      <td style="border-bottom: 5px solid">
        <a href="#complex-type-SwapchainImageStateInfo">SwapchainImageStateInfo[]</a>
      </td>
      <td style="border-bottom: 5px solid">
        <code>image_info_count</code>
      </td>
      <td style="border-bottom: 5px solid"></td>
    </tr>
    <tr>
      <td rowspan="4" style="border-bottom: 5px solid; border-right: 1px solid;">kBeginResourceInitCommand</td>
      <td>
        <code>thread_id</code>
      </td>
      <td>
        <a href="#primitive-u64">u64</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>device_id</code>
      </td>
      <td>
        <a href="#primitive-u64">u64</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>max_resource_size</code>
      </td>
      <td>
        <a href="#primitive-u64">u64</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td style="border-bottom: 5px solid">
        <code>max_copy_size</code>
      </td>
      <td style="border-bottom: 5px solid">
        <a href="#primitive-u64">u64</a>
      </td>
      <td style="border-bottom: 5px solid">
        <code>1</code>
      </td>
      <td style="border-bottom: 5px solid"></td>
    </tr>
    <tr>
      <td rowspan="2" style="border-bottom: 5px solid; border-right: 1px solid;">kEndResourceInitCommand</td>
      <td>
        <code>thread_id</code>
      </td>
      <td>
        <a href="#primitive-u64">u64</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td style="border-bottom: 5px solid">
        <code>device_id</code>
      </td>
      <td style="border-bottom: 5px solid">
        <a href="#primitive-u64">u64</a>
      </td>
      <td style="border-bottom: 5px solid">
        <code>1</code>
      </td>
      <td style="border-bottom: 5px solid"></td>
    </tr>
    <tr>
      <td rowspan="5" style="border-bottom: 5px solid; border-right: 1px solid;">kInitBufferCommand</td>
      <td>
        <code>thread_id</code>
      </td>
      <td>
        <a href="#primitive-u64">u64</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>device_id</code>
      </td>
      <td>
        <a href="#primitive-u64">u64</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>buffer_id</code>
      </td>
      <td>
        <a href="#primitive-u64">u64</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>data_size</code>
      </td>
      <td>
        <a href="#primitive-u64">u64</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr style="background-color: #9b1c1c57;">
      <td style="border-bottom: 5px solid">
        <code>data</code>
      </td>
      <td style="border-bottom: 5px solid">
        <a href="#special-compressible_bytes">compressible_bytes</a>
      </td>
      <td style="border-bottom: 5px solid">
        <code>data_size</code>
      </td>
      <td style="border-bottom: 5px solid"></td>
    </tr>
    <tr>
      <td rowspan="9" style="border-bottom: 5px solid; border-right: 1px solid;">kInitImageCommand</td>
      <td>
        <code>thread_id</code>
      </td>
      <td>
        <a href="#primitive-u64">u64</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>device_id</code>
      </td>
      <td>
        <a href="#primitive-u64">u64</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>image_id</code>
      </td>
      <td>
        <a href="#primitive-u64">u64</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>data_size</code>
      </td>
      <td>
        <a href="#primitive-u64">u64</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>aspect</code>
      </td>
      <td>
        <a href="#primitive-u32">u32</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>layout</code>
      </td>
      <td>
        <a href="#primitive-u32">u32</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>level_count</code>
      </td>
      <td>
        <a href="#primitive-u32">u32</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>level_sizes</code>
      </td>
      <td>
        <a href="#primitive-u64">u64[]</a>
      </td>
      <td>
        <code>level_count</code>
      </td>
      <td></td>
    </tr>
    <tr style="background-color: #9b1c1c57;">
      <td style="border-bottom: 5px solid">
        <code>data</code>
      </td>
      <td style="border-bottom: 5px solid">
        <a href="#special-compressible_bytes">compressible_bytes</a>
      </td>
      <td style="border-bottom: 5px solid">
        <code>data_size</code>
      </td>
      <td style="border-bottom: 5px solid"></td>
    </tr>
    <tr>
      <td rowspan="2" style="border-bottom: 5px solid; border-right: 1px solid;">kDestroyHardwareBufferCommand</td>
      <td>
        <code>thread_id</code>
      </td>
      <td>
        <a href="#primitive-u64">u64</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td style="border-bottom: 5px solid">
        <code>buffer_id</code>
      </td>
      <td style="border-bottom: 5px solid">
        <a href="#primitive-u64">u64</a>
      </td>
      <td style="border-bottom: 5px solid">
        <code>1</code>
      </td>
      <td style="border-bottom: 5px solid"></td>
    </tr>
    <tr>
      <td rowspan="10" style="border-bottom: 5px solid; border-right: 1px solid;">kSetDevicePropertiesCommand</td>
      <td>
        <code>thread_id</code>
      </td>
      <td>
        <a href="#primitive-u64">u64</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>physical_device_id</code>
      </td>
      <td>
        <a href="#primitive-u64">u64</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>api_version</code>
      </td>
      <td>
        <a href="#primitive-u32">u32</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>driver_version</code>
      </td>
      <td>
        <a href="#primitive-u32">u32</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>vendor_id</code>
      </td>
      <td>
        <a href="#primitive-u32">u32</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>device_id</code>
      </td>
      <td>
        <a href="#primitive-u32">u32</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>device_type</code>
      </td>
      <td>
        <a href="#primitive-u32">u32</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>pipeline_cache_uuid</code>
      </td>
      <td>
        <a>arrary</a>
      </td>
      <td>
        <code>16</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>device_name_len</code>
      </td>
      <td>
        <a href="#primitive-u32">u32</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr style="background-color: #9b1c1c57;">
      <td style="border-bottom: 5px solid">
        <code>device_name</code>
      </td>
      <td style="border-bottom: 5px solid">
        <a href="#primitive-u8">u8</a>
      </td>
      <td style="border-bottom: 5px solid">
        <code>device_name_len</code>
      </td>
      <td style="border-bottom: 5px solid"></td>
    </tr>
    <tr>
      <td rowspan="6" style="border-bottom: 5px solid; border-right: 1px solid;">kSetDeviceMemoryPropertiesCommand</td>
      <td>
        <code>thread_id</code>
      </td>
      <td>
        <a href="#primitive-u64">u64</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>physical_device_id</code>
      </td>
      <td>
        <a href="#primitive-u64">u64</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>memory_type_count</code>
      </td>
      <td>
        <a href="#primitive-u32">u32</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>memory_heap_count</code>
      </td>
      <td>
        <a href="#primitive-u32">u32</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>memory_types</code>
      </td>
      <td>
        <a href="#complex-type-DeviceMemoryType">DeviceMemoryType[]</a>
      </td>
      <td>
        <code>memory_type_count</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td style="border-bottom: 5px solid">
        <code>memory_heaps</code>
      </td>
      <td style="border-bottom: 5px solid">
        <a href="#complex-type-DeviceMemoryHeap">DeviceMemoryHeap[]</a>
      </td>
      <td style="border-bottom: 5px solid">
        <code>memory_heap_count</code>
      </td>
      <td style="border-bottom: 5px solid"></td>
    </tr>
    <tr>
      <td rowspan="5" style="border-bottom: 5px solid; border-right: 1px solid;">kResizeWindowCommand2</td>
      <td>
        <code>thread_id</code>
      </td>
      <td>
        <a href="#primitive-u64">u64</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>surface_id</code>
      </td>
      <td>
        <a href="#primitive-u64">u64</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>width</code>
      </td>
      <td>
        <a href="#primitive-u32">u32</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>height</code>
      </td>
      <td>
        <a href="#primitive-u32">u32</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td style="border-bottom: 5px solid">
        <code>pre_transform</code>
      </td>
      <td style="border-bottom: 5px solid">
        <a href="#primitive-u32">u32</a>
      </td>
      <td style="border-bottom: 5px solid">
        <code>1</code>
      </td>
      <td style="border-bottom: 5px solid"></td>
    </tr>
    <tr>
      <td rowspan="4" style="border-bottom: 5px solid; border-right: 1px solid;">kSetOpaqueAddressCommand</td>
      <td>
        <code>thread_id</code>
      </td>
      <td>
        <a href="#primitive-u64">u64</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>device_id</code>
      </td>
      <td>
        <a href="#primitive-u64">u64</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>object_id</code>
      </td>
      <td>
        <a href="#primitive-u64">u64</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td style="border-bottom: 5px solid">
        <code>address</code>
      </td>
      <td style="border-bottom: 5px solid">
        <a href="#primitive-u64">u64</a>
      </td>
      <td style="border-bottom: 5px solid">
        <code>1</code>
      </td>
      <td style="border-bottom: 5px solid"></td>
    </tr>
    <tr>
      <td rowspan="5" style="border-bottom: 5px solid; border-right: 1px solid;">kSetRayTracingShaderGroupHandlesCommand</td>
      <td>
        <code>thread_id</code>
      </td>
      <td>
        <a href="#primitive-u64">u64</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>device_id</code>
      </td>
      <td>
        <a href="#primitive-u64">u64</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>pipeline_id</code>
      </td>
      <td>
        <a href="#primitive-u64">u64</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>data_size</code>
      </td>
      <td>
        <a href="#primitive-u64">u64</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr style="background-color: #9b1c1c57;">
      <td style="border-bottom: 5px solid">
        <code>data</code>
      </td>
      <td style="border-bottom: 5px solid">
        <a href="#primitive-u8">u8</a>
      </td>
      <td style="border-bottom: 5px solid">
        <code>data_size</code>
      </td>
      <td style="border-bottom: 5px solid"></td>
    </tr>
    <tr>
      <td rowspan="3" style="border-bottom: 5px solid; border-right: 1px solid;">kCreateHeapAllocationCommand</td>
      <td>
        <code>thread_id</code>
      </td>
      <td>
        <a href="#primitive-u64">u64</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>allocation_id</code>
      </td>
      <td>
        <a href="#primitive-u64">u64</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td style="border-bottom: 5px solid">
        <code>allocation_size</code>
      </td>
      <td style="border-bottom: 5px solid">
        <a href="#primitive-u64">u64</a>
      </td>
      <td style="border-bottom: 5px solid">
        <code>1</code>
      </td>
      <td style="border-bottom: 5px solid"></td>
    </tr>
    <tr>
      <td rowspan="9" style="border-bottom: 5px solid; border-right: 1px solid;">kInitSubresourceCommand</td>
      <td>
        <code>thread_id</code>
      </td>
      <td>
        <a href="#primitive-u64">u64</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>device_id</code>
      </td>
      <td>
        <a href="#primitive-u64">u64</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>resource_id</code>
      </td>
      <td>
        <a href="#primitive-u64">u64</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>subresource</code>
      </td>
      <td>
        <a href="#primitive-u32">u32</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>initial_state</code>
      </td>
      <td>
        <a href="#primitive-u32">u32</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>resource_state</code>
      </td>
      <td>
        <a href="#primitive-u32">u32</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>barrier_flags</code>
      </td>
      <td>
        <a href="#primitive-u32">u32</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>data_size</code>
      </td>
      <td>
        <a href="#primitive-u64">u64</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr style="background-color: #9b1c1c57;">
      <td style="border-bottom: 5px solid">
        <code>data</code>
      </td>
      <td style="border-bottom: 5px solid">
        <a href="#special-compressible_bytes">compressible_bytes</a>
      </td>
      <td style="border-bottom: 5px solid">
        <code>data_size</code>
      </td>
      <td style="border-bottom: 5px solid"></td>
    </tr>
    <tr>
      <td rowspan="2" style="border-bottom: 5px solid; border-right: 1px solid;">kExeFileInfoCommand</td>
      <td>
        <code>thread_id</code>
      </td>
      <td>
        <a href="#primitive-u64">u64</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td style="border-bottom: 5px solid">
        <code>info_record</code>
      </td>
      <td style="border-bottom: 5px solid">
        <a href="#complex-type-FileInfo">FileInfo</a>
      </td>
      <td style="border-bottom: 5px solid">
        <code>1</code>
      </td>
      <td style="border-bottom: 5px solid"></td>
    </tr>
    <tr>
      <td rowspan="11" style="border-bottom: 5px solid; border-right: 1px solid;">kInitDx12AccelerationStructureCommand</td>
      <td>
        <code>thread_id</code>
      </td>
      <td>
        <a href="#primitive-u64">u64</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>dest_acceleration_structure_data</code>
      </td>
      <td>
        <a href="#primitive-u64">u64</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>copy_source_gpu_va</code>
      </td>
      <td>
        <a href="#primitive-u64">u64</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>copy_mode</code>
      </td>
      <td>
        <a href="#primitive-u32">u32</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>inputs_type</code>
      </td>
      <td>
        <a href="#primitive-u32">u32</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>inputs_flags</code>
      </td>
      <td>
        <a href="#primitive-u32">u32</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>inputs_num_instance_descs</code>
      </td>
      <td>
        <a href="#primitive-u32">u32</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>inputs_num_geometry_descs</code>
      </td>
      <td>
        <a href="#primitive-u32">u32</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>inputs_data_size</code>
      </td>
      <td>
        <a href="#primitive-u64">u64</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>geometry_descs</code>
      </td>
      <td>
        <a href="#complex-type-InitDx12AccelerationStructureGeometryDesc">InitDx12AccelerationStructureGeometryDesc[]</a>
      </td>
      <td>
        <code>inputs_num_geometry_descs</code>
      </td>
      <td></td>
    </tr>
    <tr style="background-color: #9b1c1c57;">
      <td style="border-bottom: 5px solid">
        <code>build_inputs_data</code>
      </td>
      <td style="border-bottom: 5px solid">
        <a href="#special-compressible_bytes">compressible_bytes</a>
      </td>
      <td style="border-bottom: 5px solid">
        <code>inputs_data_size</code>
      </td>
      <td style="border-bottom: 5px solid"></td>
    </tr>
    <tr>
      <td rowspan="3" style="border-bottom: 5px solid; border-right: 1px solid;">kFillMemoryResourceValueCommand</td>
      <td>
        <code>thread_id</code>
      </td>
      <td>
        <a href="#primitive-u64">u64</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>resource_value_count</code>
      </td>
      <td>
        <a href="#primitive-u64">u64</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td style="border-bottom: 5px solid">
        <code>data</code>
      </td>
      <td style="border-bottom: 5px solid">
        <a href="#special-compressible_bytes">compressible_bytes</a>
      </td>
      <td style="border-bottom: 5px solid">
        <code>1</code>
      </td>
      <td style="border-bottom: 5px solid"></td>
    </tr>
    <tr>
      <td rowspan="2" style="border-bottom: 5px solid; border-right: 1px solid;">kDxgiAdapterInfoCommand</td>
      <td>
        <code>thread_id</code>
      </td>
      <td>
        <a href="#primitive-u64">u64</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td style="border-bottom: 5px solid">
        <code>adapter_desc</code>
      </td>
      <td style="border-bottom: 5px solid">
        <a href="#complex-type-DxgiAdapterDesc">DxgiAdapterDesc</a>
      </td>
      <td style="border-bottom: 5px solid">
        <code>1</code>
      </td>
      <td style="border-bottom: 5px solid"></td>
    </tr>
    <tr>
      <td rowspan="2" style="border-bottom: 5px solid; border-right: 1px solid;">kDriverInfoCommand</td>
      <td>
        <code>thread_id</code>
      </td>
      <td>
        <a href="#primitive-u64">u64</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td style="border-bottom: 5px solid">
        <code>driver_record</code>
      </td>
      <td style="border-bottom: 5px solid">
        <a href="#primitive-char">char[]</a>
      </td>
      <td style="border-bottom: 5px solid">
        <code>1024</code>
      </td>
      <td style="border-bottom: 5px solid"></td>
    </tr>
    <tr>
      <td rowspan="2" style="border-bottom: 5px solid; border-right: 1px solid;">kDx12RuntimeInfoCommand</td>
      <td>
        <code>thread_id</code>
      </td>
      <td>
        <a href="#primitive-u64">u64</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td style="border-bottom: 5px solid">
        <code>runtime_info</code>
      </td>
      <td style="border-bottom: 5px solid">
        <a href="#complex-type-Dx12RuntimeInfo">Dx12RuntimeInfo</a>
      </td>
      <td style="border-bottom: 5px solid">
        <code>1</code>
      </td>
      <td style="border-bottom: 5px solid"></td>
    </tr>
    <tr>
      <td rowspan="5" style="border-bottom: 5px solid; border-right: 1px solid;">kParentToChildDependency</td>
      <td>
        <code>thread_id</code>
      </td>
      <td>
        <a href="#primitive-u64">u64</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>dependency_type</code>
      </td>
      <td>
        <a href="#enum-ParentToChildDependencyType">ParentToChildDependencyType</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>parent_id</code>
      </td>
      <td>
        <a href="#primitive-u64">u64</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>child_count</code>
      </td>
      <td>
        <a href="#primitive-u32">u32</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td style="border-bottom: 5px solid">
        <code>children_ids</code>
      </td>
      <td style="border-bottom: 5px solid">
        <a href="#primitive-u64">u64[]</a>
      </td>
      <td style="border-bottom: 5px solid">
        <code>child_count</code>
      </td>
      <td style="border-bottom: 5px solid"></td>
    </tr>
    <tr>
      <td rowspan="3" style="border-bottom: 5px solid; border-right: 1px solid;">kSetEnvironmentVariablesCommand</td>
      <td>
        <code>thread_id</code>
      </td>
      <td>
        <a href="#primitive-u64">u64</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>string_length</code>
      </td>
      <td>
        <a href="#primitive-u64">u64</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr style="background-color: #9b1c1c57;">
      <td style="border-bottom: 5px solid">
        <code>env_string</code>
      </td>
      <td style="border-bottom: 5px solid">
        <a href="#primitive-u8">u8</a>
      </td>
      <td style="border-bottom: 5px solid">
        <code>string_length</code>
      </td>
      <td style="border-bottom: 5px solid">A series of null-terminated strings, one after another, ending with a final null terminator. The total length includes all nulls.</td>
    </tr>
    <tr>
      <td rowspan="2" style="border-bottom: 5px solid; border-right: 1px solid;">kViewRelativeLocation</td>
      <td>
        <code>thread_id</code>
      </td>
      <td>
        <a href="#primitive-u64">u64</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td style="border-bottom: 5px solid">
        <code>location</code>
      </td>
      <td style="border-bottom: 5px solid">
        <a href="#complex-type-ViewRelativeLocation">ViewRelativeLocation</a>
      </td>
      <td style="border-bottom: 5px solid">
        <code>1</code>
      </td>
      <td style="border-bottom: 5px solid"></td>
    </tr>
    <tr>
      <td rowspan="5" style="border-bottom: 5px solid; border-right: 1px solid;">kExecuteBlocksFromFile</td>
      <td>
        <code>thread_id</code>
      </td>
      <td>
        <a href="#primitive-u64">u64</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>n_blocks</code>
      </td>
      <td>
        <a href="#primitive-u32">u32</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>offset</code>
      </td>
      <td>
        <a href="#primitive-i64">i64</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>filename_length</code>
      </td>
      <td>
        <a href="#primitive-u32">u32</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr style="background-color: #9b1c1c57;">
      <td style="border-bottom: 5px solid">
        <code>filename</code>
      </td>
      <td style="border-bottom: 5px solid">
        <a href="#primitive-u8">u8</a>
      </td>
      <td style="border-bottom: 5px solid">
        <code>filename_length</code>
      </td>
      <td style="border-bottom: 5px solid"></td>
    </tr>
    <tr>
      <td rowspan="12" style="border-bottom: 5px solid; border-right: 1px solid;">kCreateHardwareBufferCommand</td>
      <td>
        <code>thread_id</code>
      </td>
      <td>
        <a href="#primitive-u64">u64</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>device_id</code>
      </td>
      <td>
        <a href="#primitive-u64">u64</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>memory_id</code>
      </td>
      <td>
        <a href="#primitive-u64">u64</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>buffer_id</code>
      </td>
      <td>
        <a href="#primitive-u64">u64</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>format</code>
      </td>
      <td>
        <a href="#primitive-u32">u32</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>width</code>
      </td>
      <td>
        <a href="#primitive-u32">u32</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>height</code>
      </td>
      <td>
        <a href="#primitive-u32">u32</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>stride</code>
      </td>
      <td>
        <a href="#primitive-u32">u32</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>usage</code>
      </td>
      <td>
        <a href="#primitive-u64">u64</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>layers</code>
      </td>
      <td>
        <a href="#primitive-u32">u32</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>planes</code>
      </td>
      <td>
        <a href="#primitive-u32">u32</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td style="border-bottom: 5px solid">
        <code>plane_info</code>
      </td>
      <td style="border-bottom: 5px solid">
        <a href="#complex-type-HardwareBufferPlaneInfo">HardwareBufferPlaneInfo[]</a>
      </td>
      <td style="border-bottom: 5px solid">
        <code>planes</code>
      </td>
      <td style="border-bottom: 5px solid"></td>
    </tr>
    <tr>
      <td rowspan="6" style="border-bottom: 5px solid; border-right: 1px solid;">kInitializeMetaCommand</td>
      <td>
        <code>thread_id</code>
      </td>
      <td>
        <a href="#primitive-u64">u64</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>capture_id</code>
      </td>
      <td>
        <a href="#primitive-u64">u64</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>block_index</code>
      </td>
      <td>
        <a href="#primitive-u32">u32</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>total_number_of_initializemetacommand</code>
      </td>
      <td>
        <a href="#primitive-u32">u32</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>initialization_parameters_data_size</code>
      </td>
      <td>
        <a href="#primitive-u64">u64</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr style="background-color: #9b1c1c57;">
      <td style="border-bottom: 5px solid">
        <code>data</code>
      </td>
      <td style="border-bottom: 5px solid">
        <a href="#special-compressible_bytes">compressible_bytes</a>
      </td>
      <td style="border-bottom: 5px solid">
        <code>initialization_parameters_data_size</code>
      </td>
      <td style="border-bottom: 5px solid"></td>
    </tr>
    <tr style="background-color: #9b1c1c57;">
      <td rowspan="1" style="border-bottom: 5px solid; border-right: 1px solid;">kVulkanBuildAccelerationStructuresCommand</td>
      <td style="border-bottom: 5px solid">
        <code>parameter_buffer</code>
      </td>
      <td style="border-bottom: 5px solid">
        <a href="#primitive-u8">u8</a>
      </td>
      <td style="border-bottom: 5px solid">
        <code>$remaining</code>
      </td>
      <td style="border-bottom: 5px solid"></td>
    </tr>
    <tr style="background-color: #9b1c1c57;">
      <td rowspan="1" style="border-bottom: 5px solid; border-right: 1px solid;">kVulkanCopyAccelerationStructuresCommand</td>
      <td style="border-bottom: 5px solid">
        <code>parameter_buffer</code>
      </td>
      <td style="border-bottom: 5px solid">
        <a href="#primitive-u8">u8</a>
      </td>
      <td style="border-bottom: 5px solid">
        <code>$remaining</code>
      </td>
      <td style="border-bottom: 5px solid"></td>
    </tr>
    <tr style="background-color: #9b1c1c57;">
      <td rowspan="1" style="border-bottom: 5px solid; border-right: 1px solid;">kVulkanWriteAccelerationStructuresPropertiesCommand</td>
      <td style="border-bottom: 5px solid">
        <code>parameter_buffer</code>
      </td>
      <td style="border-bottom: 5px solid">
        <a href="#primitive-u8">u8</a>
      </td>
      <td style="border-bottom: 5px solid">
        <code>$remaining</code>
      </td>
      <td style="border-bottom: 5px solid"></td>
    </tr>
  </tbody>
</table>



## Enums

<table style="border: 1px solid;">
  <thead>
    <th style="border: 1px solid; text-align: center;">Enum Name</th>
    <th style="border: 1px solid; text-align: center;">C++ Enum</th>
    <th style="border: 1px solid; text-align: center;">Headers</th>
  </thead>
  <tbody>
    <tr>
      <td style="border-left: 1px solid;">
        <a id="enum-BlockType"></a>
        <code>BlockType</code>
      </td>
      <td>format::BlockType</td>
      <td style="border-right: 1px solid">`format/format.h`</td>
    </tr>
    <tr>
      <td style="border-left: 1px solid;">
        <a id="enum-MetaDataType"></a>
        <code>MetaDataType</code>
      </td>
      <td>format::MetaDataType</td>
      <td style="border-right: 1px solid">`format/format.h`</td>
    </tr>
    <tr>
      <td style="border-left: 1px solid;">
        <a id="enum-ApiCallId"></a>
        <code>ApiCallId</code>
      </td>
      <td>format::ApiCallId</td>
      <td style="border-right: 1px solid">`format/api_call_id.h`</td>
    </tr>
    <tr>
      <td style="border-left: 1px solid;">
        <a id="enum-MarkerType"></a>
        <code>MarkerType</code>
      </td>
      <td>format::MarkerType</td>
      <td style="border-right: 1px solid">`format/format.h`</td>
    </tr>
    <tr>
      <td style="border-left: 1px solid;">
        <a id="enum-AnnotationType"></a>
        <code>AnnotationType</code>
      </td>
      <td>format::AnnotationType</td>
      <td style="border-right: 1px solid">`format/format.h`</td>
    </tr>
    <tr>
      <td style="border-left: 1px solid;">
        <a id="enum-ResourceValueType"></a>
        <code>ResourceValueType</code>
      </td>
      <td>format::ResourceValueType</td>
      <td style="border-right: 1px solid">`format/format.h`</td>
    </tr>
    <tr>
      <td style="border-left: 1px solid;">
        <a id="enum-ParentToChildDependencyType"></a>
        <code>ParentToChildDependencyType</code>
      </td>
      <td>format::ParentToChildDependencyType</td>
      <td style="border-right: 1px solid">`format/format.h`</td>
    </tr>
  </tbody>
</table>

## Primitives

<table style="border: 1px solid;">
  <thead>
    <th style="border: 1px solid; text-align: center;">Primitive</th>
    <th style="border: 1px solid; text-align: center;">Size in Bytes</th>
    <th style="border: 1px solid; text-align: center;">Type</th>
  </thead>
  <tbody>
    <tr>
      <td style="border-left: 1px solid;">
        <a id="primitive-u8"></a>
        <code>u8</code>
      </td>
      <td>1</td>
      <td style="border-right: 1px solid">Unsigned Integer</td>
    </tr>
    <tr>
      <td style="border-left: 1px solid;">
        <a id="primitive-u16"></a>
        <code>u16</code>
      </td>
      <td>2</td>
      <td style="border-right: 1px solid">Unsigned Integer</td>
    </tr>
    <tr>
      <td style="border-left: 1px solid;">
        <a id="primitive-u32"></a>
        <code>u32</code>
      </td>
      <td>4</td>
      <td style="border-right: 1px solid">Unsigned Integer</td>
    </tr>
    <tr>
      <td style="border-left: 1px solid;">
        <a id="primitive-u64"></a>
        <code>u64</code>
      </td>
      <td>8</td>
      <td style="border-right: 1px solid">Unsigned Integer</td>
    </tr>
    <tr>
      <td style="border-left: 1px solid;">
        <a id="primitive-i32"></a>
        <code>i32</code>
      </td>
      <td>4</td>
      <td style="border-right: 1px solid">Signed Integer</td>
    </tr>
    <tr>
      <td style="border-left: 1px solid;">
        <a id="primitive-i64"></a>
        <code>i64</code>
      </td>
      <td>8</td>
      <td style="border-right: 1px solid">Signed Integer</td>
    </tr>
    <tr>
      <td style="border-left: 1px solid;">
        <a id="primitive-f32"></a>
        <code>f32</code>
      </td>
      <td>4</td>
      <td style="border-right: 1px solid">Floating Point</td>
    </tr>
    <tr>
      <td style="border-left: 1px solid;">
        <a id="primitive-char"></a>
        <code>char</code>
      </td>
      <td>1</td>
      <td style="border-right: 1px solid">Signed Integer</td>
    </tr>
    <tr>
      <td style="border-left: 1px solid;">
        <a id="primitive-wchar"></a>
        <code>wchar</code>
      </td>
      <td>2</td>
      <td style="border-right: 1px solid">"Wide" Character (for UTF-16/32)</td>
    </tr>
  </tbody>
</table>

## Special Field Kinds

<table style="border: 1px solid;">
  <thead>
    <th style="border: 1px solid; text-align: center;">Kind</th>
    <th style="border: 1px solid; text-align: center;">Definition</th>
  </thead>
  <tbody>
    <tr>
      <td style="border-left: 1px solid;">
        <a id="special-compressible_bytes"></a>
        <code>compressible_bytes</code>
      </td>
      <td style="border-right: 1px solid">A byte buffer that is read differently depending on the block's $compressed flag. CONVENTION: The on-disk source for compressed data is always the entire remainder of the block's payload. Therefore, a field of this kind MUST be the last field defined in any payload and may only appear once.</td>
    </tr>
  </tbody>
</table>

## Payload Structs

<table style="border: 1px solid">
  <thead>
    <tr>
      <th style="border-right: 1px solid; text-align: center; vertical-align: middle;" rowspan="2">Struct Name</th>
      <th colspan="4" style="border: 1px solid; text-align: center; vertical-align: middle;">Fields</th>
    </tr>
    <tr>
      <th style="border-left: 1px solid; text-align: center; vertical-align: middle;">Name</th>
      <th style="text-align: center; vertical-align: middle;">Type</th>
      <th style="text-align: center; vertical-align: middle;">Count</th>
      <th style="text-align: center; vertical-align: middle;">Details</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td rowspan="4" style="border-bottom: 5px solid; border-right: 1px solid;" id="complex-type-FileHeader">FileHeader</td>
      <td>
        <code>fourcc</code>
      </td>
      <td>
        <a href="#primitive-u32">u32</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td>4-character "magic number." Must be 'GFXR' (0x47465852).</td>
    </tr>
    <tr>
      <td>
        <code>major_version</code>
      </td>
      <td>
        <a href="#primitive-u32">u32</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td>Major file version</td>
    </tr>
    <tr>
      <td>
        <code>minor_version</code>
      </td>
      <td>
        <a href="#primitive-u32">u32</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td>Minor file version</td>
    </tr>
    <tr>
      <td style="border-bottom: 5px solid">
        <code>num_options</code>
      </td>
      <td style="border-bottom: 5px solid">
        <a href="#primitive-u32">u32</a>
      </td>
      <td style="border-bottom: 5px solid">
        <code>1</code>
      </td>
      <td style="border-bottom: 5px solid">Number of FileOptionPairs that follow the header. e.g., compression type.</td>
    </tr>
    <tr>
      <td rowspan="2" style="border-bottom: 5px solid; border-right: 1px solid;" id="complex-type-FileOptionPair">FileOptionPair</td>
      <td>
        <code>key</code>
      </td>
      <td>
        <a href="#primitive-u32">u32</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td>Key</td>
    </tr>
    <tr>
      <td style="border-bottom: 5px solid">
        <code>value</code>
      </td>
      <td style="border-bottom: 5px solid">
        <a href="#primitive-u32">u32</a>
      </td>
      <td style="border-bottom: 5px solid">
        <code>1</code>
      </td>
      <td style="border-bottom: 5px solid">Value</td>
    </tr>
    <tr>
      <td rowspan="2" style="border-bottom: 5px solid; border-right: 1px solid;" id="complex-type-BlockHeader">BlockHeader</td>
      <td>
        <code>size</code>
      </td>
      <td>
        <a href="#primitive-u64">u64</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td>Size of the block payload in bytes, excluding the header.</td>
    </tr>
    <tr>
      <td style="border-bottom: 5px solid">
        <code>type</code>
      </td>
      <td style="border-bottom: 5px solid">
        <a href="#enum-BlockType">BlockType</a>
      </td>
      <td style="border-bottom: 5px solid">
        <code>1</code>
      </td>
      <td style="border-bottom: 5px solid">Type of the block. See 'Blocks' section below for details on each block type.</td>
    </tr>
    <tr>
      <td rowspan="9" style="border-bottom: 5px solid; border-right: 1px solid;" id="complex-type-FileInfo">FileInfo</td>
      <td>
        <code>ProductVersion</code>
      </td>
      <td>
        <a href="#primitive-char">char[]</a>
      </td>
      <td>
        <code>256</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>FileVersion</code>
      </td>
      <td>
        <a href="#primitive-char">char[]</a>
      </td>
      <td>
        <code>256</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>AppVersion</code>
      </td>
      <td>
        <a href="#primitive-u32">u32[]</a>
      </td>
      <td>
        <code>4</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>AppName</code>
      </td>
      <td>
        <a href="#primitive-char">char[]</a>
      </td>
      <td>
        <code>256</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>CompanyName</code>
      </td>
      <td>
        <a href="#primitive-char">char[]</a>
      </td>
      <td>
        <code>256</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>FileDescription</code>
      </td>
      <td>
        <a href="#primitive-char">char[]</a>
      </td>
      <td>
        <code>256</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>InternalName</code>
      </td>
      <td>
        <a href="#primitive-char">char[]</a>
      </td>
      <td>
        <code>256</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>OriginalFilename</code>
      </td>
      <td>
        <a href="#primitive-char">char[]</a>
      </td>
      <td>
        <code>256</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td style="border-bottom: 5px solid">
        <code>ProductName</code>
      </td>
      <td style="border-bottom: 5px solid">
        <a href="#primitive-char">char[]</a>
      </td>
      <td style="border-bottom: 5px solid">
        <code>256</code>
      </td>
      <td style="border-bottom: 5px solid"></td>
    </tr>
    <tr>
      <td rowspan="3" style="border-bottom: 5px solid; border-right: 1px solid;" id="complex-type-HardwareBufferPlaneInfo">HardwareBufferPlaneInfo</td>
      <td>
        <code>offset</code>
      </td>
      <td>
        <a href="#primitive-u64">u64</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td>Offset from the start of the memory allocation in bytes.</td>
    </tr>
    <tr>
      <td>
        <code>pixel_stride</code>
      </td>
      <td>
        <a href="#primitive-u32">u32</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td>Number of bytes between adjacent pixels in a row.</td>
    </tr>
    <tr>
      <td style="border-bottom: 5px solid">
        <code>row_pitch</code>
      </td>
      <td style="border-bottom: 5px solid">
        <a href="#primitive-u32">u32</a>
      </td>
      <td style="border-bottom: 5px solid">
        <code>1</code>
      </td>
      <td style="border-bottom: 5px solid">Number of bytes between adjacent rows.</td>
    </tr>
    <tr>
      <td rowspan="8" style="border-bottom: 5px solid; border-right: 1px solid;" id="complex-type-SwapchainImageStateInfo">SwapchainImageStateInfo</td>
      <td>
        <code>image_id</code>
      </td>
      <td>
        <a href="#primitive-u64">u64</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td>HandleId of the swapchain image.</td>
    </tr>
    <tr>
      <td>
        <code>image_index</code>
      </td>
      <td>
        <a href="#primitive-u32">u32</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>image_layout</code>
      </td>
      <td>
        <a href="#primitive-u32">u32</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>acquired</code>
      </td>
      <td>
        <a href="#primitive-u32">u32</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>acquire_device_mask</code>
      </td>
      <td>
        <a href="#primitive-u32">u32</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>acquire_semaphore_id</code>
      </td>
      <td>
        <a href="#primitive-u64">u64</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td>HandleId of the semaphore used for acquisition.</td>
    </tr>
    <tr>
      <td>
        <code>acquire_fence_id</code>
      </td>
      <td>
        <a href="#primitive-u64">u64</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td>HandleId of the fence used for acquisition.</td>
    </tr>
    <tr>
      <td style="border-bottom: 5px solid">
        <code>last_presented_queue_id</code>
      </td>
      <td style="border-bottom: 5px solid">
        <a href="#primitive-u64">u64</a>
      </td>
      <td style="border-bottom: 5px solid">
        <code>1</code>
      </td>
      <td style="border-bottom: 5px solid">HandleId of the last presented queue.</td>
    </tr>
    <tr>
      <td rowspan="2" style="border-bottom: 5px solid; border-right: 1px solid;" id="complex-type-DeviceMemoryType">DeviceMemoryType</td>
      <td>
        <code>property_flags</code>
      </td>
      <td>
        <a href="#primitive-u32">u32</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td>Memory properties (e.g., DEVICE_LOCAL, HOST_VISIBLE).</td>
    </tr>
    <tr>
      <td style="border-bottom: 5px solid">
        <code>heap_index</code>
      </td>
      <td style="border-bottom: 5px solid">
        <a href="#primitive-u32">u32</a>
      </td>
      <td style="border-bottom: 5px solid">
        <code>1</code>
      </td>
      <td style="border-bottom: 5px solid"></td>
    </tr>
    <tr>
      <td rowspan="2" style="border-bottom: 5px solid; border-right: 1px solid;" id="complex-type-DeviceMemoryHeap">DeviceMemoryHeap</td>
      <td>
        <code>size</code>
      </td>
      <td>
        <a href="#primitive-u64">u64</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td>e.g., VkMemoryHeap::size</td>
    </tr>
    <tr>
      <td style="border-bottom: 5px solid">
        <code>flags</code>
      </td>
      <td style="border-bottom: 5px solid">
        <a href="#primitive-u32">u32</a>
      </td>
      <td style="border-bottom: 5px solid">
        <code>1</code>
      </td>
      <td style="border-bottom: 5px solid">e.g., VkMemoryHeap::flags</td>
    </tr>
    <tr>
      <td rowspan="10" style="border-bottom: 5px solid; border-right: 1px solid;" id="complex-type-InitDx12AccelerationStructureGeometryDesc">InitDx12AccelerationStructureGeometryDesc</td>
      <td>
        <code>geometry_type</code>
      </td>
      <td>
        <a href="#primitive-u32">u32</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>geometry_flags</code>
      </td>
      <td>
        <a href="#primitive-u32">u32</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>aabbs_count</code>
      </td>
      <td>
        <a href="#primitive-u64">u64</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>aabbs_stride</code>
      </td>
      <td>
        <a href="#primitive-u64">u64</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>triangles_has_transform</code>
      </td>
      <td>
        <a href="#primitive-u32">u32</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>triangles_index_format</code>
      </td>
      <td>
        <a href="#primitive-u32">u32</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>triangles_vertex_format</code>
      </td>
      <td>
        <a href="#primitive-u32">u32</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>triangles_index_count</code>
      </td>
      <td>
        <a href="#primitive-u32">u32</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>triangles_vertex_count</code>
      </td>
      <td>
        <a href="#primitive-u32">u32</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td style="border-bottom: 5px solid">
        <code>triangles_vertex_stride</code>
      </td>
      <td style="border-bottom: 5px solid">
        <a href="#primitive-u64">u64</a>
      </td>
      <td style="border-bottom: 5px solid">
        <code>1</code>
      </td>
      <td style="border-bottom: 5px solid"></td>
    </tr>
    <tr>
      <td rowspan="11" style="border-bottom: 5px solid; border-right: 1px solid;" id="complex-type-DxgiAdapterDesc">DxgiAdapterDesc</td>
      <td>
        <code>Description</code>
      </td>
      <td>
        <a href="#primitive-wchar">wchar[]</a>
      </td>
      <td>
        <code>128</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>VendorId</code>
      </td>
      <td>
        <a href="#primitive-u32">u32</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>DeviceId</code>
      </td>
      <td>
        <a href="#primitive-u32">u32</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>SubSysId</code>
      </td>
      <td>
        <a href="#primitive-u32">u32</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>Revision</code>
      </td>
      <td>
        <a href="#primitive-u32">u32</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>DedicatedVideoMemory</code>
      </td>
      <td>
        <a href="#primitive-u64">u64</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>DedicatedSystemMemory</code>
      </td>
      <td>
        <a href="#primitive-u64">u64</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>SharedSystemMemory</code>
      </td>
      <td>
        <a href="#primitive-u64">u64</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>LuidLowPart</code>
      </td>
      <td>
        <a href="#primitive-u32">u32</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>LuidHighPart</code>
      </td>
      <td>
        <a href="#primitive-i32">i32</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td style="border-bottom: 5px solid">
        <code>extra_info</code>
      </td>
      <td style="border-bottom: 5px solid">
        <a href="#primitive-u32">u32</a>
      </td>
      <td style="border-bottom: 5px solid">
        <code>1</code>
      </td>
      <td style="border-bottom: 5px solid"></td>
    </tr>
    <tr>
      <td rowspan="2" style="border-bottom: 5px solid; border-right: 1px solid;" id="complex-type-Dx12RuntimeInfo">Dx12RuntimeInfo</td>
      <td>
        <code>version</code>
      </td>
      <td>
        <a href="#primitive-u32">u32[]</a>
      </td>
      <td>
        <code>4</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td style="border-bottom: 5px solid">
        <code>src</code>
      </td>
      <td style="border-bottom: 5px solid">
        <a href="#primitive-char">char[]</a>
      </td>
      <td style="border-bottom: 5px solid">
        <code>256</code>
      </td>
      <td style="border-bottom: 5px solid"></td>
    </tr>
    <tr>
      <td rowspan="10" style="border-bottom: 5px solid; border-right: 1px solid;" id="complex-type-ViewRelativeLocation">ViewRelativeLocation</td>
      <td>
        <code>session_id</code>
      </td>
      <td>
        <a href="#primitive-u64">u64</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>space_id</code>
      </td>
      <td>
        <a href="#primitive-u64">u64</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>flags</code>
      </td>
      <td>
        <a href="#primitive-u64">u64</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>qx</code>
      </td>
      <td>
        <a href="#primitive-f32">f32</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>qy</code>
      </td>
      <td>
        <a href="#primitive-f32">f32</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>qz</code>
      </td>
      <td>
        <a href="#primitive-f32">f32</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>qw</code>
      </td>
      <td>
        <a href="#primitive-f32">f32</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>x</code>
      </td>
      <td>
        <a href="#primitive-f32">f32</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td>
        <code>y</code>
      </td>
      <td>
        <a href="#primitive-f32">f32</a>
      </td>
      <td>
        <code>1</code>
      </td>
      <td></td>
    </tr>
    <tr>
      <td style="border-bottom: 5px solid">
        <code>z</code>
      </td>
      <td style="border-bottom: 5px solid">
        <a href="#primitive-f32">f32</a>
      </td>
      <td style="border-bottom: 5px solid">
        <code>1</code>
      </td>
      <td style="border-bottom: 5px solid"></td>
    </tr>
  </tbody>
</table>
