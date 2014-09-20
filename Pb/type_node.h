/// @file meta/type_node.h
/// 
/// Defines a basic building block for type operations.
/// 
/// This file contains the declarations for a template meta-program TypeNode. 
/// The node is useful for creating more useful type constructs by 
/// concatenating strings of these types.
///
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef TYPE_NODE_H_INCLUDED
#define TYPE_NODE_H_INCLUDED
//  Includes ******************************************************************

namespace Hg
{

  //  ****************************************************************************
  /// A fundamental type used for template meta-programming type containers.
  /// 
  /// The fundamental element that is used to create both a template-meta 
  /// TypeList and TypeList. These constructs are useful for building structures 
  /// known at compile time that incur a very minimal runtime cost.
  ///           
  /// These constructs have a data buffer allocated with a size that matches the 
  /// size of the two parameterized types passed in. This will allow these types 
  /// to behave similar to the intrinsic types for calculating and creating 
  /// objects on the stack.
  ///
  template <typename H, typename T>
  struct TypeNode
  {
    typedef H head;
    typedef T tail;

  private:
    unsigned char                     size_info_[sizeof(H)+sizeof(T)];
  };

  //  ****************************************************************************
  /// A terminator for TypeNode chains.
  /// 
  /// A specialized version of the TypeNode template to facilitate sizeof 
  /// calculations that are consistent with how the operator behaves for 
  /// intrinsic and regular user-defined types.
  /// 
  /// This specialization is the equivalent of applying the EBO. Otherwise, the 
  /// size of the MT type all by itself will add the mandatory 1 extra byte. 
  /// This creates an off-by-one error for all objects since this is the 
  /// terminator case.
  ///
  template <typename H>
  struct TypeNode<H, MT>
  {
    typedef H     head;
    typedef MT tail;
  private:
    unsigned char                     size_info_[sizeof(H)];

    // prevent the instantiation of a TypeNode, and all types built upon it.
    ~TypeNode();
  };

} // namespace Hg

#endif
