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


namespace Hg
{

//  ****************************************************************************
typedef 
  TypeList
  <
    uint16_t,
    uint32_t,
    uint16_t,
    uint16_t,
    uint32_t
  > bitmap_file_header_t;

HG_BEGIN_FORMAT(bitmap_file_header_t)
  HG_DATUM(uint16_t, type)
  HG_DATUM(uint32_t, length)
  HG_DATUM(uint16_t, reserved_1)
  HG_DATUM(uint16_t, reserved_2)
  HG_DATUM(uint32_t, offset)
HG_END_FORMAT(bitmap_file_header_t)


//  ****************************************************************************
typedef 
  TypeList
  <
    uint32_t,
    uint16_t,
    uint16_t,
    uint16_t,
    uint16_t
  > bitmap_core_header_t;

HG_BEGIN_FORMAT(bitmap_core_header_t)
  HG_DATUM(uint32_t, size)
  HG_DATUM(uint16_t, width)
  HG_DATUM(uint16_t, height)
  HG_DATUM(uint16_t, planes)
  HG_DATUM(uint16_t, bit_depth)
HG_END_FORMAT(bitmap_core_header_t)


typedef 
  TypeList
  <
    byte_t,
    byte_t,
    byte_t
  > rgb_t;

HG_BEGIN_FORMAT(rgb_t)
  HG_DATUM(byte_t, blue)
  HG_DATUM(byte_t, green)
  HG_DATUM(byte_t, red)
HG_END_FORMAT(rgb_t)


typedef 
  TypeList
  <
    bitmap_core_header_t,
    rgb_t
  > core_info_t;

HG_BEGIN_FORMAT(core_info_t)
  HG_DATUM(bitmap_core_header_t, header)
  HG_DYNAMIC(byte_t, get_core_pixel_size, pixels)
HG_END_FORMAT(core_info_t)


//  ****************************************************************************

typedef 
  TypeList
  <
    uint32_t,
    int32_t,
    int32_t,
    uint16_t,
    uint16_t,
    uint32_t,
    uint32_t,
    int32_t,
    int32_t,
    uint32_t,
    uint32_t
  > bitmap_info_header_t;

HG_BEGIN_FORMAT(bitmap_info_header_t)
  HG_DATUM(uint32_t, size)
  HG_DATUM(int32_t,  width)
  HG_DATUM(int32_t,  height)
  HG_DATUM(uint16_t, planes)
  HG_DATUM(uint16_t, bit_depth)
  HG_DATUM(uint32_t, compression)
  HG_DATUM(uint32_t, sizeImage)
  HG_DATUM(int32_t,  x_pixels_per_meter)
  HG_DATUM(int32_t,  y_pixels_per_meter)
  HG_DATUM(uint32_t, color_count)
  HG_DATUM(uint32_t, important_color)
HG_END_FORMAT(bitmap_info_header_t)


typedef 
  TypeList
  <
    byte_t,
    byte_t,
    byte_t,
    byte_t
  > rgba_t;

HG_BEGIN_FORMAT(rgba_t)
  HG_DATUM(byte_t, blue)
  HG_DATUM(byte_t, green)
  HG_DATUM(byte_t, red)
  HG_DATUM(byte_t, alpha)
HG_END_FORMAT(rgba_t)


typedef 
  TypeList
  <
    bitmap_info_header_t,
    std::vector<byte_t>
  > bitmap_info_t;

HG_BEGIN_FORMAT(bitmap_info_t)
  HG_DATUM(bitmap_core_header_t, header)
  HG_DYNAMIC(byte_t, header.sizeImage, pixels)
HG_END_FORMAT(bitmap_info_t)


} // namespace Hg



namespace sgraph
{

typedef Hg::Message<Hg::bitmap_file_header_t_HgFormat, 
                    Hg::LittleEndian, 
                    Hg::BufferedStaticStoragePolicy>    file_t;

typedef Hg::Message<Hg::core_info_t_HgFormat, 
                    Hg::LittleEndian, 
                    Hg::BufferedStaticStoragePolicy>    core_t;

typedef Hg::Message<Hg::bitmap_info_t_HgFormat, 
                    Hg::LittleEndian, 
                    Hg::BufferedStaticStoragePolicy>    info_t;


typedef void (*pixel_ftor) ( Hg::rgba_t_HgFormat&  pixel,
                             Hg::byte_t&           data);


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

