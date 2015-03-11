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

  std::ifstream input(m_file_name, std::ios::binary);
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

  return true;
}




void Bitmap::process( const std::string &msg,
                      pixel_ftor         ftor)
{
  auto t = Hg::make_view<Hg::rgba_t_HgFormat>(m_info.pixels.get());

  auto iter = t.begin();
  size_t index = 0;
  size_t length= msg.length();

  for (index = 0; iter != t.end(); ++iter, ++index)
  {
    ftor(*iter, msg[index % length]);
  }
}



bool Bitmap::Store (const std::string &name)
{
  std::ofstream output(name, std::ios::binary);
  if (output.bad())
  {
    return false;
  }

  output << m_file_header;
  output << m_info;

  return true;
}




} // namespace sgraph

