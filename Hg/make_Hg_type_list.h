/// @file Hg/detail/make_Hg_type_list.h
/// 
/// Processes a basic typelist to be compatible with types required for Hg.
///
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef MAKE_HG_TYPE_LIST_H_INCLUDED
#define MAKE_HG_TYPE_LIST_H_INCLUDED
//  Includes ******************************************************************
#include <Pb/type_list.h>
#include <Hg/proxy/deduce_proxy_type.h>
#include <Pb/dynamic.h>

namespace Hg
{

//  Forward Declarations *******************************************************
//  ****************************************************************************
/// Creates a type list suitable for processing within Hg messages.
///
/// Some field types, such as arrays and vectors, may be defined with raw
/// types. This prevents Hg from properly interfacing with the parameters
/// to accurately serialize the data.
/// 
template< typename T>
struct make_Hg_type_list;

namespace detail
{

//  Overview *******************************************************************
//
//  Generally only the array and vector require type replacements for their
//  proper functioning. In some cases it is more efficient to create 
//  a specialized version of the array/vector, such as with the BitFieldArray.
//
//  The table below indicates the combination types that have replacements
//  defined for them.
//
//  Type<T>:      Sub-type<S>:    Substitution Required:
//  -----------   -----------     ----------------------------
//  Fundamental   n/a             none
//  BitField      n/a             none
//  Nested        n/a             make_Hg_type_list<T>::type
//
//  Array         Fundamental     none
//  Array         BitField        BitFieldArray
//  Array         Nested          make_Hg_type_list<S>::type
//  Array         Array           yes    / Sub-type also processed
//  Array         Vector          vector / Sub-type also processed
//
//  Vector        Fundamental     none
//  Vector        BitField        BitFieldVector
//  Vector        Nested          make_Hg_type_list<S>::type
//  Vector        Array           yes  / Sub-type also processed
//  Vector        Vector          yes  / Sub-type also processed
//
//


//  ****************************************************************************
//  Creates the proper type declaration for a sequence container type.
// 
//  @tparam T             The type container used for the declaration.
/// @tparam ValueTraitT   The trait type of the value_type of the container.
//
template< typename T,
          typename ValueTraitT
        >
struct DeclareTypeSequence
{
  using type = T;
};

//  ****************************************************************************
//  Processes a child nested-type for Hg compatibility.
// 
//  @tparam T             The type container used for the type declaration.
//
template< typename T >
struct DeclareTypeSequence < T, nested_trait >
{
  using type = typename make_Hg_type_list<T>::type;
};

//  ****************************************************************************
//  Redeclares the array of nested types, as an array of nested Hg types.
// 
//  @tparam ArrayT        The array definition type.
//  @tparam T             The value type in the container.
//  @param  N             The number of elements in the container.
//
template< typename   T,
          size_t  N,
          template <typename, size_t> class ArrayT
        >
struct DeclareTypeSequence < ArrayT<T,N>, nested_trait >
{
  // Define an alias that represents the actual data-type
  // that reprsents the type-list T passed into this array.
  using value_type  = typename FieldTypes <T>::value_type;
  using type        = std::array< value_type, N>;
};

//  ****************************************************************************
//  Processes a nested field recursively to correct any vector definitions.
// 
//  @tparam VectorT       The vector definition type.
//  @tparam T             The value type in the container.
//  @param  A             The allocator used for memory management.
//
template< typename T,
          typename A,
          template <typename, typename> class VectorT
        >
struct DeclareTypeSequence < VectorT<T,A>, nested_trait  >
{
  // Define an alias that represents the actual data-type
  // that reprsents the type-list T passed into this array.
  using value_type = typename FieldTypes <T>::value_type;
  using type       = std::vector< value_type, A>;
};



//  ****************************************************************************
//  The default implementation is a no-op and returns the same type.
// 
template< typename T,
          typename TraitT>
struct ReplaceType
{
  using type = T;
};

//  ****************************************************************************
//  The array type requires the specific definitions for internal types.
// 
template< typename ArrayT >
struct ReplaceType< ArrayT, array_trait>
{
  // Extract the type and extent from the array declaration.
  using value_type = typename ArrayT::value_type;

  // Deduce the type trait of value_type
  // for declaration of the type sequence.
  using type_trait = deduce_type_trait_t<value_type>;

  // If the value type has a dynamic size, then the array will be converted
  // to a vector, with a pre-allocated size.
  // This greatly simplifies serialization.
  // It also allows pure fixed-size constructs to be optimized as such.
  using array_type = typename DeclareTypeSequence < ArrayT, type_trait>::type;
  using type       = array_type;
};

//  ****************************************************************************
//  The vector type requires the specific definitions for internal types.
// 
template< typename VectorT >
struct ReplaceType< VectorT, vector_trait>
{
  // Extract the value type declaration from inside the vector declaration.
  using value_type = typename VectorT::value_type;

  // Deduce the type trait of value_type
  // for declaration of the type sequence.
  using type_trait = deduce_type_trait_t<value_type>;

  using type = typename DeclareTypeSequence < VectorT, type_trait>::type;
};


//  ****************************************************************************
//  Inspects the input type, and applies adjustments for compatibility with Hg.
// 
template< typename T >
struct AdjustType
{
  using type = typename ReplaceType <T, deduce_type_trait_t<T>>::type;
};

//  ****************************************************************************
//  Inspect each item and add the proper format to the final type_list.
// 
template< typename T,
          typename TailT,
          typename HgT
        >
struct make_Hg_worker
{
  // The result of inspecting a type and
  // potentially adjusting the type.
  using adjusted_type = typename AdjustType<T>::type;

  // The next item on the list to process.
  using next_type = Hg::front_t<TailT>;

  // The remainder of the unprocessed types.
  using list_tail = Hg::pop_front_t<TailT>;

  // A recursively built list of processed
  // types that have been adjusted to be
  // compatible for Hg message types.
  using hg_list = typename make_Hg_worker < next_type,          
                                            list_tail,          
                                            HgT                 
                                          >::type;
            
  // The list of types converted for Hg.
  using type = Hg::push_front_t< adjusted_type, hg_list>; 
};

//  ****************************************************************************
//  Terminating case where the next element reported by the input list is empty.
// 
template< typename LList,
          typename PList
        >
struct make_Hg_worker < Hg::MT, LList, PList>
{
  using type = PList;
};

} // namespace detail


// TODO: The solution for this function is very similar to the type_list implementation of move_item. Revisit, and investigate the possibility of creating a "transform" function with a meta-functor.

//  ****************************************************************************
//  @Note:  Type T must be a type_list.
//
template< typename T>
struct make_Hg_type_list
{
  using type = 
    typename detail::make_Hg_worker < Hg::front_t<T>,
                                      Hg::pop_front_t<T>,
                                      Hg::type_list<>
                                    >::type;
};


} // namespace Hg


#endif

