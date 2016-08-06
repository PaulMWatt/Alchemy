/// @file bitmap.h
/// 
/// Data object to manipulate the data of a bitmap image structure.
///
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef BITMAP_H_INCLUDED
#define BITMAP_H_INCLUDED
// Includes ********************************************************************
#include <Hg.h>
#include <Hg/static_storage_policy.h>
#include <string>

//  ****************************************************************************
ALCHEMY_STRUCT(bitmap_file_header_t,
  ALCHEMY_DATUM(uint16_t, type),
  ALCHEMY_DATUM(uint32_t, length),
  ALCHEMY_DATUM(uint16_t, reserved_1),
  ALCHEMY_DATUM(uint16_t, reserved_2),
  ALCHEMY_DATUM(uint32_t, offset) 
)


//  ****************************************************************************
ALCHEMY_STRUCT(bitmap_core_header_t,
  ALCHEMY_DATUM(uint32_t, size),
  ALCHEMY_DATUM(uint16_t, width),
  ALCHEMY_DATUM(uint16_t, height),
  ALCHEMY_DATUM(uint16_t, planes),
  ALCHEMY_DATUM(uint16_t, bit_depth) 
)

//  ****************************************************************************
ALCHEMY_STRUCT(bitmap_info_header_t,
  ALCHEMY_DATUM(uint32_t, size),
  ALCHEMY_DATUM(int32_t,  width),
  ALCHEMY_DATUM(int32_t,  height),
  ALCHEMY_DATUM(uint16_t, planes),
  ALCHEMY_DATUM(uint16_t, bit_depth),
  ALCHEMY_DATUM(uint32_t, compression),
  ALCHEMY_DATUM(uint32_t, sizeImage),
  ALCHEMY_DATUM(int32_t,  x_pixels_per_meter),
  ALCHEMY_DATUM(int32_t,  y_pixels_per_meter),
  ALCHEMY_DATUM(uint32_t, color_count),
  ALCHEMY_DATUM(uint32_t, important_color) 
)

ALCHEMY_STRUCT(rgba_t,
  ALCHEMY_DATUM(byte_t, blue),
  ALCHEMY_DATUM(byte_t, green),
  ALCHEMY_DATUM(byte_t, red),
  ALCHEMY_DATUM(byte_t, alpha) 
)

ALCHEMY_STRUCT(bitmap_info_t,
  ALCHEMY_DATUM(bitmap_info_header_t, header),
  ALCHEMY_ALLOC(byte_t, header.sizeImage, pixels) 
)



namespace sgraph
{

namespace detail
{
typedef Hg::basic_msg<Hg::bitmap_file_header_t, 
                      Hg::BufferedStaticStoragePolicy>      hg_file_t;

typedef Hg::basic_msg<Hg::bitmap_info_t, 
                      Hg::BufferedStaticStoragePolicy>      hg_info_t;
}

typedef Hg::Message< detail::hg_file_t>   file_t;
typedef Hg::Message< detail::hg_info_t>   info_t;
                       


typedef void (*pixel_ftor) ( Hg::rgba_t&  pixel,
                             Hg::byte_t&  data);


class Bitmap
{
public:

  bool Load (const std::string &name);
  bool Store(const std::string &name);

  void process( std::string &msg,
                pixel_ftor   ftor);

private:
  // Currently assuming the bitmap is of the form
  // using the bitmap_info format, 40 bytes.

  std::string   m_file_name;

  file_t        m_file_header;
  info_t        m_info;


};


} // namespace sgraph



#endif

