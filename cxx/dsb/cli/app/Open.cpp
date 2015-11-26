/**
 * dsb/cli/app/Open.cpp
 */

#include <dsb/cli/app/Open.h>

namespace dsb {
namespace cli {

void Open::processCmd(ProjectFile& proj, Util::CommandLine::Data& cmdLine)
{
   Repository repo;
   if (repo.isValid())
   {
      std::cout << "commanded open" << std::endl;
      auto newFile = cmdLine.at(0).values.at(0);
      std::ifstream ifs(newFile, std::ifstream::in);
      if (ifs.is_open())
      {
         // file exists
         // write filename to HEAD
         repo.setHead(newFile);

      }
      else
      {
         // file does not exist
         // initialize an empty file?
         ifs.close();
         std::ofstream ofs(newFile, std::ofstream::out);
         if (ofs.is_open())
         {
            repo.setHead(newFile);
         }
         else
         {
            // couldn't create the file
         }
         ofs.close();
      }
   }
   else
   {
      std::cout << "Repo not valid" << std::endl;
   }
}

} // End namespace cli
} // End namespace dsb
