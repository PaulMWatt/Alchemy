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
#include <meta/type_list.h>
#include <meta/type_at.h>
#include <Hg/proxy/deduce_proxy_type.h>
#include <meta/bit_field/bit_field_array.h>
#include <meta/bit_field/bit_field_vector.h>

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
template< class T>
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
//  Array         Nested          yes  / make_Hg_type_list<S>::type
//  Array         Array           yes  / Sub-type also processed
//  Array         Vector          yes  / Sub-type also processed
//
//  Vector        Fundamental     none
//  Vector        BitField        BitFieldVector
//  Vector        Nested          yes  / make_Hg_type_list<S>::type
//  Vector        Array           yes  / Sub-type also processed
//  Vector        Vector          yes  / Sub-type also processed
//
//


//  ****************************************************************************
//  Creates a type list with exactly one type entry.
// 
template < class T >
struct StartTypeList
{
  typedef typename
    Hg::push_front< Hg::TypeList< Hg::MT >, 
                    T 
                  >::type               type;
};

//  ****************************************************************************
//  Creates the proper type declaration for a sequence container type.
// 
//  @paramt T             The type container used for the declaration.
/// @paramT ValueTraitT   The trait type of the value_type of the container.
//
template< class T,
          class ValueTraitT
        >
struct DeclareTypeSequence
{
  typedef T                             type;
};

//  ****************************************************************************
//  Processes a child nested-type for Hg compatibility.
// 
//  @paramt T             The type container used for the type declaration.
//
template< class T >
struct DeclareTypeSequence < T, nested_trait >
{
  typedef typename
    make_Hg_type_list<T>::type          type;
};

//  ****************************************************************************
//  Declares a BitFieldArray in place of the array<bit_field> definition.
// 
//  @paramt ArrayT        The array definition type.
//  @paramt T             The value type in the container.
//  @param  N             The number of elements in the container.
//
template< class   T,
          size_t  N,
          template <class, size_t> class ArrayT
        >
struct DeclareTypeSequence < ArrayT<T,N>, bitfield_trait >
{
  typedef typename 
    Hg::BitFieldArray<T, N>             type;
};

//  ****************************************************************************
//  Redeclares the array of nested types, as an array of nested Hg types.
// 
//  @paramt ArrayT        The array definition type.
//  @paramt T             The value type in the container.
//  @param  N             The number of elements in the container.
//
template< class   T,
          size_t  N,
          template <class, size_t> class ArrayT
        >
struct DeclareTypeSequence < ArrayT<T,N>, nested_trait >
{
  // Define a typedef that represents the actual data-type
  // that reprsents the type-list T passed into this array.
  typedef typename
    FieldTypes <T, 0>::value_type       value_type;

  // TODO: Ignore proxies for now, simply substitute with the field::value_type for a nested value.
  // TODO: Undoubtedly we will need to return and recursively process this type even if a nested type is determined to be unnecessary.
  typedef typename 
    std::array< value_type, N>          type;

  //typedef typename 
  //  make_Hg_type_list<T>::type          datum_type;

  //typedef Hg::detail::DataProxy 
  //          < nested_trait,
  //            0,
  //            typename StartTypeList<datum_type>::type,
  //            0
  //          >                           proxy_type;

  //typedef typename 
  //  std::array< datum_type, N>          type;

  // TODO: The nested processing needs to catch up to this definition.
  //typedef typename 
  //  std::array< proxy_type, N>          type;
};

//  ****************************************************************************
//  Declares a BitFieldVector in place of the vector<bit_field> definition.
// 
//  @paramt VectorT       The vector definition type.
//  @paramt T             The value type in the container.
//  @param  A             The allocator used for memory management.
//
template< class T,
          class A,
          template <class, class> class VectorT
        >
struct DeclareTypeSequence < VectorT<T,A>, bitfield_trait >
{
  typedef typename 
    Hg::BitFieldVector<T, A>            type;
};

//  ****************************************************************************
//  Declares a BitFieldVector in place of the vector<bit_field> definition.
// 
//  @paramt VectorT       The vector definition type.
//  @paramt T             The value type in the container.
//  @param  A             The allocator used for memory management.
//
template< class T,
          class A,
          template <class, class> class VectorT
        >
struct DeclareTypeSequence < VectorT<T,A>, nested_trait  >
{
  // Define a typedef that represents the actual data-type
  // that reprsents the type-list T passed into this array.
  typedef typename
    FieldTypes <T, 0>::value_type       value_type;

  // TODO: Ignore proxies for now, simply substitute with the field::value_type for a nested value.
  // TODO: Undoubtedly we will need to return and recursively process this type even if a nested proxy is determined to be unnecessary.
  typedef typename 
    std::vector< value_type, A>         type;

  //typedef typename 
  //  make_Hg_type_list<T>::type          datum_type;

  //typedef Hg::detail::DataProxy 
  //          < nested_trait,
  //            0,
  //            typename StartTypeList<datum_type>::type,
  //            0
  //          >                           proxy_type;

  //typedef typename 
  //  std::vector< datum_type, A>         type;

  // TODO: The nested processing needs to catch up to this definition
  //typedef typename 
  //  std::vector< proxy_type, A>         type;
};



//  ****************************************************************************
//  The default implementation is a no-op and returns the same type.
// 
template< class T,
          class TraitT>
struct ReplaceType
{
  typedef typename T                    type;
};

//  ****************************************************************************
//  The array type requires the specific definitions for internal types.
// 
template< class ArrayT >
struct ReplaceType< ArrayT, array_trait>
{
  // Extract the type and extent from the array declaration.
  typedef typename
    ArrayT::value_type                  value_type;

  // Deduce the type trait of value_type
  // for declaration of the type sequence.
  typedef typename
    DeduceTypeTrait<value_type>::type   type_trait;

  typedef typename
    DeclareTypeSequence < ArrayT, 
                          type_trait
                        >::type         type;
};

//  ****************************************************************************
//  The vector type requires the specific definitions for internal types.
// 
template< class VectorT >
struct ReplaceType< VectorT, vector_trait>
{
  // Extract the value type declaration from inside the vector declaration.
  typedef typename
    VectorT::value_type                 value_type;

  // Deduce the type trait of value_type
  // for declaration of the type sequence.
  typedef typename
    DeduceTypeTrait<value_type>::type   type_trait;

  typedef typename
    DeclareTypeSequence < VectorT, 
                          type_trait
                        >::type         type;
};


//  ****************************************************************************
//  Inspects the input type, and applies adjustments for compatibility with Hg.
// 
template< class T >
struct AdjustType
{
  typedef typename 
    ReplaceType < T, 
                  typename DeduceTypeTrait<T>::type 
                >::type                 type;
};

//  ****************************************************************************
//  Inspect each item and add the proper format to the final type_list.
// 
template< class T,
          class TailT,
          class HgT
        >
struct make_Hg_worker
{
                                        // The result of inspecting a type and
  typedef typename                      // potentially adjusting the type.
    AdjustType<T>::type                 adjusted_type;
                                        


  typedef typename                      // The next item on the list to process.
    Hg::front<TailT>::type              next_type;
                                        

  typedef typename                      // The remainder of the unprocessed types.
    Hg::pop_front<TailT>::type          list_tail;
                                        

  typedef typename                      
    make_Hg_worker< next_type,          // A recursively built list of processed
                    list_tail,          // types that have been adjusted to be
                    HgT                 // compatible for Hg message types.
                  >::type               hg_list;
                                        
  typedef typename  
    Hg::push_front< hg_list,
                    adjusted_type       // The list of types converted for Hg.
                  >::type               type; 
};

//  ****************************************************************************
//  Terminating case where the next element reported by the input list is empty.
// 
template< class LList,
          class PList
        >
struct make_Hg_worker < Hg::MT, 
                        LList, 
                        PList>
{
  typedef PList                         type;
};

} // namespace detail




//  ****************************************************************************
//  @Note:  Type T must be a typelist.
//
template< class T>
struct make_Hg_type_list
{
protected:
  typedef typename                      // The next item on the list to process.
    Hg::front<T>::type                  next_type;
                                        

  typedef typename                      // The remainder of the unprocessed types.
    Hg::pop_front<T>::type              list_tail;


public:                                        
  typedef typename                      // Make the Hg compatible list.
    detail::make_Hg_worker< next_type,
                            list_tail,
                            Hg::TypeList<Hg::MT>
                          >::type       type;
};


} // namespace Hg


#endif
