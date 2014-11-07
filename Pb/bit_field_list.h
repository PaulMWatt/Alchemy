/// @file meta/bit_field_list.h
/// 
/// Defines a collector for bit-fields parameters used with Alchemy message formats.
/// The BitFieldList is the top-level container used to collect all of the 
/// individual bit-fields.
///
/// Each bit-field is contained withing a BitFieldNode. These nodes are 
/// organized as a static link-list. One new node is added for each bit-field
/// that is part of the full bit list.
///
/// The current limit is 32 bit-field entries. 
/// Expanding this limit requires expanding the size of the integer_sequence
/// and the DeduceBitFieldList structures.
/// 
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef BIT_FIELD_LIST_H_INCLUDED
#define BIT_FIELD_LIST_H_INCLUDED
//  Includes *******************************************************************
#include <Pb/meta_fwd.h>
#include <Pb/bit_field/basic_list.h>
#include <Pb/bit_field/bit_field.h>
#include <Pb/integer_sequence.h>

namespace Hg
{


//  ****************************************************************************
/// A node to represent a single bit-field in a sequence of a bit-field list.
/// This node will recursively derive from the next bit-field in the set of
/// fields that are held in this single value. The first bit-field will therefore
/// be at the bottom of the derived chain, and the last element will be the 
/// class node closest to the base.
///
template  < typename  RootT,
            size_t    IndexT,
            size_t    OffsetT,
            typename  SeqT
          >
struct BitFieldNode
  : BitFieldNode< RootT, 
                  IndexT+1, 
                  OffsetT+Front<SeqT>::value,
                  typename GetTail<SeqT>::type
                >
{
  //  Typedef *******************************************************************
  typedef typename GetTail<SeqT>::type                    tail_type;

  typedef BitFieldNode< RootT, 
                        IndexT+1, 
                        OffsetT+Front<SeqT>::value,
                        tail_type
                      >                                   base_type;
    
  typedef typename RootT::value_type                      value_type;

  //  Construction ***************************************************************
  //  ****************************************************************************
  /// Default Constructor.
  /// 
  BitFieldNode()
    : base_type()
    , m_field( RootT::GetFieldAddress(m_field) )
  { 
    // TODO: This is the default constructor, revisit and determine if there is a location to attach memory from.
    //m_field.attach((value_type*)&rhs.m_field);
  }

  //  ****************************************************************************
  /// Copy constructor for this type of node.
  /// This is important because it provides a location that contains the 
  /// actual integer-type value this field is stored within.
  ///
  BitFieldNode(const BitFieldNode &rhs)
    : base_type(rhs)
    , m_field( RootT::GetFieldAddress(m_field) )
  {
    // The assignment in the constructor assigns the reference of
    // data_field to the data member, m_field.
    // 
    m_field.attach((value_type*)&rhs.m_field);
  }

  //  ****************************************************************************
  /// Value constructor 
  /// This is important because it provides a location that contains the 
  /// actual integer-type value this field is stored within.
  ///
  BitFieldNode(value_type &data_field)
    : base_type(data_field)
    , m_field(RootT::GetFieldAddress(m_field))
  {
    // The assignment in the constructor assigns the reference of
    // data_field to the data member, m_data.
    // 
    m_field.attach(&data_field);
  }

private:
  //  Data Members ***************************************************************
  BitField<Hg::MT, Hg::MT,  OffsetT, Front<SeqT>::value, value_type>            &m_field;
};

//  ****************************************************************************
/// Terminating Node for a BitFieldList
///
template  < typename  RootT,
            size_t    IndexT,
            size_t    OffsetT
          >
struct BitFieldNode< RootT, IndexT, OffsetT, MT>
  : public RootT
{
  //  Typedefs *******************************************************************
  typedef typename RootT::value_type              value_type;

  //  Construction ***************************************************************
  //  ****************************************************************************
  BitFieldNode(const BitFieldNode &rhs)
    : RootT(rhs)
  { }

  //  ****************************************************************************
  BitFieldNode(value_type &data_field)
    : RootT(data_field)
  { }

protected:

  //  ****************************************************************************
  /// A parameterized method that allows the BitList heirarchy to pragmatically
  /// access the different bit-fields defined in the list without knowledge of
  /// the name of the field.
  ///
  template <size_t    Idx,
            typename  field_t>
  field_t& GetFieldAddress(const field_t&)
  {
    // Create this typedef, to simplify the overly complex statement below.
    typedef FieldIndex< Idx, RootT, field_t::k_size> field_index_t;

    // This syntax is calling a template member function "GetField" found 
    // in the base class "RootT".
    // 
    // The template keyword lets the compiler know this is a template,
    // rather than a < sign:
    //    "this->GetField <" 
    // 
    // The static_cast from this to a type "RootT" is required in order to 
    // give a hint to the compiler where to look for the "GetField" function.
    //
    return 
      static_cast<RootT*>(this)->template 
                                 GetField<field_index_t>(field_t());
  }
};

//  ****************************************************************************
/// The BitList manages a sequence of bit fields.
/// Parameterized access to these fields is provided in a controlled manner.
///
template  < typename RootT,
            typename SeqT
          >
struct BitFieldList
//  : public BitFieldNode< RootT, 0, 0, SeqT >
  : public RootT
{
  //  Typedefs *****************************************************************
  typedef typename RootT::value_type                      value_type;
  //typedef BitFieldNode< RootT, 0, 0, SeqT >               base_type;
  typedef RootT                                           base_type;

  //  Constants ****************************************************************
  static 
    const size_t k_size  = sizeof(value_type);

  //  Construction *************************************************************

  //  **************************************************************************
  /// Default constructor
  /// Typically used for temporary instances. 
  BitFieldList()
    : base_type()
  { 
    RootT::m_data = 0;
  }

  //  **************************************************************************
  /// Const Value constructor, 
  /// Typically used for temporary instances. 
  /// This call will use internal memory to store values.
  ///
  BitFieldList(const value_type &data_field)
    : base_type()
  { 
    RootT::value(data_field);
  }

  //  **************************************************************************
  /// Value constructor.
  ///
  BitFieldList(value_type &data_field)
    : base_type(data_field)
  {
  }

  //  **************************************************************************
  /// Value conversion operator allows the entire integer to be extracted.
  ///
  operator value_type() const
  {
    return RootT::value();
  }

  //  **************************************************************************
  /// Assignment operator, changes the value but does not change the storage address.
  ///
  BitFieldList& operator=(const BitFieldList &rhs)
  {
    RootT::value(rhs.value());
    return *this;
  }

  //  **************************************************************************
  /// Assignment operator, changes the value but does not change the storage address.
  ///
  value_type& operator=(const value_type &rhs)
  {
    RootT::value(rhs);
    return RootT::value();
  }

  //  Methods *******************************************************************
  //  ***************************************************************************
  /// Returns the size of the base integer type used in the bit list.
  ///
  static
  size_t size()
  {
    return k_size;
  }
};

//  ****************************************************************************
/// Type-trait class that contains common definitions used by every bit-list.
/// This class is also used to conveniently define a bit-list type from a
/// generic type-list format.
///             
template< typename  base_type>
struct DeclareBitFieldList
{
  typedef base_type                     base_t;

  typedef BitFieldList
                < base_t,
                  integer_sequence
                  < base_t::idx_0::k_size,
                    base_t::idx_1::k_size,
                    base_t::idx_2::k_size,
                    base_t::idx_3::k_size,
                    base_t::idx_4::k_size,
                    base_t::idx_5::k_size,
                    base_t::idx_6::k_size,
                    base_t::idx_7::k_size,
                    base_t::idx_8::k_size,
                    base_t::idx_9::k_size,
                    base_t::idx_10::k_size,
                    base_t::idx_11::k_size,
                    base_t::idx_12::k_size,
                    base_t::idx_13::k_size,
                    base_t::idx_14::k_size,
                    base_t::idx_15::k_size,
                    base_t::idx_16::k_size,
                    base_t::idx_17::k_size,
                    base_t::idx_18::k_size,
                    base_t::idx_19::k_size,
                    base_t::idx_20::k_size,
                    base_t::idx_21::k_size,
                    base_t::idx_22::k_size,
                    base_t::idx_23::k_size,
                    base_t::idx_24::k_size,
                    base_t::idx_25::k_size,
                    base_t::idx_26::k_size,
                    base_t::idx_27::k_size,
                    base_t::idx_28::k_size,
                    base_t::idx_29::k_size,
                    base_t::idx_30::k_size,
                    base_t::idx_31::k_size
                  >
                >                       type;
};


//  ****************************************************************************
/// Type-trait class that contains common definitions used by every bit-list.
/// This class is also used to conveniently define a bit-list type from a
/// generic type-list format.
///             
template< size_t    Idx,
          typename  format_type
        >
struct DeduceBitFieldList
{
  typedef 
    typename TypeAt < Idx,
                      format_type
                    >::type                   base_t;

  typedef typename
    DeclareBitFieldList<base_t>::type         type;
};

} // namespace Hg


#endif
