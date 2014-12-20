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

All commenting is done using doxygen.

Mercury (Hg), Messenger of the Gods
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
  - HG_END_FORMAT(TYPE_LIST)

Hg provides a portable bit-field interface that works by generating the
appropriate shift and mask operations for each field. This provides the 
convenience of using C/C++ bit-field language feature, but can still
create a predictable bit-sequence in a packed byte buffer.

Use these MACROS to define a set of bit-fields that are packed 
into a user-specified integral type.

Hg currently is written to allow up to 32 bit-fields in a single parameter.

  - HG_BEGIN_PACKED(TYPE,BITSET)
  -   HG_BIT_FIELD(INDEX, NAME, COUNT)
  - HG_END_PACKED

-------------

Here is a short example of a Hg message definition and how it can be used:

`// Typelist defines the format`  
`typedef Typelist`  
`<`  
  `uint32_t,`  
  `uint32_t,`  
  `std::array<char, 128>`  
`> AppError;`  
  
`// Message definition specifies the TypeList format, and associates a name with each field.`  
`HG_BEGIN_FORMAT(AppError)`  
  `HG_DATUM(uint32_t,id)`  
  `HG_DATUM(uint32_t,code)`  
  `HG_ARRAY(char,128,desc)`  
`HG_END_FORMAT(AppError)`  
  
`// Typedefs such as these are recommended to simplify the usage.`  
`// These typedefs create message objects that associate`  
`// a Hg format, with a platform byte-order.`  
`// The message object also provides memory management options.`  
`typedef Hg::Message<AppError_HgFormat, Hg::HostByteOrder>     AppErrorMsg;`  
`typedef Hg::Message<AppError_HgFormat, Hg::NetByteOrder>      AppErrorMsgNet;`  
  
`// Now messages can be created, populated, copied, and converted between byte-order.`  
`AppErrorMsg msg;`  
`msg.id   = 1;`  
`msg.code = GetError();`  
`strncpy(msg.desc, GetErrorDesc(), sizeof(msg.desc));`  
  
`// Convert to network byte-order`  
`AppErrorMsgNet msgNet = Hg::to_network(msg);`  
  
`// The fields id and code will have been converted if this is`   
`// a little endian system, otherwise no change will have occured.`  
`// Assuming there is a socket open and ready to be written to,`  
`// the network instance of the message will provide the data.`  
`send(sock, msgNet.data(), msgNet.size(), 0);`

-------------

Hg provides the convenient interface for users to convert data values into a data buffer. 

Hg is a C++ template library, it does not produce any module on its own. 

Alchemy does not provide any transport mechanism. This currently is not a priority for this library because there are plenty of libraries that already exist to manage data transfer between two nodes. I intend to create adapters that are compatible with common serialization and transport interfaces like Boost::Serialize and Boost::Asio. 

I envision users of the library to be able to use message objects defined for host-byte order, and the transport adapters will decide if the message byte-order needs to be adjusted. For example, if the transport adapter is a socket, the adapter will convert to network-byte order. However, if the transport is a named-pipe on the same system, it will not perform any byte-order adjustments.

If you know of other transport libraries and would like to see an Hg adapter to that library, please create a new issue request.

-------------
Benchmark performance:

I have started creating benchmarks to measure Hg's performance. The benchmarks compare the Hg implementation to a hand-written struct, using memcpy and the network byte-order conversion functions. 

These are the basic benchmark tests that have been written:

1. A single struct with fundamental type fields.  
2. A single struct with Packed bit fields.  
3. A single struct with fundamental fields that are intentionally placed at unaligned memory positions.  
4. A Nested struct that contains an instance of all of the previous structs. One of the nested structs is created in an   array.

I intend to create a more thorough set of tests. For now these 4 types have helped me identify plenty of hot-spots to improve the performance. Originally I only had a memory model that was dynamically allocated. When I ran the first benchmarks, Hg was 100x slower. After that I added a static memory model that can be used as well. This improved the performance dramatically. I will continue to comb through the Hg implementation and structure to improve its speed. The current performance report is listed below.

- I have been able to improve the overal speed of Hg so it only incurs a ~15% overhead.
- The fundamental types produce code that runs at the same speed.
- The packed-bit fields have been completely reworked. They are now smaller, and for the benchmarks they produce faster code.
-- Some overhead is incurred because all of the fields are zero initialized when an object is created.
-- I am considering adding an option to not initialize the objects for people who are performance concsious. However, I hesitate to do that because it could cause more problems than the performance penalty incurs. 
- Nested structures cause the largest increase in cost.
-- I have tracked down many of the causes to be unnecessary copies of the objects. I will continue to eliminate these as I find them.  

     History: Hg incurs ~30% overhead (slower) compared to the hand-written version.
     History: In some cases Hg produces faster code, ~10%. This was the fundamental field test.
     History: Packed bit fields cause the largest increase in cost.

-------------

Active and Planned Improvements:

Currently in progress:
 * Cross-compiler support and cross-platform integration with auto-tools. Currently the projects are Visual Studio Solutions.
 * Adding support for Clang.
 * Clean up TODO: tags left in the code. Place an official exception handling mechanism in place that is disabled by default.

Soon to follow:
 * Sample applications to demonstrate it's usage.
 * Message converters, to simplify the task of receiving a message and translating it to another format before forwarding it on to the stage of processing.
 * Generate a Wireshark dissector from the Hg definition.
 
