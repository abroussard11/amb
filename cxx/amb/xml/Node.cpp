/**
 * amb/xml/Node.cpp
 */

// #include <unistd.h>
#include <iostream>
#include <amb/xml/Node.h>
#include <Util/Log.h>

namespace amb {
namespace xml {

Node::Node(std::string* xmlStr)
    : root(),  //
      text(),  //
      children() {
  if (validateXml(xmlStr)) {
    // sleep(.2);
    auto remainingXml = setRoot(*xmlStr);
    // std::cout << "root = " << root << std::endl;

    remainingXml = setText(remainingXml);
    // std::cout << "text = " << text << std::endl;

    remainingXml = setChildren(remainingXml);
    // std::cout << "num children = " << children.size() << std::endl;
  }
}

Node::Node(std::string xmlStr) : Node(&xmlStr) {
  // Empty: using the forwarding constructor
}

String Node::getElement(std::string tagName) {
  auto slashslash = tagName.find("//");
  // std::cout << "slashslash = " << slashslash << std::endl;

  auto slash = tagName.find("/", slashslash + 2);
  // std::cout << "slash = " << slash << std::endl;

  auto baseTag = tagName.substr(0, slash);

  std::string remainingTag("");
  if (slash != std::string::npos) {
    remainingTag = tagName.substr(slash + 1, std::string::npos);
  }

  // std::cout << "baseTag = " << baseTag << ", remainingTag = " << remainingTag
  // << std::endl;

  for (auto& e : children) {
    // std::cout << "Checking "
    //  << baseTag << " == " << e.root
    //  << std::endl;

    if (e.root == baseTag) {
      if (remainingTag == "") {
        return e.text;
      } else {
        return e.getElement(remainingTag);
      }
    }
  }

  return String();
}

std::vector<xml::Node> Node::getElements(std::string searchStr) {
  // std::cout << std::endl;
  // Util::Log::info("Searching for: ", searchStr, " in root = ", root);
  std::vector<xml::Node> elements;

  auto slashslash = searchStr.find("//");
  // std::cout << "slashslash = " << slashslash << std::endl;
  auto slash = searchStr.find("/", slashslash + 2);
  // std::cout << "slash = " << slash << std::endl;

  auto isBaseSearchNode = (slashslash != std::string::npos);
  auto baseTagStart = 0;
  if (isBaseSearchNode) {
    baseTagStart = slashslash + 2;
  }
  auto baseTag = searchStr.substr(baseTagStart, slash - baseTagStart);

  std::string remainingTag("");
  if (slash != std::string::npos) {
    remainingTag = searchStr.substr(slash + 1, std::string::npos);
  }

  // std::cout << "baseTag = " << baseTag << ", remainingTag = " << remainingTag
  // << std::endl;

  if (baseTag == root) {
    // Util::Log::info("base == root
    // ====================================================");
    if (remainingTag != "") {
      for (auto& e : children) {
        auto nodes = e.getElements(remainingTag);
        elements.insert(elements.end(), nodes.begin(), nodes.end());
      }
    } else {
      // std::cout << "We're in the else, appending self" << std::endl;
      elements.push_back(*this);
    }
  } else if (isBaseSearchNode) {
    for (auto& e : children) {
      auto nodes = e.getElements(searchStr);
      elements.insert(elements.end(), nodes.begin(), nodes.end());
    }
  }

  return elements;
}

std::string Node::setRoot(const std::string& str) {
  // std::cout << "\nsetRoot:\n";
  // std::cout << "str = " << str << std::endl;

  auto pos1 = str.find('<');
  auto pos2 = str.find('>', pos1);
  root = str.substr(pos1 + 1, pos2 - (pos1 + 1));

  auto remainingStr = str.substr(pos2 + 1);

  return remainingStr;
}

std::string Node::setText(const std::string& str) {
  // std::cout << "\nsetText:\n";
  auto pos = str.find('<');
  if (pos != 0) {
    text = str.substr(0, pos);
  }

  auto remainingStr = str.substr(pos);
  // std::cout << "setText remainingStr = " << remainingStr << std::endl;
  return remainingStr;
}

std::string Node::setChildren(std::string str) {
  // std::cout << "\nsetChildren:\n";
  while (!isRootCloseTag(str)) {
    // get open tag position
    auto openL = str.find('<');
    auto openR = str.find('>', openL);
    auto tagName = str.substr(openL + 1, openR - (openL + 1));

    // std::cout << "openL = " << openL << std::endl;
    // std::cout << "openR = " << openR << std::endl;
    // std::cout << "tagName = " << tagName << std::endl;

    // get close tag position
    auto closeL = str.find(tagName, openR);
    // std::cout << "closeL = " << closeL <<  std::endl;

    // get substr from open to close
    auto childXml = str.substr(openL, (closeL - openL) + tagName.size() + 1);
    // str = addChild(substr);
    addChild(childXml);
    str = str.substr(closeL + tagName.size() + 1);
  }
  return str;
}

void Node::addChild(std::string xml) { children.emplace_back(Node(&xml)); }

bool Node::isRootCloseTag(const std::string& str) {
  auto slashPos = str.find("</");
  if (slashPos != 0) return false;

  auto pos2 = str.find('>');
  // std::cout << "\nisRootCloseTag:" << std::endl;
  // std::cout << "str = " << str << std::endl;
  // std::cout << "slashPos = " << slashPos << std::endl;
  // std::cout << "pos2 = " << pos2 << std::endl;

  auto tagName = str.substr(slashPos + 2, pos2 - (slashPos + 2));
  // std::cout << "isRoot tagName = " << tagName << std::endl;
  // std::cout << "isRoot root = " << root << std::endl;

  return (tagName == root);
}

bool Node::validateXml(const std::string* xmlStr) {
  // TODO
  // for each open tag, there exists a closing tag
  // in the same scope?
  return xmlStr->size() > 0;
}

}  // End namespace amb
}  // End namespace xml
