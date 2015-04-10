/// @file sgraphy.cpp 
///
/// Defines the entry point for the console application.
///
/// This simple stenography application demonstrates how data can be 
/// manipulated with the alchemy message formatting library.
///
/// The program can encode an ascii text message within a bitmap, as well
/// as extract the message from a bitmap with an encoded message.
///
/// - The input bitmap must use a 32-bit per pixel encoding.
/// - The application can encode 1-byte per pixel
/// - If the secret message exceeds the limits of the image, it will be truncated.
/// - The output message extracted from an image may contain extra spaces
///   if the original message did not use the entire space available in the image.
///
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#include "sgraphy.h"
#include "bitmap.h"
#include <iostream>
#include <fstream>
#include <sstream>

using std::cout;
using std::endl;
using std::string;
using std::stringstream;


//  Global Varibles ************************************************************

bool   is_encode      = false;
string msg_file       = "msg.txt";
string input_file     = "source.bmp";
string output_file    = "target.bmp";

//  ****************************************************************************
bool ParseCmdParams(int argc, char* argv[])
{
  // The second parameter must be the command switch
  if (4 == argc)
  {
    if (0 != strcmp("-d", argv[1]))
    {
      return false;
    }

    input_file = argv[2];
    output_file= argv[3];
  }
  else if (5 == argc)
  {
    if (0 != strcmp("-e", argv[1]))
    {
      return false;
    }
 
    is_encode  = true;
    msg_file   = argv[2];
    input_file = argv[3];
    output_file= argv[4];
  }
  else
  {
    return false;
  }

  return true;
}

//  ****************************************************************************
void PrintHelp()
{
  cout << "\nUsage: sgraphy [-e message_path] [-d] input output\n\n"
       << "Options:\n"
       << "    -e\t\tEncodes the specified message_path into the input file\n"
       << "    -d\t\tDecodes an embedded message from input, and stores in output\n"
       << "\n"
       << "    -e and -d are mutually exclusive.\n\n";
}

//  ****************************************************************************
string ReadFile(const string& path)
{
  std::ifstream input_file(path);

  stringstream  data;
  data << input_file.rdbuf();

  return data.str();
}

//  ****************************************************************************
void WriteFile( const string& path, 
                const string& data)
{
  std::ofstream output_file(path);
  output_file << data;
}

//  ****************************************************************************
void weave_data ( Hg::rgba_t&  pixel,
                  Hg::byte_t&  data)
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

//  ****************************************************************************
void extract_data ( Hg::rgba_t&  pixel,
                    Hg::byte_t&  data)
{
  using Hg::s_data;

  // The lower two bits of the data byte.
  const Hg::byte_t k_data_mask = 0x03;

  s_data value;
  
  value.d0  = (pixel.blue  & k_data_mask);
  value.d1  = (pixel.green & k_data_mask);
  value.d2  = (pixel.red   & k_data_mask);
  value.d3  = (pixel.alpha & k_data_mask);

  data = value;
}

//  ****************************************************************************
int main(int argc, char* argv[])
{
  if (!ParseCmdParams(argc, argv))
  {
    PrintHelp();
    return 0;
  }

  string message = ReadFile(msg_file);

  sgraph::Bitmap bmp;
  bmp.Load(input_file);

  if (is_encode)
  {
    bmp.process(message, weave_data);
    bmp.Store(output_file);
  }
  else
  {
    bmp.process(message, extract_data);
    WriteFile(output_file, message);
  }
  
	return 0;
}
