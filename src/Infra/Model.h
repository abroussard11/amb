/**
 * The Model Interface
 */

#include <string>

namespace Infra {

class Model
{
public:
   Model();
   virtual ~Model();

   virtual void run() = 0;
   virtual std::string getName();
   virtual void setName(std::string name);

private:
   std::string _name;
};

} // End namespace Infra
