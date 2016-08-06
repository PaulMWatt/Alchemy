
#include "stdafx.h"
#include <iostream>
#include <array>
#include <string>
#include <vector>

#include "Number.h"
#include "parser.h"

using namespace std;


//  ****************************************************************************
int _tmain(int argc, _TCHAR* argv[])
{
  parser::Parser p;
  std::string    input;

  std::cout << "Enter a number: ";
  std::cin  >> input;

  bool isValid = p.parse(input.c_str(), input.length());

  std::cout << "\n\nThe input: " << input << " is " << (isValid ? "valid" : "invalid") << std::endl;

  return 0;
}
