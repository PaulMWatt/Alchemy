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
template< typename FromMessageT,
          typename ToMessageT
        >
struct ByteOrderConversionFunctor;


//  ****************************************************************************
template< typename MessageT,
          typename ByteOrderT,
          typename StorageT
        >
class Message;


//  ****************************************************************************
/// Parameterized function to facilitate the conversion of a Hg::Message to 
/// from byte-order A to byte-order B. Note that A and B can be the same type.
///
/// @param T        [typename] The Hg::Message format definition of the 
///                 message to be converted.
/// @param from     The message object to convert from.
///                           
/// @return         A Hg::Message object using the same format and data type as the 
///                 input buffer will be returned. The data in the buffer will 
///                 be in host byte-order.
///                 
///                 If the input format was already in host byte-order,
///                 no conversion operations will be performed.
///
template< typename MessageT,
          typename FromT,
          typename StorageT,
          typename ToT
        >
Hg::Message<MessageT, ToT, StorageT>
  convert_byte_order(const Hg::Message<MessageT, FromT, StorageT>& from)
{
  typedef typename 
    MessageT::format_type                         format_type;
  // Initialize a functor to convert data to network byte order,
  // then call this operation for each element in the defined message.
  detail::ByteOrderConversionFunctor< Hg::Message< MessageT, FromT, StorageT>,
                                      Hg::Message< MessageT, ToT, StorageT>  >  ftor(from);  
  Hg::ForEachType < 0,
                    Hg::length<format_type>::value - 1,
                    format_type
                  > (ftor);

  return ftor.output; 
}

//  ****************************************************************************
/// A functor to assist in the conversion of fundamental types from one byte-order
/// to another. 
///
/// @tparam T                 [typename] The fundamental type to be converted.
/// @tparam TraitT            [typename] Specifies the type trait of T.
///                           This field acts as a descriminator for selecting
///                           the most appropriate construct to convert byte-order.
/// 
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
/// A specialized functor to convert nested types.
///
/// @tparam T       [typename] The value_type for this specialization
///                 is actually a format_type for the nested structure.
/// 
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
    typedef Hg::NetByteOrder    from_order;
    typedef Hg::HostByteOrder   to_order;

    // Construct a shallow message wrapper around the nested data.
    Hg::Message<T, from_order, StorageT>  from;
    from = input;

    // Pass this message to be byte-order swapped.
    output = convert_byte_order<T, from_order, StorageT, to_order>(from).values();
  }
};

//  ****************************************************************************
/// A specialized functor to convert array types.
///
/// @tparam T       [typename] The value_type for this specialization.
/// 
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
/// A specialized functor to convert vector types.
///
/// @tparam T       [typename] The value_type for this specialization.
/// 
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
/// A functor to assist in the conversion of a messages data-fields from 
/// network byte-order to host byte-order.
///
/// @param FromMessageT       [typename] The input message type.
/// @param ToMessageT         [typename] The output message type.
/// 
template< typename FromMessageT,
          typename ToMessageT
        >
struct ByteOrderConversionFunctor
{
  //  Typedefs *****************************************************************
  typedef FromMessageT                  from_message_type;
  typedef ToMessageT                    to_message_type;
  typedef typename
    from_message_type::message_type     message_type;
  typedef typename
    message_type::format_type           format_type;
  typedef typename
    from_message_type::storage_type     storage_type;

  //  Data Members *************************************************************
  from_message_type input;
  to_message_type   output;

  //  **************************************************************************
  /// Value constructor that initializes the input message to be converted.
  ///
  /// @param rhs      The Message object that contains the input data.
  ///
  explicit
    ByteOrderConversionFunctor(const from_message_type& rhs)
    : input(rhs)
  { }

  //  **************************************************************************
  /// Parameterized function operator
  ///
  /// This function provides the ability for every type of data field to be
  /// converted by this functor.
  /// 
  /// @paramT size_t          Parameterized value that specifies the index
  ///                         of the data field to be converted.
  /// @paramT value_type      [typename] The type of the data element T.
  /// @param unnamed          An unused variable to disambiguate the appropriate
  ///                         specialization function for the compiler to select.
  /// 
  template <size_t   Idx,
            typename value_t>
  void operator()(const value_t&)
  {
    typedef typename
      Hg::detail::DeduceProxyType < Idx,
                                    format_type
                                  >::type                     proxy_type;
    typedef typename
      proxy_type::value_type                                  value_type;
                                      
    value_type from_value  = input.template FieldAt<Idx>().get();
    value_type to_value    = from_value;

    // Create an instance of a selection template that will choose between
    // nested processing, and value conversion.
    ConvertEndianess< value_type,
                      storage_type,
                      typename DeduceTypeTrait<value_type>::type
                    > swap_order;
    swap_order(from_value, to_value);
    output.template FieldAt<Idx>().set(to_value);
  }
};

//  ****************************************************************************
//  ****************************************************************************
/// A no-op functor specialization to handle Message to Message conversions 
/// of the same byte-order.
///
/// @param MessageT       [typename] The input/output message type.
///                       These types are the same, and therefore will not 
///                       trigger any byte-order swap operations.
/// 
template< typename MessageT >
struct ByteOrderConversionFunctor <MessageT, MessageT>
{ 
  //  Typedefs *****************************************************************
  typedef MessageT                      from_message_type;
  typedef MessageT                      to_message_type;

  //  Data Members *************************************************************
  from_message_type input;
  to_message_type   output;

  //  **************************************************************************
  /// Value constructor that initializes the input message to be converted.
  ///
  /// @param rhs      The Message object that contains the input data.
  /// 
  explicit
    ByteOrderConversionFunctor(const from_message_type& from)
    : input(from)
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
  void operator()(const value_t&)
  { 
    // Simply copy the input value to the output value.
    output.template FieldAt<Idx>().set( 
      input.template FieldAt<Idx>().get() 
    );
  }
};

} // namespace detail

} // namespace Hg

#endif
