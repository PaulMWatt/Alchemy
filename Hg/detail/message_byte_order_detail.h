/// @file Hg/detail/message_byte_order_detail.h
/// 
/// Internal details for the implementation of byte-order conversion of messages.
/// 
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef MESSAGE_BYTE_ORDER_DETAIL_H_INCLUDED
#define MESSAGE_BYTE_ORDER_DETAIL_H_INCLUDED

#include <Pb/byte_order.h>

namespace Hg
{

namespace detail
{

//  Forward Declarations ******************************************************
//  ****************************************************************************
template< typename FromMsgT,
          typename ToMsgT
        >
struct ByteOrderConversionFunctor;


//  ****************************************************************************
template< typename MsgT,
          typename ByteOrderT
        >
class Message;

//  ****************************************************************************
template< typename MsgT,
          typename StorageT
        >
class basic_msg;


//  ****************************************************************************
//  Parameterized function to facilitate the conversion of a Hg::Message to 
//  from byte-order A to byte-order B. Note that A and B can be the same type.
// 
//  @param T        [typename] The Hg::Message format definition of the 
//                  message to be converted.
//  @param from     The message object to convert from.
//                            
//  @return         A Hg::Message object using the same format and data type as the 
//                  input buffer will be returned. The data in the buffer will 
//                  be in host byte-order.
//                  
//                  If the input format was already in host byte-order,
//                  no conversion operations will be performed.
// 
template< typename T,
          typename OrderT
        >
Hg::Message < typename T::base_type, OrderT >
  convert_byte_order( T&                                     from,
                           Hg::Message < typename T::base_type, OrderT >&  to)
{
  typedef typename 
    T::format_type         format_type;

  // Initialize a functor to convert the data byte order,
  // then call this operation for each element in the defined message.
  detail::ByteOrderConversionFunctor
    < T,
      Hg::Message < typename T::base_type, OrderT >
    > ftor(from, to);  

  Hg::ForEachType < 0,
                    Hg::length<format_type>::value - 1,
                    format_type
                  > (ftor);

  return ftor.output; 
}

//  ****************************************************************************
//  A functor to assist in the conversion of fundamental types from one byte-order
//  to another. 
// 
//  @tparam T                 [typename] The fundamental type to be converted.
//  @tparam TraitT            [typename] Specifies the type trait of T.
//                            This field acts as a descriminator for selecting
//                            the most appropriate construct to convert byte-order.
//  
template< typename T, 
          typename StorageT,
          typename TraitT
        >
struct ConvertEndianess
{
  void operator()(const T &input,
                        T &output)
  {
    output = EndianSwap(input);
  }
};

//  ****************************************************************************
//  A specialized functor to convert nested types.
// 
//  @tparam T       [typename] The value_type for this specialization
//                  is actually a format_type for the nested structure.
//  
template< typename T,
          typename StorageT
        >
struct ConvertEndianess<T, StorageT, nested_trait>
{
  template <typename NestedValueT>
  void operator()(const NestedValueT &input,
                        NestedValueT &output)
  {
    // Byte-order swapping is a symetric action.
    // The important goal is to define two differing orders to ensure
    // that the byte-orders are swapped.
    typedef Hg::LittleEndian                      from_order;
    typedef Hg::BigEndian                         to_order;
    typedef typename 
      Hg::basic_msg<T, StorageT>::little_t        from_type;
    typedef typename 
      Hg::basic_msg<T, StorageT>::big_t           to_type;

    // Construct a shallow message wrapper around the nested data.
    from_type  from(input);
    to_type    to;

    // Pass this message to be byte-order swapped.
    output = convert_byte_order<from_type, 
                                to_order>(from, to).values();
  }
};

//  ****************************************************************************
//  A specialized functor to convert array types.
// 
//  @tparam T       [typename] The value_type for this specialization.
//  
template< typename T,
          typename StorageT
        >
struct ConvertEndianess<T, StorageT, array_trait>
{
  template <typename ArrayValueT>
  void operator()(const ArrayValueT &input,
                        ArrayValueT &output)
  {
    // Get the trait for the value_type managed by the array.
    typedef typename
      ArrayValueT::value_type                     value_type;

    typedef typename
      DeduceTypeTrait<value_type>::type           type_trait;

    // Convert with the byte-order conversion functors to detect and handle
    // any nested array items, or arrays of arrays etc...
    ConvertEndianess< value_type, 
                      StorageT,
                      type_trait
                    > swap_order;
    // Perform a conversion on every item in the array.
    for (size_t index = 0; index < input.size(); ++index)
    {
      swap_order(input[index], output[index]);
    }
  }
};

//  ****************************************************************************
//  A specialized functor to convert vector types.
// 
//  @tparam T       [typename] The value_type for this specialization.
//  
template< typename T,
          typename StorageT
        >
struct ConvertEndianess<T, StorageT, vector_trait>
{
  template <typename VectorValueT>
  void operator()(const VectorValueT &input,
                        VectorValueT &output)
  {
    // Get the trait for the value_type managed by the array.
    typedef typename
      VectorValueT::value_type                    value_type;

    typedef typename
      DeduceTypeTrait<value_type>::type           type_trait;

    // Convert with the byte-order conversion functors to detect and handle
    // any nested array items, or arrays of arrays etc...
    ConvertEndianess< value_type,
                      StorageT,
                      type_trait
                    > swap_order;
    // Allocate space for the output vector.
    output.resize(input.size());

    // Perform a conversion on every item in the vector.
    for (size_t index = 0; index < input.size(); ++index)
    {
      swap_order(input[index], output[index]);
    }
  }
};

//  ****************************************************************************
//  ****************************************************************************
//  A functor to assist in the conversion of a messages data-fields from 
//  network byte-order to host byte-order.
// 
//  @param FromMsgT       [typename] The input message type.
//  @param ToMsgT         [typename] The output message type.
//  
template< typename FromMsgT,
          typename ToMsgT
        >
struct ByteOrderConversionFunctor
{
  //  Typedefs *****************************************************************
  typedef FromMsgT                  from_message_type;
  typedef ToMsgT                    to_message_type;
  typedef typename
    from_message_type::message_type     message_type;
  typedef typename
    message_type::format_type           format_type;
  typedef typename
    from_message_type::storage_type     storage_type;

  //  Data Members *************************************************************
  from_message_type&       input;
  to_message_type&         output;

  //  **************************************************************************
  //  Value constructor that initializes the input message to be converted.
  // 
  //  @param rhs      The basic_msg object that contains the input data.
  // 
  explicit
    ByteOrderConversionFunctor(from_message_type& from,
                                     to_message_type&   to)
    : input(from)
    , output(to)
  { }

  //  **************************************************************************
  //  Parameterized function operator
  // 
  //  This function provides the ability for every type of data field to be
  //  converted by this functor.
  //  
  //  @tparam size_t          Parameterized value that specifies the index
  //                          of the data field to be converted.
  //  @tparam value_type      [typename] The type of the data element T.
  //  @param unnamed          An unused variable to disambiguate the appropriate
  //                          specialization function for the compiler to select.
  //  
  template <size_t   Idx,
            typename value_t>
  void operator()(const value_t*)
  {
    typedef typename
      Hg::detail::DeduceProxyType < Idx,
                                    format_type
                                  >::type                     proxy_type;
    typedef typename
      proxy_type::value_type                                  value_type;
                                      
    // The context for which the const input parameter is
    // being used here does not change the value.
    // However, a non-const version of get() causes conflicts.
    // Therefore, casting away const is the safest and cleanest solution.
    from_message_type &mutable_input = const_cast<from_message_type &>(input);

    value_type& from_value = mutable_input.template FieldAt<Idx>().get();

    // Create an instance of a selection template that will choose between
    // nested processing, and value conversion.
    ConvertEndianess< value_type,
                      storage_type,
                      typename DeduceTypeTrait<value_type>::type
                    > swap_order;
    // Swap directly into the value storage for the conversion output.
    swap_order( from_value, 
                output.template FieldAt<Idx>().get());
  }
};


//  ****************************************************************************
//  ****************************************************************************
//  A no-op functor specialization to handle Message to Message conversions 
//  of the same byte-order.
// 
//  @param MsgT       [typename] The input/output message type.
//                        These types are the same, and therefore will not 
//                        trigger any byte-order swap operations.
//  
template< typename T >
struct ByteOrderConversionFunctor <T, T>
{ 
  //  Typedefs *****************************************************************
  typedef T                      from_message_type;
  typedef T                      to_message_type;

  //  Data Members *************************************************************
  const from_message_type &input;
  to_message_type&         output;

  //  **************************************************************************
  /// Value constructor that initializes the input message to be converted.
  ///
  /// @param rhs      The basic_msg object that contains the input data.
  /// 
  explicit
    ByteOrderConversionFunctor(const from_message_type& from,
                                     to_message_type&   to)
    : input(from)
    , output(to)
  { }

  //  **************************************************************************
  /// Parameterized function operator
  ///
  /// This function provides the ability for every type of data field to be
  /// converted by this functor.
  /// 
  /// @param size_t           Parameterized value that specifies the index
  ///                         of the data field to be converted.
  /// @param value_type       [typename] The type of the data element T.
  /// @param unnamed          An unused variable to disambiguate the appropriate
  ///                         specialization function for the compiler to select.
  /// 
  template <size_t   Idx,
            typename value_t>
  void operator()(const value_t*)
  { 
    // The context for which the const input parameter is
    // being used here does not change the value.
    // However, a non-const version of get() causes conflicts.
    // Therefore, casting away const is the safest and cleanest solution.
    from_message_type &mutable_input = const_cast<from_message_type &>(input);
    // Simply copy the input value to the output value.
    output.template FieldAt<Idx>().set( 
      mutable_input.template FieldAt<Idx>().get() 
    );
  }
};

} // namespace detail

} // namespace Hg

#endif
