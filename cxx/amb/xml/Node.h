/**
 * amb/xml/Node.h
 */

#ifndef AMB_XML_NODE_H_
#define AMB_XML_NODE_H_

#include <string>
#include <vector>
#include <amb/String.h>

namespace amb {
namespace xml {

class Node {
 public:
  std::string root;
  String text;
  std::vector<xml::Node> children;

  Node(std::string* xmlStr);
  Node(std::string xmlStr);
  Node() = default;
  virtual ~Node() = default;

  String getElement(std::string tagName);
  std::vector<xml::Node> getElements(std::string tagName);

  std::string setRoot(const std::string& str);
  std::string setText(const std::string& str);
  std::string setChildren(std::string str);

  void addChild(const std::string xml);
  bool isRootCloseTag(const std::string& str);
  bool validateXml(const std::string* xmlStr);
};

}  // End namespace amb
}  // End namespace xml

#endif  // AMB_XML_NODE_H_
