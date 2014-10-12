/**
 * The Fish Model
 */

#include <Infra/Model.h>
#include <FishGroup/Fish.h>

namespace Models {

class FishModel
{
public:
   FishModel();
   virtual ~FishModel();

   virtual void run();
   virtual void update();

   virtual void displayPrompt();

private:
   bool _quit;
   std::string _selection;
   FishGroup::Fish* _fishy;
};

} // End namespace Models
