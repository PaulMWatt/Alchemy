/// @file message_dynamic_detail.h
/// 
/// Internal details for the implementation of a dynamic message size query.
/// 
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef MESSAGE_DYNAMIC_DETAIL_H_INCLUDED
#define MESSAGE_DYNAMIC_DETAIL_H_INCLUDED
//  Includes *******************************************************************
#include <Pb/dynamic.h>
#include <Pb/meta_foreach.h>
#include <Pb/optional.h>
#include <Hg/deduce_type_trait.h>

namespace Hg
{

namespace detail
{

//  Forward Declarations *******************************************************
//  ****************************************************************************
template< typename MsgT,
          bool     IsDynamicT
        >
struct DynamicSizeWorker;


namespace nested
{

//  ****************************************************************************
//  Returns the size of a field that contains a dynamically-sized nested type.
//
template< typename  T >
struct dynamic_size
{
  static_assert(Hg::nested_value<T>::value, "Parameterized type T must be a nested-type.");

  static const 
    bool k_has_dynamic  = 
      Hg::has_dynamic<T::format_type>::value;

  static const 
    size_t k_fixed_size = 
      Hg::size_of<typename T::format_type>::value;

  //  **************************************************************************
  static size_t eval(const T& field)
  {
    return eval_size<k_has_dynamic>(field);
  }

private:

  //  **************************************************************************
  template< bool HasDynamicT >
  static size_t eval_size(const T& field)
  {
    size_t total_size = k_fixed_size
                      + DynamicSizeWorker<T, true>().size(field);
    return total_size;  
  }

  //  **************************************************************************
  template<>
  static size_t eval_size<false>(const T& /*field*/)
  {
    return k_fixed_size;  
  }
};

} // namespace nested


//  Dynamic Vector size calculations *******************************************
namespace vector
{ 

//  ****************************************************************************
/// Determines the number of bytes required to serialize a vector.
///    
template< typename T,
          typename A,
          typename TypeTraitT = typename deduce_type_trait<T>::type
        >
struct dynamic_size
{
  //  **************************************************************************
  static
    size_t eval(const std::vector<T,A>& field)
  {
    return field.size() * sizeof(T);
  }
};


//  ****************************************************************************
/// Determines the number of bytes required to serialize a vector.
/// This version handles a vector with sub-messages.
///    
template< typename T,
          typename A
        >
struct dynamic_size<T,A,nested_trait>
{
  //  **************************************************************************
  static
    size_t eval(const std::vector<T,A>& field)
  {
    size_t total = 0;
    for (auto entry : field)
    {
      total += Hg::detail::nested::dynamic_size<T>::eval(entry);
    }

    return total;
  }
};


//  ****************************************************************************
/// Determines the number of bytes required to serialize a vector.
/// This version handles a vector with variable-length types.
///    
template< typename T,
          typename A
        >
struct dynamic_size<T,A,vector_trait>
{
  //  **************************************************************************
  static
    size_t eval(const std::vector<T,A>& field)
  {

    using Size = 
      dynamic_size< typename T::value_type, 
                    typename T::allocator_type, 
                    typename deduce_type_trait<typename T::value_type>::type
                  >;

    size_t total = 0;
    for (size_t index = 0; index < field.size(); ++index)
    {
      total += Size::eval(field[index]);
    }

    return total;
  }
};

} // namespace vector


//  Optional datum dynamic size ************************************************
namespace optional
{
//  ****************************************************************************
/// Determines the number of bytes required to serialize an optional parameter.
///    
template< typename T >
struct dynamic_size
{
  //  **************************************************************************
  static 
    size_t eval(const T& field)
  {
    using type_trait = typename deduce_type_trait<typename T>::type;

    return eval_size<type_trait>(field);
  }

private:

  //  **************************************************************************
  template< typename TraitT>
  static 
    size_t eval_size(const T& /*field*/)
  {
    return Hg::size_of<T>::value;  
  }

  //  **************************************************************************
  template< >
  static 
    size_t eval_size<nested_trait>(const T& field)
  {
    return Hg::detail::nested::dynamic_size<T>::eval(field);
  }

  //  **************************************************************************
  template< >
  static 
    size_t eval_size<vector_trait>(const T& field)
  {
    return Hg::detail::vector::dynamic_size<T::value_type,
                                            T::allocator_type>::eval(field);
  }
};

} // namespace optional



//  ****************************************************************************
/// Reports the total size of the dynamic buffers required for this message.
///    
template< typename T,
          typename A
        >
size_t dynamic_size(const std::vector<T,A>& field)
{
  return Hg::detail::vector::dynamic_size<T,A>::eval(field);
}


//  ****************************************************************************
/// Catch all implementations that returns 0 dynamically-sized data.
///    
template <typename T>
size_t dynamic_size(const T& field)
{
  return 0;
}


//  ****************************************************************************
template< typename MsgT >
struct DynamicSizeFunctor
{
  //  Aliases ******************************************************************
  using message_type          = MsgT;
  using format_type           = typename message_type::format_type;
  using dynamic_field_indices = typename dynamic_fields<format_type>::type;

  //  Data Members *************************************************************
  const message_type &message;
  size_t              m_dynamic_size;

  //  **************************************************************************
  /// Value constructor that initializes the input message being queried.
  ///
  /// @param rhs      The Message object that contains the specified data.
  ///
  explicit
    DynamicSizeFunctor(const message_type& rhs)
    : message(rhs)
    , m_dynamic_size(0)
  { }

  //  **************************************************************************
  /// Parameterized function operator
  ///
  /// Reports the dynamic size of the requested field.
  /// 
  /// @tparam size_t          Parameterized value that specifies the index
  ///                         of the data field to be converted.
  /// @tparam value_type      [typename] A discriminator type for disambiguation.
  /// @param unnamed          An unused variable to disambiguate the appropriate
  ///                         specialization function for the compiler to select.
  /// 
  template< size_t   IdxT,
            typename value_t
          >
  void operator()(const value_t*)
  {
    message_type &msg = const_cast<message_type&>(message);

    calc_dynamic_size<IdxT,format_type> calc;
    m_dynamic_size += calc(msg.template FieldAt<IdxT>());
  }

  //  **************************************************************************
  /// Returns the dynamic size calculated by the functor.
  ///
  size_t size()
  {
    return m_dynamic_size;
  }

private:

  //  **************************************************************************
  //  Tag-dispatched calculation for the dynamic-size of an element.
  //
  template< size_t   IdxT,
            typename FormatT,
            typename TraitT = deduce_type_trait_t<Hg::type_at_t<IdxT, FormatT>>>
  struct calc_dynamic_size
  {
    size_t operator()(Datum<IdxT,FormatT>& field)
    {
      return dynamic_size(field.get());
    }
  };


  //  **************************************************************************
  //  Tag-dispatched calculation for optional data fields.
  //
  template< size_t   IdxT,
            typename FormatT>
  struct calc_dynamic_size<IdxT, FormatT,optional_trait>
  {
    size_t operator()(Datum<IdxT,FormatT>& field)
    {
      using value_type = Datum<IdxT,FormatT>::value_type;

      return  field.is_valid()
              ? Hg::detail::optional::dynamic_size<value_type>::eval(field.get())
              : 0;
    }
  };
};




//  ****************************************************************************
/// Helper functor to iterate and query the size of a dynamically-sized message.
///
template< typename MsgT,
          bool     IsDynamicT
        >
struct DynamicSizeWorker
{
  static
    size_t size(const MsgT& msg)
  {
    using message_type  = MsgT;
    using format_type   = typename message_type::format_type;

    // Initialize a functor to query for the dynamic size of each field.
    detail::DynamicSizeFunctor< message_type > ftor(msg);
    Hg::ForEachType < 0,
                      Hg::length<format_type>::value - 1,
                      format_type
                    > (ftor);

    return ftor.size();   
  }
};


//  ****************************************************************************
/// Specialization for statically-sized messages.
///
template< typename MsgT >
struct DynamicSizeWorker<MsgT, false>
{
  static
    size_t size(const MsgT& msg)
  {
    return 0;  
  }
};


} // namespace detail

} // namespace Hg

#endif
