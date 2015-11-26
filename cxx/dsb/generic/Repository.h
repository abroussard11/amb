/**
 * dsb/Repository.h
 */

#ifndef DSB_REPOSITORY_H_
#define DSB_REPOSITORY_H_

#include <fstream>

namespace dsb {

class Repository
{
public:
   const std::string HEAD;

   Repository();
   virtual ~Repository() = default;

   bool isValid();
   void initialize();
   void setHead(std::string headName);
   std::string getHead();

private:
   bool _isValid;
   std::string _headProjName;
};

} // End namespace dsb

#endif // DSB_REPOSITORY_H_
