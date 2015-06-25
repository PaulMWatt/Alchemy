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


//  ****************************************************************************
namespace sgraph
{

//  ****************************************************************************
bool Bitmap::Load (const std::string &name)
{
  m_file_name = name;

  std::ifstream input(m_file_name, std::ios::binary);
  if (input.bad())
  {
    return false;
  }

  input >> m_file_header;


  if ((size_t)0x36 != m_file_header.offset)
  {
    return false;
  }


  size_t s = m_info.size();

  //input >> m_info;

  return true;
}

//  ****************************************************************************
void Bitmap::process( std::string &msg,
                      pixel_ftor   ftor)
{
  auto t    = Hg::make_view<Hg::rgba_t>(m_info.pixels.get());
  auto iter = t.begin();

  // Calculate the number of bytes that can be encoded or extracted
  // from the image and ensure the the message buffer is large enough.
  size_t length = t.end() - iter;
  msg.resize(length);

  for (size_t index = 0; iter != t.end(); ++iter, ++index)
  {
    ftor(*iter, (Hg::byte_t&)(msg[index]));
  }
}

//  ****************************************************************************
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

