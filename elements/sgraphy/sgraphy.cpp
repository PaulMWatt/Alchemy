/// @file sgraphy.cpp 
///
/// Defines the entry point for the console application.
///
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#include "sgraphy.h"
#include "bitmap.h"


//  ****************************************************************************
void weave_data ( Hg::rgba_t_HgFormat&  pixel,
                  const Hg::byte_t      data)
{
  using Hg::s_data;

  // The lower two bits of the data byte.
  const Hg::byte_t k_data_mask = 0x03;

  s_data value(data);
  
  pixel.blue  = (pixel.blue  & ~k_data_mask)
              | (value.d0    &  k_data_mask);
  pixel.green = (pixel.green & ~k_data_mask)
              | (value.d1    &  k_data_mask);
  pixel.red   = (pixel.red   & ~k_data_mask)
              | (value.d2    &  k_data_mask);
  pixel.alpha = (pixel.alpha & ~k_data_mask)
              | (value.d3    &  k_data_mask);
}


char secret_message[] = "Hello World!";




int main(int argc, char* argv[])
{
  sgraph::Bitmap bmp;

  bmp.Load("C:\\users\\paul\\desktop\\house.bmp");



  // Process the bitmap...
  bmp.process(secret_message, weave_data);

  bmp.Store("C:\\users\\paul\\desktop\\copy.bmp");
  
	return 0;
}

