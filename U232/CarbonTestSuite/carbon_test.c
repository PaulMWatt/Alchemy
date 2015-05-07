/** @file carbon_test.c
 * 
 *  C-source file for testing Carbon generated definitions.
 *  
 *  The MIT License(MIT)
 *  
 *  @copyright 2014 Paul M Watt
 *  
 */
#include <Carbon.h>
#include <CarbonTestDefs.h>

#define LEAN_AND_MEAN
#include <Windows.h>



void function()
{
  HMODULE hLib = LoadLibrary("CarbonTestLibrary.dll");

  pfn_Hg_local_endianess p_local = (pfn_Hg_local_endianess)GetProcAddress(hLib, "Hg_local_endianess");

  int e = p_local();

  //int e = Hg_local_endianess();

//  Hg_msg_t* p_msg = Hg_create(k_ray_t_id);




  FreeLibrary(hLib);
}


