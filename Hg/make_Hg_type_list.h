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
  typedef T                             type;
};

//  ****************************************************************************
//  Processes a child nested-type for Hg compatibility.
// 
//  @tparam T             The type container used for the type declaration.
//
template< typename T >
struct DeclareTypeSequence < T, nested_trait >
{
  typedef typename
    make_Hg_type_list<T>::type          type;
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
  // Define a typedef that represents the actual data-type
  // that reprsents the type-list T passed into this array.
  typedef typename
    FieldTypes <T>::value_type          value_type;

  typedef  
    std::array< value_type, N>          type;
};

//  ****************************************************************************
//  Processes a nested field recursively to correct any vector definitions.
// 
//  @tparam VectorT       The vector definition type.
//  @tparam T             The value type in the container.
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
    FieldTypes <T>::value_type          value_type;

  typedef 
    std::vector< value_type, A>         type;
};



//  ****************************************************************************
//  The default implementation is a no-op and returns the same type.
// 
template< class T,
          class TraitT>
struct ReplaceType
{
  typedef T                             type;
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

  // If the value type has a dynamic size, then the array will be converted
  // to a vector, with a pre-allocated size.
  // This greatly simplifies serialization.
  // It also allows pure fixed-size constructs to be optimized as such.
  typedef typename
    DeclareTypeSequence < ArrayT, 
                          type_trait
                        >::type         array_type;

  // TODO: Delete this commented code
  //typedef typename
  //  DeclareTypeSequence < std::vector<value_type>, 
  //                        type_trait
  //                      >::type         vector_type;
  
  typedef array_type                    type;
  // TODO: Delete this commented code
  //typedef typename
  //  std::conditional< has_dynamic<value_type>::value, 
  //                    vector_type, 
  //                    array_type
  //                  >::type             type;
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
    Hg::push_front< adjusted_type,       // The list of types converted for Hg.
                    hg_list
                  >::type               type; 
};

//  ****************************************************************************
//  Terminating case where the next element reported by the input list is empty.
// 
template< typename LList,
          typename PList
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
template< typename T>
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
                            Hg::type_list<>
                          >::type       type;
};


} // namespace Hg


#endif


// TODO: This will be deleted when it is verified the BitFieldArray and Vector are not needed. A better approach has been developed, the msg_view.
//  ****************************************************************************
//  Declares a BitFieldArray in place of the array<bit_field> definition.
// 
//  @tparam ArrayT        The array definition type.
//  @tparam T             The value type in the container.
//  @param  N             The number of elements in the container.
//
//template< typename   T,
//          size_t  N,
//          template <typename, size_t> typename ArrayT
//        >
//struct DeclareTypeSequence < ArrayT<T,N>, packed_trait >
//{
//  typedef 
//    Hg::BitFieldArray<T, N>             type;
//};


//  ****************************************************************************
//  Declares a BitFieldVector in place of the vector<bit_field> definition.
// 
//  @tparam VectorT       The vector definition type.
//  @tparam T             The value type in the container.
//  @param  A             The allocator used for memory management.
//
//template< class T,
//          class A,
//          template <class, class> class VectorT
//        >
//struct DeclareTypeSequence < VectorT<T,A>, packed_trait >
//{
//  typedef  
//    Hg::BitFieldVector<T, A>            type;
//};

