Network Alchemy {#mainpage}
========================================================
A message and structured data processing framework. 

Alchemy is a message and structured data processing framework. 
This framework provides the ability to define structured message
formats, which can be used portably across platforms. 
These structured definitions will facilitate the population of the data
in the memoery buffers for inter-process communication, file and network
transfer as well as direct memory access mapping.

Byte-alignment processing is completely transparent to application level
users. Conversion utilities are automatically generated for conversion
between host, network, big and little-endian formats for transport developers. 

Alchemy is portable across different processor types and platforms. 
Word alignment and memory access issues are also handled transparently
by the framework. Users interface with Hg message structures in the same way structures are accessed. Nested structures are supported.

Message structure definitions are created with the list of MACROs below.
Refer to the appropriate MACROs documentation for details on correct
usage:

  - HG_BEGIN_FORMAT(TYPE_LIST)
  - HG_MSG_FIELD(TYPE,PARAM)
  - HG_END_FORMAT

Hg provides a portable bit-field interface that works by generating the
appropriate shift and mask operations for each field. Use these MACROS
to define a set of bit-fields that are packed into a user-specified
integral type.
Hg currently is written to allow up to 32 bit-fields in a single parameter.
  - HG_BEGIN_BIT_SET(TYPE,BITSET)
  - HG_END_BIT_SET
  - HG_BIT_FIELD(INDEX,COUNT,PARAM)

