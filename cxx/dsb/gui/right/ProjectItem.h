/**
 * dsb/gui/right/ProjectItem.h
 */

#ifndef DSB_GUI_RIGHT_PROJECTITEM_H_
#define DSB_GUI_RIGHT_PROJECTITEM_H_

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <amb/GuiComponent.h>
#include <dsb/interface/ActivityMsg.h>

namespace dsb {
namespace gui {
namespace right {

class ProjectItem : public amb::GuiComponent {
 public:
  ProjectItem(const ActivityMsg& act);
  ProjectItem() = default;
  virtual ~ProjectItem() = default;

  ActivityMsg toActivityMsg() const;
  void updateTotal();

 protected:
  virtual void onKeyPressed(sf::Event& event) override;
  virtual void onTextEntered(sf::Event& event) override;
  virtual void onMouseButtonPressed(sf::Event& event) override;
  virtual void onMouseButtonReleased(sf::Event& event) override;

 private:
  bool _doListenForKeyboard;
  sf::Text _name;
  sf::Text _desc;
  sf::Text _LU;
  sf::Text _UC;
  sf::Text _QU;
  sf::Text _total;
  sf::Text* _fieldBeingEdited;
  sf::RectangleShape _nameBox;
  sf::RectangleShape _luBox;
  sf::RectangleShape _ucBox;
  sf::RectangleShape _quBox;
  sf::RectangleShape _totalBox;

  virtual void updateSelf() override;
  virtual void drawSelf(sf::RenderTarget& target,
                        sf::RenderStates states) const override;
  bool isClickOnLuBox(sf::Event& event, sf::Transform trans);
  bool isClickOnUcBox(sf::Event& event, sf::Transform trans);
  bool isClickOnQuBox(sf::Event& event, sf::Transform trans);
  bool isClickOnTotalBox(sf::Event& event, sf::Transform trans);
};

}  // End namespace right
}  // End namespace gui
}  // End namespace dsb

#endif  // DSB_GUI_RIGHT_PROJECTITEM_H_
