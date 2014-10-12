#include <iostream>
#include <FishGroup/Fish.h>

int main()
{
   std::cout << "Hello World!" << std::endl;
   FishGroup::Fish myFish;
   myFish.swim();

   std::vector<Infra::Model*> actions;

   actions.push_back(new Models::Fishy())

   std::cout << "Select an action to run:" << std::endl;
   for (auto& action : actions)
   {

   }
}
