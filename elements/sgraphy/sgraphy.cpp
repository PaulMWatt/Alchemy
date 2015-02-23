// sgraphy.cpp : Defines the entry point for the console application.
//

#include "bitmap.h"



int main(int argc, char* argv[])
{
  sgraph::Bitmap bmp;

  bmp.Load("C:\\users\\paul\\desktop\\house.bmp");
  bmp.Store("C:\\users\\paul\\desktop\\copy.bmp");
  
	return 0;
}

