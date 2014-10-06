#include <iostream>
#include "Fish.h"

namespace FishGroup {

Fish::Fish()
{
   // Empty
}

Fish::~Fish()
{
   //Empty
}

void Fish::swim()
{
   std::cout << "Fish swims!" << std::endl;
}

} // End namespace Fish
