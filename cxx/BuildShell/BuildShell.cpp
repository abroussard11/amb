/**
 * BuildShell.cpp
 */

#include <iostream>

int main(int argc, char** argv)
{
   std::cout << "BuildShell:";
   for (int i = 0; i < argc; ++i)
   {
      std::cout << " " << argv[i];
   }
   std::cout << std::endl;

   return 0;
}

