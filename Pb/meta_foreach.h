/// @file meta_foreach.h
/// 
/// Defines a compile-time equivalent of std::for_each.
/// 
/// Parameterized processing function that iterates through the type container 
/// recursively to visit each targeted element.
///
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef META_FOREACH_H_INCLUDED
#define META_FOREACH_H_INCLUDED
//  Includes *******************************************************************
#include <Pb/meta_fwd.h>

namespace Hg
{

namespace detail
{

//  ****************************************************************************
/// This parameterized construct is used to iterate through each type in the 
/// specified type container.
///         
/// @param  CurIndex    [size_t] The starting index for processing the type container.
///                     This value must be less than EndIndex otherwise a
///                     compiler error will be generated.
/// @param  EndIndex    [size_t]The last index to be processed in the type container.
/// @param  ContainerT  [typename] A type container to process. 
///                     Each type entry within the specified range will be processed. 
///                     A compiler error will be generated if this parameter
///                     is not a Type Container.
/// @param  Function    [typename] The user specified functor to use on each type.
/// 
template <size_t CurIndex, 
          size_t EndIndex,
          typename ContainerT, 
          typename Function>
class ForEachTypeHelper
{
  // TODO: Add these static asserts back once a suitable replacement is created for tr1 libraries.
  //static_assert((CurIndex <= EndIndex), 
  //              "The Current Index must be not be greater than the End Index");
  //static_assert(type_container<ContainerT>::value, 
  //              "ContainerT must be derived from \"container_trait\"");

public:
  //  **************************************************************************
  /// Initializes this helper constructor for applying the input Functor fn to 
  /// each type specified in the Type Container passed to the Functor.
  ///         
  /// @param  fn  The functor that will be called for each type.
  ///
  ForEachTypeHelper(Function& fn)
    : ftor(fn)
  {
    // No current operations.
  }

  //  **************************************************************************
  /// The function that allows this structure to operate as a functor. 
  /// 
  void operator()()
  {
    process<CurIndex, EndIndex, ContainerT>();
  }

private:
  //  Private Data *************************************************************
  Function& ftor;             ///< Used-defined parameterized functor that 
                              ///  is processed on each type in the specified
                              ///  range on the type container.

  //  Private Methods **********************************************************
  //  **************************************************************************
  /// Internal parameterized processing function that iterates through
  /// the type container recursively to visit each targeted element.
  ///         
  /// @tparam  IndexT     [size_t] The starting index for processing the type container.
  /// @tparam  LastT      [size_t] The last index to be processed in the type container.
  /// @tparam  FormatT    [typename] A type container to process. 
  ///                     Each type entry within the specified range will be processed. 
  ///
  template <size_t IndexT,
            size_t LastT,
            typename FormatT>
  void process()
  {
    // Extract the type at the current index specified for this instance
    // of the process helper function, and call the user's functor.
    typedef typename TypeAt<IndexT, FormatT>::type type_t;

#ifdef _WIN32
    ftor.operator() < IndexT, 
                      typename TypeAt<IndexT, FormatT>::type
                    >(type_t());
#else
    // GCC requires a hint to know this is a template call
    ftor. template operator() < IndexT, 
                                typename TypeAt<IndexT, FormatT>::type
                              >(type_t());
#endif 

    // Perform a runtime check to terminate the recursive processing of
    // the type container elements.
    if (IndexT < LastT)
    {
      // The value_if template construct is used to prevent an element from
      // being defined that exceeds the boundaries of the type container.
      process<value_if<(IndexT < LastT),
                        size_t,
                        IndexT+1, 
                        LastT>::value, 
              LastT,
              FormatT>();
    }
  }
};

} // namespace detail

//  ****************************************************************************
/// Meta-template implementation of for_each.
/// 
/// Meta-template to perform a user specified action on every element in the 
/// specified type ContainerT. This is the compile-time equivalent of the 
/// **std::for_each** function.
///           
/// @tparam  BeginIndex [size_t] The starting index for processing the type container.
///                     This value must be less than EndIndex otherwise a
///                     compiler error will be generated.
/// @tparam  EndIndex   [size_t]The last index to be processed in the type container.
/// @tparam  ContainerT [typename] A type container to process. 
///                     Each type entry within the specified range will be processed. 
///                     A compiler error will be generated if this parameter
///                     is not a Type Container.
/// @tparam  Function   [typename] The user specified functor to use on each type.
///
/// @param  fn          A functor that will be called for each type entry in the 
///                     container passed to the forEach function.
///               
///                     Since this function works on a template type, the functor 
///                     must support a parameterized functor that accepts one type.
///                     
/// @return             The input functor is returned to capture any changed state.
///
template <size_t   BeginIndex, 
          size_t   EndIndex,
          typename ContainerT, 
          typename Function>
Function& ForEachType(Function   &fn)
{
  // TODO: Return with a static_assert that is compatible with tr1 compilers.
//  static_assert (BeginIndex <= EndIndex,
//                "The Begin Index must not be greater than the End Index");
  //static_assert (type_container<ContainerT>::value,
  //                "ContainerT must be derived from \"container_trait\"");
  //static_assert (length<ContainerT>::value > 0,
  //               "ContainerT must contain more than 0 type entries.");

  // The helper template is required because this processing is performed
  // on types at compile-time. Dynamic input variables are not permitted for
  // parameterized function calls.
  typedef detail::ForEachTypeHelper<BeginIndex, 
                                    EndIndex, 
                                    ContainerT,
                                    Function>     Handler;
  Handler process(fn);
  process();

  // Return the same functor passed into the ForEachType call similar to
  // the std::for_each call.
  return fn;
}

} // namespace Hg

#endif
