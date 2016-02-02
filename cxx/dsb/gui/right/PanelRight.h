/**
 * dsb/gui/right/PanelRight.h
 */

#ifndef DSB_GUI_RIGHT_PANELRIGHT_H_
#define DSB_GUI_RIGHT_PANELRIGHT_H_

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <amb/GuiComponent.h>
#include <dsb/interface/ActivityMsg.h>
#include <dsb/interface/SaveButtonMsg.h>
#include <dsb/interface/LoadButtonMsg.h>
#include <dsb/interface/ExportButtonMsg.h>
#include <dsb/gui/right/ActivityList.h>
#include <dsb/gui/right/ListHeader.h>
#include <infra/Inbox.h>

namespace dsb {
namespace gui {
namespace right {

class PanelRight : public amb::GuiComponent {
 public:
  PanelRight() = delete;
  PanelRight(sf::VideoMode mode);
  virtual ~PanelRight() = default;

  // virtual void processEvent(sf::Event& event);

 protected:
  void onActivityMsg(const ActivityMsg& msg);
  void onSaveButtonMsg(const SaveButtonMsg& msg);
  void onLoadButtonMsg(const LoadButtonMsg& msg);
  void onExportButtonMsg(const ExportButtonMsg& msg);

 private:
  sf::RectangleShape _rect;
  sf::RectangleShape _projectListBackground;
  ActivityList::Ptr _actList;
  sf::Text _projectLabel;  // TODO add a ProjectLabelContainer for looks
  ListHeader _header;
  infra::Inbox<ActivityMsg>::Ptr _inbox;
  infra::Inbox<SaveButtonMsg>::Ptr _saveInbox;
  infra::Inbox<LoadButtonMsg>::Ptr _loadInbox;
  infra::Inbox<ExportButtonMsg>::Ptr _exportInbox;

  void updateSelf() override;
  void drawSelf(sf::RenderTarget& target,
                        sf::RenderStates states) const override;
  // bool isClickOnSelf(const sf::Event& event);
};

}  // End namespace right
}  // End namespace gui
}  // End namespace dsb

#endif  // DSB_GUI_RIGHT_PANELRIGHT_H_
