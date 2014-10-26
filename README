Network Alchemy
========================================================
A portable framework to robustly process network messages and structured data. 

Alchemy is portable across different processor types and platforms. 
There is currently only one tool in the Alchemy framework, Hg (Mercury).

Currently Alchemy is based on template library development with
the same methodologies that are used to develop the Standard C++ Library.
Therefore the project only includes header files.

Alchemy requires a C++98 compiler with the TR1 extensions.
Where possible C++11 and C++14 constructs will be utilized.
However, the goal is to allow the library to continue to function
in the absence of these newer compilers and features, with the
potential loss of convenience or performance. 


Mercury, Messenger of the Gods
==============================

Hg is a message and structured data processing framework that
provides the ability to define portable structured message
formats. Hg creates ABI consistent definitions that are compatible
to the bit-level. These structured definitions will facilitate the 
population of the data in the memory buffers for inter-process communication, 
file and network transfer, and even direct memory access mapping.

* Byte-alignment processing is completely transparent to application level
users. 
* Byte-order conversion utilities are automatically generated for 
proper conversion between host, network, big and little-endian 
byte formats for transport developers. 
* Word alignment and memory access issues are also handled transparently
by the framework. 
* A natural interface syntax is created for the users of Hg messages
structures in the same way structures are accessed. 
* Nested structures are supported.
* Sequences of elements both fixed-size (arrays) and dynamically-sized (vectors)
are supported.

Message structure definitions are created with the list of MACROs below.
Refer to the appropriate MACROs documentation for details on correct
usage:

  - HG_BEGIN_FORMAT(TYPE_LIST)
  -   HG_DATUM(TYPE,NAME)
  -   HG_ARRAY(TYPE,COUNT,NAME)
  -   HG_DYNAMIC(TYPE,COUNT,NAME)
  -   HG_ALLOCATOR(TYPE,ALLOCATOR,COUNT,NAME)
  - HG_END_FORMAT

Hg provides a portable bit-field interface that works by generating the
appropriate shift and mask operations for each field. This provides the 
convenience of using C/C++ bit-field language feature, but can still
create a predictable bit-sequence in a packed byte buffer.

Use these MACROS to define a set of bit-fields that are packed 
into a user-specified integral type.

Hg currently is written to allow up to 32 bit-fields in a single parameter.

  - HG_BEGIN_BIT_SET(TYPE,BITSET)
  -   HG_BIT_FIELD(INDEX, NAME, COUNT)
  - HG_END_BIT_SET


Commenting is done using doxygen.

Additional utilities will be added to Network Alchemy once Hg's robustness
has been improved to develop reliable applications.


Soon to follow:
 * Cross-compiler support and cross-platform integration
 * Sample applications to demonstrate it's usage.
 * Performance Benchmarks
 
