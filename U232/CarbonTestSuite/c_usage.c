/** @file c_usage.c
 * 
 *  C-source file for demonstrating Carbon API usage.
 *  
 *  The MIT License(MIT)
 *  
 *  @copyright 2015 Paul M Watt
 *  
 */
#include <c_usage.h>

// Function pointers for interfacing 
// with Carbon APIs through a DLL.
pfn_Hg_local_endianess   g_pfnHg_local_endianess = 0;
pfn_Hg_create            g_pfnHg_create          = 0;
pfn_Hg_destroy           g_pfnHg_destroy         = 0;
pfn_Hg_type              g_pfnHg_type            = 0;
pfn_Hg_size              g_pfnHg_size            = 0;
pfn_Hg_data_size         g_pfnHg_data_size       = 0;
pfn_Hg_to_network        g_pfnHg_to_network      = 0;
pfn_Hg_to_host           g_pfnHg_to_host         = 0;
pfn_Hg_to_big_end        g_pfnHg_to_big_end      = 0;
pfn_Hg_to_little_end     g_pfnHg_to_little_end   = 0;
pfn_Hg_pack              g_pfnHg_pack            = 0;
pfn_Hg_unpack            g_pfnHg_unpack          = 0;


HMODULE setup_library()
{
  HMODULE hLib = LoadLibrary("CarbonTestLibrary.dll");

  g_pfnHg_local_endianess = (pfn_Hg_local_endianess)GetProcAddress(hLib, "Hg_local_endianess");
  g_pfnHg_create          = (pfn_Hg_create)         GetProcAddress(hLib, "Hg_create");
  g_pfnHg_destroy         = (pfn_Hg_destroy)        GetProcAddress(hLib, "Hg_destroy");
  g_pfnHg_type            = (pfn_Hg_type)           GetProcAddress(hLib, "Hg_type");
  g_pfnHg_size            = (pfn_Hg_size)           GetProcAddress(hLib, "Hg_size");
  g_pfnHg_data_size       = (pfn_Hg_data_size)      GetProcAddress(hLib, "Hg_data_size");
  g_pfnHg_to_network      = (pfn_Hg_to_network)     GetProcAddress(hLib, "Hg_to_network");
  g_pfnHg_to_host         = (pfn_Hg_to_host)        GetProcAddress(hLib, "Hg_to_host");
  g_pfnHg_to_big_end      = (pfn_Hg_to_big_end)     GetProcAddress(hLib, "Hg_to_big_end");
  g_pfnHg_to_little_end   = (pfn_Hg_to_little_end)  GetProcAddress(hLib, "Hg_to_little_end");
  g_pfnHg_pack            = (pfn_Hg_pack)           GetProcAddress(hLib, "Hg_pack");
  g_pfnHg_unpack          = (pfn_Hg_unpack)         GetProcAddress(hLib, "Hg_unpack");

  return hLib;
}

void teardown_library(HMODULE hLib)
{
  g_pfnHg_local_endianess = 0;
  g_pfnHg_create          = 0;
  g_pfnHg_destroy         = 0;
  g_pfnHg_type            = 0;
  g_pfnHg_size            = 0;
  g_pfnHg_data_size       = 0;
  g_pfnHg_to_network      = 0;
  g_pfnHg_to_host         = 0;
  g_pfnHg_to_big_end      = 0;
  g_pfnHg_to_little_end   = 0;
  g_pfnHg_pack            = 0;
  g_pfnHg_unpack          = 0;

  FreeLibrary(hLib);
}

void function()
{
  //uint32_t a = k_camera_t;
  //uint32_t b = k_ray_t;

  int e = g_pfnHg_local_endianess();

}


