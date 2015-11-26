/**
 * amb/Xml.h
 */

#ifndef AMB_XML_H_
#define AMB_XML_H_

#include <iostream>
#include <sstream>
#include <vector>
#include <amb/xml/Node.h>

namespace amb {

class Xml
{
public:
   xml::Node node;

   Xml() = default;
   Xml(const std::string& fileName);
   virtual ~Xml() = default;

   void loadString(const std::string& xmlStr);
   void loadFile(const std::string& fileName);

   String getElement(std::string tagName);
   std::vector<xml::Node> getElements(std::string tagName);

private:
   std::string preprocessText(std::istream& ifs);
   void parseData(const std::string& xmlStr);
};

} // End namespace amb

#endif // AMB_XML_H_
