/**
 * The Fish Model
 */

#include <Models/FishModel.h>

namespace Models {

FishModel::FishModel() :
   _quit(false), //
   _selection(0), //
   _fishy(new FishGroup::Fish())
{
   setName("Fish Model");
}

FishModel::~FishModel()
{
   // Empty
}

void FishModel::run()
{
   displayPrompt();
   while (!_quit)
   {
      update();
      std::cout << _fishy->swim() << std::endl << std::endl;
      displayPrompt();
   }
}

void FishModel::update()
{
   delete _fishy;

   if (_selection == "1")
   {
      _fishy = new FishGroup::Fish();
   }
   else
   {
      std::cout << "Invalid selection. Choosing the default dinner." << std::endl;
      _fishy = new FishGroup::Fish();
   }

}

void FishModel::displayPrompt()
{
   std::cout << "Choose your dinner:" << std::endl;
   std::cout << "\t1: Fishy" << std::endl
             << "\tQ: quit" << std::endl;
   std::cin >> _selection;

   if (_selection == "Q" || _selection == "q")
      _quit == true;
}

} // End namespace Models
