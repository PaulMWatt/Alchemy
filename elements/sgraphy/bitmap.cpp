/// @file bitmap.cpp
/// 
/// Data object to manipulate the data of a bitmap image structure.
///
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
// Includes ********************************************************************
#include "bitmap.h"
#include <fstream>


namespace sgraph
{


bool Bitmap::Load (const std::string &name)
{
  m_file_name = name;

  std::ifstream input(m_file_name);
  if (input.bad())
  {
    return false;
  }

  input >> m_file_header;


  if ( m_file_header.offset != (size_t)0x36)
  {
    return false;
  }

  input >> m_info;

  auto t = m_info.pixels.make_view<Hg::rgba_t_HgFormat>();

  return true;
}



bool Bitmap::Store (const std::string &name)
{
  m_file_name = name;

  std::ofstream output(m_file_name);
  if (output.bad())
  {
    return false;
  }

  output << m_file_header;
  output << m_info;

  return true;
}




} // namespace sgraph

