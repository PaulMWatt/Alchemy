Benchmarks
========================================================
Optimizations continue to improve the speed of Alchemy each week. This is a summary of the current benchmark results. The details are further below:

Test | % Faster
----------- |:------------
Basic: |  **20.5059%**
Packed: | **13.9461%**
Unaligned: | **1.81528%**
Complex: | **4.25552%**
Array: | **73.3624%**
Total: | **21.0723%**

Arrays appear to out-perform the basic hand-written equivalent by a considerable margin.

Network Alchemy
========================================================
A portable framework to robustly process network messages and structured data. This library can also be used for serialization tasks and provides **compile-time reflection** for Hg-defined structures. 

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
* An opaque view type exists that can be mapped against any sequence of
bytes for temporary access. This allows the object to interact with a 
packed structure at a byte-level, without making copies or taking ownership.

Message structure definitions are created with the list of MACROs below.
Refer to the appropriate MACROs documentation for details on correct
usage:

  HG_BEGIN_FORMAT(TYPE_LIST, ...)
  -   HG_DATUM(TYPE,NAME)
  -   HG_ARRAY(TYPE,COUNT,NAME)
  -   HG_DYNAMIC(TYPE,COUNT,NAME)
  -   HG_ALLOCATOR(TYPE,ALLOCATOR,COUNT,NAME)

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

`// Message definition specifies the TypeList format, and associates a name with each field.`  
`HG_BEGIN_FORMAT(AppError,`  
  `HG_DATUM(uint32_t,id)`  
  `HG_DATUM(uint32_t,code),`  
  `HG_ARRAY(char,128,desc)`  
`)`  
  
`// Now messages can be created, populated, copied, and converted between byte-order.`  
`AppError::host_t msg;`  
`msg.id   = 1;`  
`msg.code = GetError();`  
`strncpy(msg.desc, GetErrorDesc(), sizeof(msg.desc));`  
  
`// Convert to network byte-order`  
`AppError::net_t msgNet = Hg::to_network(msg);`  
  
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

Machine:
*Intel Core i7-4790L @ 4.00GHz 
*16 GB RAM 
*Windows 8.1 

These benchmarks were compiled by Visual Studio 2013 with these compiler settings:  
*Maximixe Speed: /O2  
*Enable Intrinsic (Yes): /Oi  
*Favor Speed: /Ot  
*Omit Frame Pointers (Yes): /Oy
*Whole Program Optimization (Yes): /GL  
  
Omitting the frame pointers gave the largest boost in performance. Most probably due to the recursive implementation for many of the algorithms that process the Hg messages.

Benchmark output:
-----------------
Loading test data:  
Hit enter when ready...:  
   
Test | Msg Size | Cycles 
-------------- |:---------- |:---------
no_conversion  | 64 | 8388608  
        basic  | 14 | 38347922  
       packed  | 7 | 76695844  
    unaligned  | 19 | 28256363  
      complex  | 86 | 6242685  
        array  | 1024 | 524288  
  
Running control benchmark:  
Test completed  
  
Running Hg benchmark:
Test completed  

diff:    Is time difference calculated as **control** - **Hg**  
percent: Value indicates **Hg** performance (+ is better)  
    
Test | control | Hg | diff | percent
----------- |:---------- |:--------- |:---------- |:------------
Basic: |  0.620346  s | 0.493183  s | -0.127208 | **20.5059%**
Packed: | 0.710566  s | 0.61147     s | -0.0990963 | **13.9461%**
Unaligned: | 0.577596  s | 0.567111  s | -0.010485 | **1.81528%**
Complex: | 0.813253  s | 0.778645  s | -0.0346081 | **4.25552%**
Array: | 0.577873  s | 0.153931   s | -0.423941 | **73.3624%**
Total: | 3.29963  s | 2.60429   s | -0.695338 | **31.0732%**

These scenarios are trivial to write by hand,  
and are currently outside of Alchemy's capabilities.  
Therefore, Alchemy woefully underperforms in these scenarios.  
  
Scenario | control | Hg | diff | percent
----------- |:---------- |:--------- |:---------- |:------------
NoConversion: |  0.380360  s | 0.509006  s | 0.128643 | **-33.8212%**
  
These are the basic benchmark tests that have been written:

1. A single struct with fundamental type fields.  
2. A single struct with Packed bit fields.  
3. A single struct with fundamental fields that are intentionally placed at unaligned memory positions.  
4. A Nested struct that contains an instance of all of the previous structs. One of the nested structs is created in an array. 
5. An array of 256 32-bit integers
6. A structure that does not perform byte-order conversion, but does read, copy, then write data.

**Previous Results**
* I have been able to improve the overal speed of Hg so overall it is **7.5% faster** than the hand-written version.
* Current performance results:
* Fundamental Types: 29%  faster
* Packed-bits:       13%  faster
* Unaligned ints:    48%  faster
* Nested types:      23%  slower
* Overall:           7.5% faster

**Additional tests will be added as the existing implementation is refined.

-------------

Active and Planned Improvements:

Currently in progress:
 * Nearly complete with development for Carbon (C). This is an auxiallary library that will allow you to generate a C-linkable library of your Hg definitions to import into any type of environment that is capable of loading and linking to C-based DLLS.
 * Cross-compiler support and cross-platform integration with auto-tools. Currently the projects are Visual Studio Solutions.
 * Adding support for Clang.
 * Clean up TODO: tags left in the code. 

Soon to follow:
 * Message converters, to simplify the task of receiving a message and translating it to another format before forwarding it on to the stage of processing.
 
