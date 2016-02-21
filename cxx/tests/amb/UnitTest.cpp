/**
 * tests/amb/UnitTest.cpp
 */

#include <tests/amb/UnitTest.h>

#include <amb/Attribute.h>
#include <amb/CliAppDriver.h>
#include <amb/Color.h>
#include <amb/FastMap.h>
#include <amb/Font.h>
#include <amb/GuiAppDriver.h>
#include <amb/GuiComponent.h>
#include <amb/ProgVars.h>
#include <amb/Xml.h>
#include <Util/Log.h>
#include <typeinfo>
#include <SFML/Graphics/Text.hpp>

namespace amb {

void UnitTest::testRoutine() {
  constructorTest<amb::CliAppDriver>();       // 1
  constructorTest<amb::Color>();              // 2
  constructorTest<amb::FastMap<int, int>>();  // 3
  // auto LUXIRB = amb::FontNames::luxirb;
  // constructorTest<amb::Font>(LUXIRB); // 4 //TODO: figure out why we can't
  // use amb::Font::LUXIRB directly
  constructorTest<amb::GuiAppDriver>();             // 5
  constructorTest<amb::GuiComponent>();             // 6
  constructorTest<amb::ProgVars>();                 // 7
  constructorTest<amb::xml::Node>();                // 8
  constructorTest<amb::xml::Node>("");              // 9
  constructorTest<amb::Xml>("cxx/tests/test.xml");  // 10
  if (_verbose) {
    Util::Log::info(
        "Attempting to load non-existent file. Expecting an Error message...");
  }
  constructorTest<amb::Xml>("fileNotFound.xml");  // 11
  testFastMap();
  trackTest(testGuiComponent());  // 14
  testXml();
  testAttribute();

  //constructorTest<sf::Text>("TestText", amb::Font::defaults[0]);
}

/**
 * The unit test for amb::FastMap
 */
void UnitTest::testFastMap() {
  Util::Log::info("Begin testFastMap subtest");

  using ValueType = std::shared_ptr<std::string>;

  amb::FastMap<int, ValueType> myMap;
  myMap.push_back(0, std::make_shared<std::string>("zero"));
  myMap.push_back(1, std::make_shared<std::string>("one"));

  auto val0 = myMap.find(0);
  requireEqual(*val0, "zero");  // 12

  auto val1 = myMap.find(1);
  requireEqual(*val1, "one");  // 13
}

/**
 * The unit test for amb::GuiComponent
 */
bool UnitTest::testGuiComponent() {
  Util::Log::info("Begin testGuiComponent subtest");
  auto success = true;
  try {
    auto component = std::make_unique<amb::GuiComponent>();
    auto event = sf::Event{};
    component->addComponent<amb::GuiComponent>();
    component->processEvent(event);

    amb::GuiComponent::Ptr comp = std::make_unique<amb::GuiComponent>();
    component->addComponent(std::move(comp));
  } catch (...) {
    success = false;
  }

  return success;
}

/**
 * The unit test for amb::Xml
 */
void UnitTest::testXml() {
  Util::Log::info("Begin testXml subtest");

  amb::xml::Node node1("<root></root>");
  requireEqual(node1.root, "root");        // 15
  requireEqual(node1.text, "");            // 16
  requireEqual(node1.children.size(), 0);  // 17

  amb::xml::Node node2("<root>Aaron</root>");
  requireEqual(node2.root, "root");        // 18
  requireEqual(node2.text, "Aaron");       // 19
  requireEqual(node2.children.size(), 0);  // 20

  amb::xml::Node node3("<root><child>Aaron</child><child>Adam</child></root>");
  requireEqual(node3.root, "root");                  // 21
  requireEqual(node3.text, "");                      // 22
  requireEqual(node3.children.size(), 2);            // 23
  requireEqual(node3.children.at(0).text, "Aaron");  // 24
  requireEqual(node3.children.at(1).text, "Adam");   // 25

  auto testXml =
      "<group><name>MISCELLANEOUS</name><item><name>TREE</name><desc>Remove: "
      "Tree/Step/Deck/Other</desc><LU>300</LU><UC>e300a</UC></item></group>";
  amb::xml::Node node4(testXml);
  requireEqual(node4.root, "group");       // 26
  requireEqual(node4.text, "");            // 27
  requireEqual(node4.children.size(), 2);  // 28
  auto& child1 = node4.children.at(0);
  requireEqual(child1.root, "name");           // 29
  requireEqual(child1.text, "MISCELLANEOUS");  // 30
  auto& child2 = node4.children.at(1);
  requireEqual(child2.root, "item");        // 31
  requireEqual(child2.text, "");            // 32
  requireEqual(child2.children.size(), 4);  // 33
  auto& subChild1 = child2.children.at(0);
  requireEqual(subChild1.text, "TREE");  // 34
  auto& subChild2 = child2.children.at(1);
  requireEqual(subChild2.text, "Remove: Tree/Step/Deck/Other");  // 35
  auto& subChild3 = child2.children.at(2);
  requireEqual(subChild3.text, "300");        // 36
  requireEqual(subChild3.text.toInt(), 300);  // 37
  auto& subChild4 = child2.children.at(3);
  requireEqual(subChild4.text, "e300a");  // 38

  auto testXmlFile =
      "   <group>\n\
      <name>MISCELLANEOUS</name>\n\
      <item>\n\
         <name>TREE</name>\n\
         <desc>Remove: Tree/Step/Deck/Other</desc>\n\
         <LU>300</LU>\n\
         <UC>e300a</UC>\n\
      </item>\n\
   </group>\n";
  amb::Xml xml;
  xml.loadString(testXmlFile);
  requireEqual(xml.node.root, "group");       // 39
  requireEqual(xml.node.text, "");            // 40
  requireEqual(xml.node.children.size(), 2);  // 41
  auto& xmlChild1 = xml.node.children.at(0);
  requireEqual(xmlChild1.root, "name");           // 42
  requireEqual(xmlChild1.text, "MISCELLANEOUS");  // 43
  auto& xmlChild2 = xml.node.children.at(1);
  requireEqual(xmlChild2.root, "item");        // 44
  requireEqual(xmlChild2.text, "");            // 45
  requireEqual(xmlChild2.children.size(), 4);  // 46
  auto& xmlSubChild1 = xmlChild2.children.at(0);
  auto& xmlSubChild2 = xmlChild2.children.at(1);
  auto& xmlSubChild3 = xmlChild2.children.at(2);
  auto& xmlSubChild4 = xmlChild2.children.at(3);
  requireEqual(xmlSubChild1.text, "TREE");                          // 47
  requireEqual(xmlSubChild2.text, "Remove: Tree/Step/Deck/Other");  // 48
  requireEqual(xmlSubChild3.text, "300");                           // 49
  requireEqual(xmlSubChild3.text.toInt(), 300);                     // 50
  requireEqual(xmlSubChild4.text, "e300a");                         // 51

  amb::Xml xml2;
  xml2.loadString("<!-- Comment Handling --><root></root>");
  requireEqual(xml2.node.root, "root");        // 52
  requireEqual(xml2.node.text, "");            // 53
  requireEqual(xml2.node.children.size(), 0);  // 54

  amb::Xml xml3;
  xml3.loadString("<root></root><!-- comment -->");
  requireEqual(xml3.node.root, "root");        // 55
  requireEqual(xml3.node.text, "");            // 56
  requireEqual(xml3.node.children.size(), 0);  // 57

  amb::Xml xml4;
  xml4.loadString("<!-- Comment Handling --><root></root><!-- comment -->");
  requireEqual(xml4.node.root, "root");        // 58
  requireEqual(xml4.node.text, "");            // 59
  requireEqual(xml4.node.children.size(), 0);  // 60

  amb::Xml xml5;
  xml5.loadFile("cxx/tests/test.xml");
  // Test for valid reading of the Ampersand
  requireEqual(xml5.node.children.at(3).text, "Aaron & Adam");  // 61
  requireEqual(xml5.getElement("child1"), "");                  // 62
  requireEqual(xml5.getElement("child1/data").toInt(), 1);      // 63
  auto xml5Elements = xml5.getElements("//data");
  requireEqual(xml5Elements.size(), 3);              // 64
  requireEqual(xml5Elements.at(0).text.toInt(), 1);  // 65
  requireEqual(xml5Elements.at(1).text.toInt(), 2);  // 66
  requireEqual(xml5Elements.at(2).text.toInt(), 3);  // 67
}

struct DataSet1 {
  int x;
  int y;
};

struct DataSet2 {
  float x;
  float y;
};

void assignDataSet1(void* obj, const DataSet1& prop);
void assignDataSet2(void* obj, const DataSet2& prop);

class MyModel {
 public:
  amb::Attribute<DataSet1> data1;
  amb::Attribute<DataSet2> data2;

  MyModel()
      : data1((void*)this, &assignDataSet1),  //
        data2((void*)this, &assignDataSet2)   //
  {
    // Empty
  }

  void setProperty(const DataSet1& data) {
    data1.set(data);
  }

  void setProperty(const DataSet2& data) {
    data2.set(data);
  }
};

void assignDataSet1(void* obj, const DataSet1& prop) {
  std::cout << "Calling assignDataSet1\n";
  static_cast<MyModel*>(obj)->setProperty(prop);
}

void assignDataSet2(void* obj, const DataSet2& prop) {
  std::cout << "Calling assignDataSet2\n";
  static_cast<MyModel*>(obj)->setProperty(prop);
}

//template <typename Property>
//void assignPropType(void* obj, const Property& prop) {
//   std::cout << "Calling assignPropType" << std::endl;
//   static_cast<MyModel*>(obj)->setProperty(prop);
//};

void UnitTest::testAttribute() {
  MyModel model;
  DataSet1 _amb = {3, 5};
  //DataSet2 _dataSet2= {1.0F, 25.0F};

  model.data1 = _amb;
  requireEqual(static_cast<DataSet1>(model.data1).x, 3);
  requireEqual(static_cast<DataSet1>(model.data1).y, 5);

  //DataSet1 _amb2;
  //_amb2 = model.data1;
  //requireEqual(_amb2.x, 3);
  //requireEqual(_amb2.y, 5);
}

}  // End namespace amb
