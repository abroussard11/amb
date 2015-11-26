/**
 * dsb/gui/right/ProjectItem.cpp
 */

#include <dsb/gui/right/ProjectItem.h>

#include <iostream>
#include <sstream>
#include <typeinfo>
#include <amb/Color.h>
#include <amb/Font.h>
#include <amb/Text.h>
#include <dsb/interface/ActivityMsg.h>

namespace dsb {
namespace gui {
namespace right {

ProjectItem::ProjectItem(const ActivityMsg& act) :
   _doListenForKeyboard(false), //
   _name(act.name, amb::Font::defaults[0]), //
   _desc(act.desc, amb::Font::defaults[0]), //
   _LU(act.LU, amb::Font::defaults[0]), //
   _UC(act.UC, amb::Font::defaults[0]), //
   _QU(act.QU, amb::Font::defaults[0]), //
   _total(act.total, amb::Font::defaults[0]), //
   _fieldBeingEdited(nullptr), //
   _nameBox(), //
   _luBox(), //
   _ucBox(), //
   _quBox(), //
   _totalBox()
{
   const auto margin = 20.F;
   const auto topMargin = 7.5F;
   const float rectWidth = 120.F;
   const auto boxSize = sf::Vector2f(rectWidth - 1.F, 30.F);
   // Texts
   _name.setPosition(margin, topMargin);
   _desc.setPosition(margin, 20.F + topMargin);
   _LU.setPosition(rectWidth + margin, topMargin);
   _UC.setPosition((rectWidth * 2) + margin, topMargin);
   _QU.setPosition((rectWidth * 3) + margin, topMargin);
   _total.setPosition((rectWidth * 4) + margin, topMargin);
   _name.setCharacterSize(15);
   _desc.setCharacterSize(15);
   _LU.setCharacterSize(15);
   _UC.setCharacterSize(15);
   _QU.setCharacterSize(15);
   _total.setCharacterSize(15);
   _name.setColor(amb::Color::Black);
   _desc.setColor(sf::Color::Black);
   _LU.setColor(sf::Color::Black);
   _UC.setColor(sf::Color::Black);
   _QU.setColor(sf::Color::Black);
   _total.setColor(sf::Color::Black);

   // Boxes
   _nameBox.setOutlineColor(sf::Color::Black);
   _luBox.setOutlineColor(sf::Color::Black);
   _ucBox.setOutlineColor(sf::Color::Black);
   _quBox.setOutlineColor(sf::Color::Black);
   _totalBox.setOutlineColor(sf::Color::Black);
   _nameBox.setOutlineThickness(1.F);
   _luBox.setOutlineThickness(1.F);
   _ucBox.setOutlineThickness(1.F);
   _quBox.setOutlineThickness(1.F);
   _totalBox.setOutlineThickness(1.F);
   _nameBox.setFillColor(sf::Color::Transparent);
   _luBox.setFillColor(sf::Color::Transparent);
   _ucBox.setFillColor(sf::Color::Transparent);
   _quBox.setFillColor(sf::Color::Transparent);
   _totalBox.setFillColor(sf::Color::Transparent);
   _nameBox.setSize(boxSize);
   _luBox.setSize(boxSize);
   _ucBox.setSize(boxSize);
   _quBox.setSize(boxSize);
   _totalBox.setSize(boxSize);
   _nameBox.setPosition(0 * rectWidth, 0.F);
   _luBox.setPosition(1 * rectWidth, 0.F);
   _ucBox.setPosition(2 * rectWidth, 0.F);
   _quBox.setPosition(3 * rectWidth, 0.F);
   _totalBox.setPosition(4 * rectWidth, 0.F);
}

ActivityMsg ProjectItem::toActivityMsg() const
{
   auto msg = ActivityMsg();
   msg.name = _name.getString();
   msg.desc = _desc.getString();
   msg.LU = _LU.getString();
   msg.UC = _UC.getString();
   msg.QU = _QU.getString();
   msg.total = _total.getString();
   return msg;
}

void ProjectItem::updateTotal()
{
   std::string ucLabel = _UC.getString();
   std::string ucNum;
   std::cout << "Parsing " << ucLabel << std::endl;
   for (auto& e : ucLabel)
   {
      if (isdigit(e))
      {
         ucNum += e;
         // std::cout << "e = " << e << ", typeid = " << typeid(e).name() << std::endl;
      }
   }
   std::stringstream convertUc(ucNum);
   std::stringstream convertQu(_QU.getString().toAnsiString());
   std::stringstream convertTotal;
   int uc;
   int qu;
   int total;

   convertUc >> uc;
   convertQu >> qu;

   total = uc * qu;

   convertTotal << total;
   _total.setString(convertTotal.str());
}

void ProjectItem::onTextEntered(sf::Event& event)
{
   if (_doListenForKeyboard)
   {
      if (event.text.unicode >= 32 && event.text.unicode < 128)
      {
         sf::String str = _fieldBeingEdited->getString();
         str.insert(str.getSize(), event.text.unicode);
         _fieldBeingEdited->setString(str);
         updateTotal();
      }
   }
}

void ProjectItem::onKeyPressed(sf::Event& event)
{
   if (_doListenForKeyboard)
   {
      // looking for the backspace key
      if(event.key.code == sf::Keyboard::BackSpace)
      {
         // std::cout << "BackSpace was pressed" << std::endl;
         sf::String str = _fieldBeingEdited->getString();
         if (str.getSize() > 0)
         {
            str.erase(str.getSize() - 1);
            _fieldBeingEdited->setString(str);
            updateTotal();
         }
      }
   }
}

void ProjectItem::onMouseButtonPressed(sf::Event& event)
{
   // Empty
}

void ProjectItem::onMouseButtonReleased(sf::Event& event)
{
   const auto trans = getGlobalTransform();
   if (isClickOnLuBox(event, trans))
   {
      std::cout << "Editing LU" << std::endl;
      _fieldBeingEdited = &_LU;
      _doListenForKeyboard = true;
   }
   else if (isClickOnUcBox(event, trans))
   {
      std::cout << "Editing UC" << std::endl;
      _fieldBeingEdited = &_UC;
      _doListenForKeyboard = true;
   }
   else if (isClickOnQuBox(event, trans))
   {
      std::cout << "Editing QU" << std::endl;
      _fieldBeingEdited = &_QU;
      _doListenForKeyboard = true;
   }
   else if (isClickOnTotalBox(event, trans))
   {
      std::cout << "Editing Total" << std::endl;
      _fieldBeingEdited = &_total;
      _doListenForKeyboard = true;
   }
   else
   {
      _fieldBeingEdited = nullptr;
      _doListenForKeyboard = false;
   }
}

void ProjectItem::updateSelf()
{

}

void ProjectItem::drawSelf(sf::RenderTarget& target, sf::RenderStates states) const
{
   target.draw(_nameBox, states);
   target.draw(_luBox, states);
   target.draw(_ucBox, states);
   target.draw(_quBox, states);
   target.draw(_totalBox, states);

   target.draw(_name, states);
   target.draw(_LU, states);
   target.draw(_UC, states);
   target.draw(_QU, states);
   target.draw(_total, states);
}

bool ProjectItem::isClickOnLuBox(sf::Event& event, sf::Transform trans)
{
   auto box = trans.transformRect(_luBox.getGlobalBounds());
   return box.contains(event.mouseButton.x, event.mouseButton.y);;
}

bool ProjectItem::isClickOnUcBox(sf::Event& event, sf::Transform trans)
{
   auto box = trans.transformRect(_ucBox.getGlobalBounds());
   return box.contains(event.mouseButton.x, event.mouseButton.y);;
}

bool ProjectItem::isClickOnQuBox(sf::Event& event, sf::Transform trans)
{
   auto box = trans.transformRect(_quBox.getGlobalBounds());
   return box.contains(event.mouseButton.x, event.mouseButton.y);;
}

bool ProjectItem::isClickOnTotalBox(sf::Event& event, sf::Transform trans)
{
   auto box = trans.transformRect(_totalBox.getGlobalBounds());
   return box.contains(event.mouseButton.x, event.mouseButton.y);;
}

} // End namespace right
} // End namespace gui
} // End namespace dsb
