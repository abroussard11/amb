/**
 * The Model Interface
 */

#include <Infra/Model.h>

namespace Infra {

Model::Model() :
   _name("")
{
   // Empty
}

Model::~Model()
{
   // Empty
}

std::string Model::getName()
{
   return _name;
}

void Model::setName(std::string name)
{
   _name = name;
}

} // End namespace Infra
