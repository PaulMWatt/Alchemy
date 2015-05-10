/*  @file c_usage.h
  
    C-source file for demonstrating Carbon API usage.
   
    The MIT License(MIT)
    
    @copyright 2015 Paul M Watt  
 */
#ifndef C_USAGE_H_INCLUDED
#define C_USAGE_H_INCLUDED
/*  Includes ******************************************************************/
#define LEAN_AND_MEAN
#include <Windows.h>

#include <Carbon.h>
#include <CarbonTestDefs.h>

#ifdef __cplusplus
extern "C"
{
#endif

extern pfn_Hg_local_endianess   g_pfnHg_local_endianess;
extern pfn_Hg_create            g_pfnHg_create;
extern pfn_Hg_destroy           g_pfnHg_destroy;
extern pfn_Hg_type              g_pfnHg_type;
extern pfn_Hg_size              g_pfnHg_size;
extern pfn_Hg_data_size         g_pfnHg_data_size;
extern pfn_Hg_to_network        g_pfnHg_to_network;
extern pfn_Hg_to_host           g_pfnHg_to_host;
extern pfn_Hg_to_big_end        g_pfnHg_to_big_end;
extern pfn_Hg_to_little_end     g_pfnHg_to_little_end;
extern pfn_Hg_pack              g_pfnHg_pack;
extern pfn_Hg_unpack            g_pfnHg_unpack;

HMODULE setup_library();
void    teardown_library(HMODULE hLib);
void    function();


#ifdef __cplusplus
}
#endif



#endif
