/// @file Bi/detail/N_functions.cpp
/// 
/// Large number theory functions.
///             
/// The MIT License(MIT)
/// @copyright 2016 Paul M Watt
//  ****************************************************************************
#include <Bi/N_functions.h>
#include <Bi/Z.h>
#include <Bi/Z_operators.h>

#include <cmath>
#include <vector>

typedef uint64_t                        z_base;
typedef std::vector<z_base>             z_type;



namespace Bi
{

//  ****************************************************************************
//  This implementation uses Newton-Raphson iteration to create an integer
//  reciprocal to the required accuracy.
//
Z reciprocal(const Z& value)
{
  Z ret_val;



  return ret_val;
}



//  ****************************************************************************
uint64_t reciprocal(const uint64_t& value)
{

  uint64_t result = 1;

  return result;
}





} // namespace Bi
