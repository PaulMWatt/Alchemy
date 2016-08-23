Bi (Bismuth) Big-Integer
========================================================
I have started work on a Big-Integer library for Alchemy. This will be useful for integer calculations for number theory. Eventually, I will secure it for use with cryptography, which I plan to implement a few convenience functions to simplify encryption, hashing and other related activities with message passing. 

Bismuth (Bi) is a Big-Integer library to handle operations that require numbers greater than the native processor can support. The primary goals of Bismuth are ease-of-use and security. A wide variety of operations from Number Theory are implemented in Bismuth, including modular arithmetic and discrete logarithms. The primary goal for this library is to become a building block to build other robust applications, such as cryptosystems. It is also written using C++ 11 features with clarity of implementation and simplicity to make security more realistic.


Benchmarks
========================================================
The addition of move semantics to the Hg constructs now bring the speed of Alchemy to 40% faster than the hand written construct, with a significant increase for nested data structures:

Test | % Faster
----------- |:------------
Basic: |  **41.37%**
Packed: | **14.05%**
Unaligned: | **47.74%**
Complex: | **25.54%**
Array: | **73.23%**
Total: | **39.98%**

Alchemy and Modern C++ Features
========================================================
Alchemy is now implemented with Modern C++. I will keep a branch open called "Classic C++" that only requires C++98 and TR1 features.   

I will fix bugs on the classic branch.  
With the exception of Optional fields and Union types, I do not plan on developing additional features for this branch.

Network Alchemy
========================================================
A portable framework to robustly process network messages and structured data. This library can also be used for serialization tasks and provides **compile-time reflection** for Hg-defined structures. 

Alchemy is portable across different processor types and platforms. 
There is currently only one tool in the Alchemy framework, Hg (Mercury).

Currently Alchemy is based on template library development with
the same methodologies that are used to develop the Standard C++ Library.
Therefore the project only includes header files.

Alchemy requires a Modern C++98 compiler (C++11 and C++14), although a legacy version for Classic C++ with the TR1 extensions is available. This version supports fundamentals, nested, packed, arrays, vectors and message views. All new development is done exclusively on the modern branch and bug fixes on both branches.

All commenting is done using doxygen.

Carbon (C), C-linkable API generation 
==============================

The preprocessor has been utilized to generate definitions that are compatible with C. A Mercury library can now be generated and configured to generate Carbon definitions as well. All of the power and speed of the Hg messages will be compiled into a library that exports C-linkable interfaces, as well as C-style structures to access the data.

This library will allow any language that is capable of importing a C-library to take advantage of Hg message serialization support. More details will soon follow regarding documentation and usage examples.


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
* Optional field members that are not guaranteed to be present when a message is received.  


Message structure definitions are created with the list of MACROs below.
Refer to the appropriate MACROs documentation for details on correct
usage:

  ALCHEMY_BEGIN_FORMAT(TYPE_LIST, ...)
  -   ALCHEMY_DATUM(TYPE,NAME)
  -   ALCHEMY_ARRAY(TYPE,COUNT,NAME)
  -   ALCHEMY_ALLOC(TYPE,COUNT,NAME)
  -   ALCHEMY_ALLOC_EX(TYPE,ALLOCATOR,COUNT,NAME)
  -   ALCHEMY_DATUM_OPT(TYPE,EXISTS,NAME)
  -   ALCHEMY_ARRAY_OPT(TYPE,COUNT,EXISTS,NAME)
  -   ALCHEMY_ALLOC_OPT(TYPE,COUNT,EXISTS,NAME)
  -   ALCHEMY_ALLOC_EX_OPT(TYPE,ALLOCATOR,COUNT,EXISTS,NAME)

Hg provides a portable bit-field interface that works by generating the
appropriate shift and mask operations for each field. This provides the 
convenience of using C/C++ bit-field language feature, but can still
create a predictable bit-sequence in a packed byte buffer.

Use these MACROS to define a set of bit-fields that are packed 
into a user-specified integral type.

Hg currently is written to allow up to 32 bit-fields in a single parameter.

  - ALCHEMY_BEGIN_PACKED(TYPE,BITSET, ...)
  -   ALCHEMY_BIT_FIELD(INDEX, NAME, COUNT)

-------------

Here is a short example of a Hg message definition and how it can be used:

`#include <Alchemy.h>`  
`// Message definition specifies the TypeList format, and associates a name with each field.`  
`ALCHEMY_BEGIN_FORMAT(AppError,`  
  `ALCHEMY_DATUM(uint32_t,id)`  
  `ALCHEMY_DATUM(uint32_t,code),`  
  `ALCHEMY_ARRAY(char,128,desc)`  
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

Here is the sample example used with C and Carbon rather than C++:

`// Inclusion of the carbon header triggers the generation of the Carbon definitions.`  
`#include <Carbon.h>`  
`// Same message definitions as before.`  
`ALCHEMY_BEGIN_FORMAT(AppError,`  
  `ALCHEMY_DATUM(uint32_t,id)`  
  `ALCHEMY_DATUM(uint32_t,code),`  
  `ALCHEMY_ARRAY(char,128,desc)`  
`)`  
  
`// An enumerated value that identifies the `  
`// type of message to be created is generated.`  
`Hg_msg_t *p_msg = Hg_create(k_AppError);`  
`AppError *msg = (AppError*)p_msg;`  
`msg->id   = 1;`  
`msg->code = GetError();`  
`strncpy(msg->desc, GetErrorDesc(), sizeof(msg->desc));`  
  
`// Convert to network byte-order`  
`// AppError::net_t msgNet = Hg::to_network(msg);`  
`// Carbon messages are converted in-place.`  
`Hg_to_network(p_msg);`  
  
`// The environment that uses the carbon library is reposible`    
`// for managing memory to serialize the messages.`  
`size_t len = Hg_size(p_msg);`  
`unsigned char *p_buffer = malloc(len);`  
`Hg_pack(p_msg, p_buffer, len)`  
``  
`// Now the data can be sent in network order`  
`send(sock, p_buffer, len, 0);`  
``  
`// Cleanup resources.`  
`free(p_buffer);`  
`Hg_destroy(p_msg);`

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
Basic: |  0.4133  s | 0.2423  s | -0.1710 | **41.37%**
Packed: | 0.3959  s | 0.3403     s | -0.0556 | **14.05%**
Unaligned: | 0.4391  s | 0.2295  s | -0.2096 | **47.74%**
Complex: | 0.7485  s | 0.5573  s | -0.1912 | **25.54%**
Array: | 0.5141  s | 0.1376   s | -0.3765 | **73.23%**
Total: | 2.5109  s | 1.5071   s | -1.0039 | **39.98%**

These are the basic benchmark tests that have been written:

1. A single struct with fundamental type fields.  
2. A single struct with Packed bit fields.  
3. A single struct with fundamental fields that are intentionally placed at unaligned memory positions.  
4. A Nested struct that contains an instance of all of the previous structs. One of the nested structs is created in an array. 
5. An array of 256 32-bit integers
6. A structure that does not perform byte-order conversion, but does read, copy, then write data.


