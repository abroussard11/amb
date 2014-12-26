/*
 * Problem01.cpp
 *
 */

#include <string>
#include <sstream>
#include <Minigames/ProjectEuler/problems/Problem01.h>

namespace Minigames {
namespace ProjectEuler {

Problem01::Problem01()
{
   // Empty
}

Problem01::~Problem01()
{
   // Empty
}

std::string Problem01::getText()
{
   std::string text("If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9."
                            "The sum of these multiples is 23. \nFind the sum of all the multiples of 3 or 5 below 1000.");

   return text;
}

std::string Problem01::getSolution()
{
   int total = 0;
   for (auto x=1; x < 1000; x++)
   {
      if (x%3 == 0 || x%5 == 0)
      {
         total += x;
      }
   }

   std::stringstream ss;
   ss << "The sum is: " << total;

   return ss.str();
}

} /* namespace ProjectEuler */
} /* namespace Minigames */
