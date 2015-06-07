/// @file Pb/type_list.h
/// 
/// Provides an implementation for the type_list template meta-programming construct. 
/// Utility functions are also provided to inspect and modify the contents
/// of a type_list definition.
//  
//  - **param_pack**
//      A type that simply holds a template parameter pack.      
//
//  - **add_to**
//      Meta-function that adds types to a template parameter pack. 
//
//  - **to_param_pack**
//      Converts an existing type to a param_pack definition.
//
//  - **make_type_list**
//      Meta-function that defines a new instance of a type_list from various types.
//
//  - **type_list**
//      This provides compile-time reflection upon the type_list type collection. 
//      definition to query the type of parameter at the specified index.
// 
//  - **length**
//      Determines the number of elements in the **type_list**.
// 
//  - **type_at**
//      Determines the type of an element at a specified index in the **type_list**.
// 
//  - **front**
//      Returns the type for the element at the beginning of the **type_list**.
//      
//  - **pop_front**
//      Removes the type for the element at the beginning of the 
//      **type_list**. The type_list defined in the resulting
//      meta-structure is the original type_list with the first element removed.
//      
//  - **push_front**
//      Pushes a new type at the beginning of the **type_list**.
//      
//  - **push_back**
//      Pushes a new type at the end of the **type_list**.
//      
//  - **back**
//      Returns the type for the element at the end of the **type_list**.
// 
//  - **move_item**
//      Moves a specified number of items from one list into another.
// 
//  - **split**
//      Splits a list at a specified number of elements.
// 
/// The MIT License(MIT)
/// @copyright 2015 Paul M Watt
//  ****************************************************************************
#ifndef TYPE_LIST_H_INCLUDED
#define TYPE_LIST_H_INCLUDED
//  Includes *******************************************************************
#include <Pb/meta_fwd.h>

namespace Hg
{

//  Forward Declarations *******************************************************
template<typename T, typename U> struct add_to;

template <typename... T>
struct type_node;

template< typename... NodesT >
struct type_list;

template< typename... P > 
struct to_param_pack;

template< typename... T>
struct make_type_list;

template <typename T>
struct length;

template< std::size_t IdxT, typename T>
struct type_at;

template< typename T >
struct front;

template< typename T >
struct back;

template< typename T >
struct pop_front;

template< typename T >
struct pop_back;

template<typename F, typename L>
struct push_front;

template<typename L, typename B>
struct push_back;

template<std::size_t CountT, typename L, typename R>
struct move_item;

template<std::size_t IdxT, typename T>
struct split;

//  Template Alias Definitions *************************************************

//  ****************************************************************************
/// Alias for add_to template meta-function for combining types to parameter packs.
/// 
template<typename T, typename U>
using add_to_t = typename add_to<T,U>::type;

//  ****************************************************************************
/// Alias for the meta-function that converts a type into a parameter pack.
/// 
template< typename... P > 
using to_param_pack_t = typename to_param_pack <type_node<P...>>::type;

//  ****************************************************************************
/// Alias for make_type_list template meta-function for working with type_list.
/// 
template< typename... T>
using make_type_list_t = typename make_type_list< T... >::type;

//  ****************************************************************************
/// Alias for type_at template meta-function for working with type_list.
/// 
template< std::size_t IdxT, typename T >
using type_at_t = typename type_at<IdxT, T>::type;

//  ****************************************************************************
/// Alias for front template meta-function for working with type_list.
/// 
template< typename T >
using front_t = typename front<T>::type;

//  ****************************************************************************
/// Alias for front template meta-function for working with type_list.
/// 
template< typename T >
using back_t = typename back<T>::type;

//  ****************************************************************************
/// Alias for pop_front template meta-function for working with type_list.
/// 
template< typename T >
using pop_front_t = typename pop_front<T>::type;

//  ****************************************************************************
/// Alias for pop_front template meta-function for working with type_list.
/// 
template< typename T >
using pop_back_t = typename pop_back<T>::type;

//  ****************************************************************************
/// Alias for push_front template meta-function for working with type_list.
/// 
template< typename F, typename L >
using push_front_t = typename push_front<F, L>::type;

//  ****************************************************************************
/// Alias for push_back template meta-function for working with type_list.
/// 
template< typename L, typename B >
using push_back_t = typename push_back<L, B>::type;

//  ****************************************************************************
/// Alias for push_back template meta-function for working with type_list.
/// 
template<std::size_t IdxT, typename...T>
using split_t = typename split<IdxT, T...>::type;


//  ****************************************************************************
//  ****************************************************************************
/// A construct that holds template parameter packs in a variable form.
///
template< typename... T > 
struct param_pack
{ };


//  ****************************************************************************
/// Adds a type T to the end of an existing parameter pack.
///
/// @tparam T       The type to add at the beginning of the parameter pack. 
/// @tparam ArgsU   The pack of types to add at the end of the parameter pack.
///
/// @return         'type' will be defined that contains a param_pack type, which
///                 can provide access to the accumulated parameter pack.
///
template<typename T, typename... ArgsU>
struct add_to<T, param_pack<ArgsU...>>
{
  using type = param_pack<T, ArgsU...>;
};

//  ****************************************************************************
/// Adds a type T to the end of an existing parameter pack.
///
/// @tparam ArgsT   The pack of types to add at the beginning of the parameter pack. 
/// @tparam ArgsU   The type to add at the end of the parameter pack.
///
/// @return         'type' will be defined that contains a param_pack type, which
///                 can provide access to the accumulated parameter pack.
///
template<typename... ArgsT, typename U>
struct add_to<param_pack<ArgsT...>, U>
{
  using type = param_pack<ArgsT..., U>;
};

//  ****************************************************************************
/// Adds a type T to the end of an existing parameter pack.
///
/// @tparam ArgsT   The pack of types to add at the beginning of the parameter pack. 
/// @tparam ArgsU   The pack of types to add at the end of the parameter pack.
///
/// @return         'type' will be defined that contains a param_pack type, which
///                 can provide access to the accumulated parameter pack.
///
template<typename... ArgsT, typename... ArgsU>
struct add_to<param_pack<ArgsT...>, param_pack<ArgsU...>>
{
  using type = param_pack<ArgsT..., ArgsU...>;
};



//  ****************************************************************************
/// Extracts the parameter pack from a type_node.
///
/// @tparam   The parameter pack that is part of the definition for a type_node.
///
/// 'type' is defined as a param_pack that holds the parameter pack extracted
/// from the type_node.
///
template< typename... P > 
struct to_param_pack <type_node<P...>>
{
  using type = param_pack<P...>;
};



//  ****************************************************************************
//  Empty node, acts as the terminating node of a recursive parameter pack.
//
template <>
struct type_node<>
{
  using head = empty;
  using tail = empty;
};

//  ****************************************************************************
//  Recursive type node definition that forms the structure of a type_list.
//
template< typename    H,
          typename... T
        >
struct type_node<H, T...>
  : public type_node<T...>
{
  using head = H;
  using tail = type_node<T...>;
};


//  ****************************************************************************
//  Type container for use with meta-function processing.
//  Meta-function operations are supported to allow the introspection of the
//  types, modification of the list, and size calculations of the internal types.
//
template< typename... NodesT >
struct type_list
  : container_trait
{
   using type = type_node<NodesT...>; 
};


//  ****************************************************************************
/// Default implementation of this meta-function that creates a type_list 
/// from a raw parameter pack.
/// 
/// @tparam T   A basic parameter pack.
///
/// 'type' is defined as the new type_list.
///
template< typename... T>
struct make_type_list
{
   using type  = type_list<T...>;
};

//  ****************************************************************************
/// Meta-function creates a type_list definition from the internal type_nodes.
/// 
/// @tparam T   The parameter pack that will be extracted from an existing 
///             type_node to create a type_list.
///
/// 'type' is defined as the new type_list.
///
template< typename... T>
struct make_type_list< type_node<T...>>
{
   using type  = type_list<T...>;
};

//  ****************************************************************************
/// Meta-function creates a type_list definition from a param_pack container.
/// 
template< typename... T>
struct make_type_list< param_pack<T...>>
{
   using type  = type_list<T...>;
};



//  ****************************************************************************
//  Recursive helper function to identify the type of a node at a specific index.
//
//  IdxT    The index of the node to inspect
//  NodesT  The node sequence of the type_list to inspect.
//
//  'type' is defined as the type that is deduced for the requested node index.
//
template< std::size_t    IdxT, 
          typename  NodesT
        >
struct type_of_node
{
  using type = 
    typename type_of_node<IdxT-1, typename NodesT::tail>::type;
};

//  ****************************************************************************
//  Terminating specialization to deduce the type held at the specified index.
//  We allow more nodes after we have identified our target because we may
//  stop in the middle of a list. 
//
//  NodesT  The node sequence of the type_list to inspect. The head element
//          from this type will be specified as the type.
//
template< typename  NodesT >
struct type_of_node<0, NodesT>
{
  using type = typename NodesT::head;
};



//  ****************************************************************************
//  Inspection meta-functions

//  ****************************************************************************
/// Default implementation to return the length for a regular type.
///
/// @return     A type called 'value' will be defined always indicates 1.
///
template < typename T>
struct length
  : std::integral_constant<std::size_t, 1>
{ };

//  ****************************************************************************
/// Returns the number of elements in a parameter pack.
///
/// @tparam T   The parameter pack held within a param_pack template.
///
/// @return     A type called 'value' will be defined that contains the number
///             of elements that are held in the parameter pack.
///
template< typename... T > 
struct length<param_pack<T...>>
  : std::integral_constant<std::size_t, sizeof...(T)>
{ };

//  ****************************************************************************
/// Returns the number of elements in the type_list.
///
/// @tparam T   The parameter pack held within a type_list template.
///
/// @return     A type called 'value' will be defined that contains the number
///             of elements that are held in the parameter pack.
///
template< typename... T >
struct length<type_list<T...>>
  : std::integral_constant<std::size_t, sizeof...(T)>
{ };

//  ****************************************************************************
/// Specialization of length for an empty (MT) type_list.
///
/// @return     A type called 'value' will be defined always to indicate 0.
///
template <>
struct length< MT > 
  : std::integral_constant<std::size_t, 0>
{ };



//  ****************************************************************************
/// Meta-function that determines the type at a specified index in a type_list.
/// 
/// @tparam IdxT  The zero-based index to reference in the type_list.
///               This value must be < the number of elements in the type_list.
/// @tparam T     The type_list to be queried.
///
/// @return       A type declaration called 'type' is defined that represents
///               the type at the specified index.
///
/// Usage:
/// ~~~{.cpp}
/// using TL = type_list<int, char, float, long>;
/// 
/// static_assert(std::is_same<float, type_at<2, TL>::type>::value, "");
/// 
/// ~~~
///
template< std::size_t IdxT, 
          typename    T  
        >
struct type_at
{
  using nodes = typename T::type;
  using type  = typename type_of_node<IdxT, nodes>::type;
  using rest  = typename make_type_list<typename nodes::tail>::type;
};

//  ****************************************************************************
/// Terminating specialization for the type_at meta-function.
/// 
template< std::size_t IdxT >
struct type_at< IdxT, type_list<> >
{
  using nodes = MT;
  using type  = MT;
  using rest  = MT;
};


//  ****************************************************************************
/// This allows the first type in the list to be returned.
/// 
/// @tparam T   The type_list for which the type of the first node will be returned.
///
/// 'type' will be defined to indicate the type of the first element.
/// 'rest' will be defined to return access to the remainder of the type_list.
///
template< typename T >
struct front
{
  /// Type of the first element in the list.
  using type = type_at_t<0, T>;
  using rest = typename type_at<0, T>::rest;
};



//  ****************************************************************************
/// This allows the last type in the list to be returned.
/// 
/// @tparam T   The type_list for which the type of the last node will be returned.
///
/// 'type' will be defined to indicate the type of the last element.
///
template< typename T >
struct back
{
  /// Type of the last element in the list.
  using type = type_at_t<length<T>::value-1, T>;
};


//  ****************************************************************************
//  Modifiers

//  ****************************************************************************
/// This allows the first type of the list to be removed, and
/// the remainder of the list will become the type alias.
/// 
/// @tparam T   The type_list from which the first element will be removed.
///
/// 'type' will be defined to contain the remainder of the type_list.
///
template< typename T >
struct pop_front
{
  using type = typename front<T>::rest;
};

//  ****************************************************************************
/// Terminating specialization for pop_front.
///
template< >
struct pop_front< type_list<> >
{
  using type = MT;
};


//  ****************************************************************************
/// This allows the last type of the list to be removed, and
/// the remainder of the list will become the type alias.
/// 
/// @tparam T   The type_list from which the last element will be removed.
///
/// 'type' will be defined to contain the remainder of the type_list.
///
template< typename T >
struct pop_back
{
  using type = split_t<length<T>::value - 1, T>;
};

//  ****************************************************************************
/// Terminating specialization for pop_back.
///
template< >
struct pop_back< type_list<> >
{
  using type = MT;
};


//  ****************************************************************************
/// This allows the a new type to be pushed at the front of the list.
/// The new list will become the alias of the pushed type and
/// the existing type list.
/// 
/// 'type' will be defined to contain the type_list with a new element at the front.
///
template<typename F, typename L>
struct push_front
{
private:
   using params = typename to_param_pack<typename L::type>::type;
   using sum    = typename add_to<F, params>::type;

public:
   using type   = typename make_type_list<sum>::type;
};



//  ****************************************************************************
/// This allows the a new type to be pushed at the back of the list.
/// The new list will become the alias of the pushed type and
/// the existing type list.
/// 
/// 'type' will be defined to contain the type_list with a new element at the end.
///
template<typename L, typename B>
struct push_back
{
private:
   using params = typename to_param_pack<typename L::type>::type;
   using sum    = typename add_to<params, B>::type;

public:
   using type   = typename make_type_list<sum>::type;
};



//  ****************************************************************************
/// Moves CountT item of the type on the right (R) to the type on the left (L).
/// 
/// @tparam CountT  The number of elements to move between the two lists.
/// @tparam L       The type_list which will receive the elements added 
///                 to the back of the type.
/// @tparam R       The type_list from which the front elements will be 
///                 moved to the other type.
///
/// 'type' will be defined to contain the resulting left-hand type.
/// 'rest' will be defined to contain the resulting right-hand type.
///
template<std::size_t CountT, typename T, typename R>
struct move_item
{
private:
  using first = push_back_t<T, front_t<R>>;
  using last  = pop_front_t<R>;

public:
  using type  = typename move_item<CountT-1, first, last>::type;
  using rest  = typename move_item<CountT-1, first, last>::rest;
};


//  ****************************************************************************
/// The terminating specialization for this move meta-function.
/// 
template<typename T, typename R>
struct move_item<0, T, R>
{
public:
  using type  = T;
  using rest  = R;
};


//  ****************************************************************************
/// Splits the list into two separate lists at the specified pivot index.
/// 
/// @tparam PivitT  The number of elements where the list should be split.
/// @tparam T       The type_list which will be split into two lists.
///
/// 'type' will be defined to contain the type_list from the start to the split.
/// 'rest' will be defined to contain the type_list with the split to the end.
///
template<std::size_t PivotT, typename T>
struct split
{
  static_assert(PivotT <= length<T>::value,
                "The split pivot index is out of range");

  using type = typename move_item<PivotT, type_list<>, T>::type;
  using rest = typename move_item<PivotT, type_list<>, T>::rest;
};


} // namespace Hg

#endif
