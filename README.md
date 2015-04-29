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

* I have been able to improve the overal speed of Hg so overall it is **7.5% faster** than the hand-written version.
* Current performance results:
* Fundamental Types: 29%  faster
* Packed-bits:       13%  faster
* Unaligned ints:    48%  faster
* Nested types:      23%  slower
* Overall:           7.5% faster

Machine:
*Intel Core i7-4790L @ 4.00GHz 
*16 GB RAM 
*Windows 8.1 

Benchmark output:
-----------------
`Loading test data:`  
`Hit enter when ready...:`  
`**Running Hg benchmark:**`  
`basic size:      14, count; 38347922`  
`packed size:     7,  count; 76695844`  
`unaligned size:  19, count; 28256363`  
`complex size:    72, count; 7456540`  
`Test completed`  
` `
`**Running memcpy benchmark:**`  
`basic size:      14, count; 38347922`  
`packed size:     7,  count; 76695844`  
`unaligned size:  19, count; 28256363`  
`complex size:    72, count; 7456540 `  
`Test completed                      `  

 Test | Hg | memcpy | diff | percent
 ----------- |:---------- |:--------- |:---------- |:------------
 Basic | 0.533849s | 0.691942s |  0.158093  | **-29.6138%**
 Packed | 0.630563s | 0.713644s |  0.0830816 | **-13.1758%**
 Unaligned | 0.399894s | 0.593238s |  0.193344  | **-48.3489%**
 Complex | 1.0218s | 0.781852s | -0.239947  | **23.4828%**
 Total | 2.5861s | 2.78068s  |  0.194572  | **-7.52373%**

'Loading test data:'  
'Hit enter when ready...:'  
''  
'Running control benchmark:'  
'--------------------------'  
'no_conversion size: 64          count: 8388608'  
'        basic size: 14          count: 38347922'  
'       packed size: 7           count: 76695844'  
'    unaligned size: 19          count: 28256363'  
'      complex size: 86          count: 6242685'  
'        array size: 1024        count: 524288'  
'Test completed'  
''  
''  
'Running Hg benchmark:'  
'--------------------------'  
'no_conversion size: 64          count: 8388608'  
'        basic size: 14          count: 38347922'  
'       packed size: 7           count: 76695844'  
'    unaligned size: 19          count: 28256363'  
'      complex size: 86          count: 6242685'  
'        array size: 1024        count: 524288'  
'Test completed'  
''  
'-------------------------------------------------------------------------'  
'These scenarios are trivial to write by hand,'  
'and are currently outside of Alchemy's capabilities.'  
'Therefore, Alchemy woefully underperforms in these scenarios.'  
''  
'Scenario:     memcpy:           Hg:             diff            percent'  
'------------- ----------        ----------      ----------      ---------'  
'NoConversion: 0.361389  s       0.577049  s     0.215659        -59.6751%'  
''  
''  
'-------------------------------------------------------------------------'  
'diff:    Is time difference calculated as **control** - **Hg**'  
'percent: Value indicates **Hg** performance (+ is better)'  
''  
'Test:         memcpy:           Hg:             diff            percent'  
'------------- ----------        ----------      ----------      ---------'  
'Basic:        0.612162  s       0.495236  s     -0.116926       19.1005%'  
'Packed:       0.691659  s       0.612     s     -0.0796588      11.5171%'  
'Unaligned:    0.571058  s       0.560454  s     -0.0106043      1.85696%'  
'Complex:      0.806906  s       0.776377  s     -0.0305296      3.78353%'  
'Array:        0.567276  s       0.15729   s     -0.409986       72.2728%'  
'Total:        3.24906   s       2.60136   s     -0.647704       19.9351%'  
''
'-------------------------------------------------------------------------'


These are the basic benchmark tests that have been written:

1. A single struct with fundamental type fields.  
2. A single struct with Packed bit fields.  
3. A single struct with fundamental fields that are intentionally placed at unaligned memory positions.  
4. A Nested struct that contains an instance of all of the previous structs. One of the nested structs is created in an   array.

I intend to create a more thorough set of tests. For now these 4 types have helped me identify plenty of hot-spots to improve the performance. Originally I only had a memory model that was dynamically allocated. When I ran the first benchmarks, Hg was 100x slower. After that I added a static memory model that can be used as well. This improved the performance dramatically. I will continue to comb through the Hg implementation and structure to improve its speed. The current performance report is listed below.

* Notes: 
** Some overhead is incurred because all of the fields are zero initialized when an object is created. 
** I am considering adding an option to not initialize the objects for people who are performance concsious. However, I hesitate to do that because it could cause more problems than the performance penalty incurs.  
** Nested structures cause the largest increase in cost. 

-------------

Active and Planned Improvements:

Currently in progress:
 * Cross-compiler support and cross-platform integration with auto-tools. Currently the projects are Visual Studio Solutions.
 * Adding support for Clang.
 * Clean up TODO: tags left in the code. 

Soon to follow:
 * Message converters, to simplify the task of receiving a message and translating it to another format before forwarding it on to the stage of processing.
 * Add the automatic generation of C-linkable functions and structures that internally make use of Alchemy. This will allow Alchemy to be integrated with other languages, such as C, C#, JAVA, FORTRAN and any others capable of importing functions from C libraries.
 
