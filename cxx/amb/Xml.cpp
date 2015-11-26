/**
 * amb/Xml.cpp
 */

// #include <unistd.h>
#include <fstream>
#include <amb/Xml.h>
#include <Util/Log.h>

namespace amb {

Xml::Xml(const std::string& fileName)
{
   loadFile(fileName);
}

void Xml::loadString(const std::string& xmlStr)
{
   std::istringstream iss(xmlStr);
   parseData(preprocessText(iss));
}

void Xml::loadFile(const std::string& fileName)
{
   std::ifstream ifs(fileName);
   if (ifs.good())
   {
      auto cleanStr = preprocessText(ifs);
      parseData(cleanStr);
   }
   else
   {
      Util::Log::error("Error opening the file");
   }
}

String Xml::getElement(std::string tagName)
{
   return node.getElement(tagName);
}

std::vector<xml::Node> Xml::getElements(std::string tagName)
{
   return node.getElements(tagName);
}

std::string Xml::preprocessText(std::istream& ifs)
{
   // Remove leading and trailing whitespace
   std::stringstream ssout;
   std::string s;
   while (getline(ifs, s))
   {
      auto posL = s.find_first_not_of(' ');
      auto posR = s.find_last_not_of(" \n");
      if (posL == std::string::npos)
      {
         ssout << "";
      }
      else
      {
         ssout << s.substr(posL, posR - posL + 1);
      }
   }

   // Remove comments
   auto cleanStr = ssout.str();
   auto retStr = std::string{""};

   // std::cout << "cleanStr = " << cleanStr << std::endl;

   auto commentL = cleanStr.find("<!--");
   auto commentR = std::size_t{0};

   // std::cout << "preprocessText:" << std::endl;
   // std::cout << "commentL = " << commentL << std::endl;
   while (commentL != std::string::npos)
   {
      retStr += cleanStr.substr(commentR, commentL - commentR);
      commentR = cleanStr.find("-->", commentL) + 3;
      commentL = cleanStr.find("<!--", commentR);
      // std::cout << "preprocessText:" << std::endl;
      // std::cout << "commentL = " << commentL << std::endl;
   }
   retStr += cleanStr.substr(commentR, std::string::npos);

   return retStr;
}

void Xml::parseData(const std::string& xmlStr)
{
   node = xml::Node(xmlStr);
}

} // End namespace amb
