/**
 * dsb/gui/right/PanelRight.cpp
 */

#include <dsb/gui/right/PanelRight.h>

#include <iostream>
#include <amb/Color.h>
#include <amb/Font.h>
#include <Util/Log.h>

namespace dsb {
namespace gui {
namespace right {

PanelRight::PanelRight(sf::VideoMode mode) :
   GuiComponent(), //
   _rect(), //
   _projectListBackground(), //
   _actList(), //
   _projectLabel("", amb::Font::defaults[0]), //
   _header(), //
   _inbox(), //
   _saveInbox(), //
   _loadInbox(), //
   _exportInbox()
{
   _actList = std::make_shared<ActivityList>();
   addComponent(_actList);

   // Messaging
   using namespace infra;
   _inbox = Inbox<ActivityMsg>::makeInbox();
   registerInbox<ActivityMsg>(_inbox);
   _saveInbox = Inbox<SaveButtonMsg>::makeInbox();
   registerInbox<SaveButtonMsg>(_saveInbox);
   _loadInbox = Inbox<LoadButtonMsg>::makeInbox();
   registerInbox<LoadButtonMsg>(_loadInbox);
   _exportInbox = Inbox<ExportButtonMsg>::makeInbox();
   registerInbox<ExportButtonMsg>(_exportInbox);

   auto width = mode.width / 3.F;
   auto height = mode.height * 0.9F;

   // Background
   _rect.setSize(sf::Vector2f(width, height));
   _rect.setFillColor(amb::Color::Gray);

   // project item list background
   auto listWidth = width - 5.F;
   auto listHeight = height - (mode.height / 40.F) - 5.F;
   _projectListBackground.setSize(sf::Vector2f(listWidth, listHeight));
   _projectListBackground.setPosition(0, 0);
   _projectListBackground.setFillColor(sf::Color::White);

   _projectLabel.setPosition(0, 0);
   _projectLabel.setCharacterSize(20);
   _projectLabel.setColor(sf::Color::Black);

   Repository repo;
   if (repo.isValid())
   {
      std::string prefix("     Project: ");
      _projectLabel.setString(prefix + repo.getHead());

      std::ifstream ifs(repo.getHead(), std::ifstream::in);
      auto proj = ProjectFile();
      proj.deserialize(ifs);
      _actList->loadProjectFile(proj);
   }

   _header.move(0.F, 30.F);
   _actList->move(0.F, 61.F);
}

// void PanelRight::processEvent(sf::Event& event)
// {
//    amb::GuiComponent::processEvent(event);
//    // if (isClickOnSelf(event))
//    // {
//    //    Util::Log::info("PanelRight clicked on");
//    //    // _actList->processEvent(event);
//    // }
// }

void PanelRight::onActivityMsg(const ActivityMsg& msg)
{
   _actList->append(msg);
}

void PanelRight::onSaveButtonMsg(const SaveButtonMsg& msg)
{
   Util::Log::debug("save");
   Repository repo;
   _actList->saveProjectToFile(repo.getHead());
}

void PanelRight::onLoadButtonMsg(const LoadButtonMsg& msg)
{
   Util::Log::debug("load");
   // TODO: prompt for file name
   // TODO: load that file
}

void PanelRight::onExportButtonMsg(const ExportButtonMsg& msg)
{
   Util::Log::debug("export");
   // TODO: export to csv? xls?
}

void PanelRight::updateSelf()
{
   auto msgs = _inbox->getMessages();
   for (auto& m : msgs)
   {
      onActivityMsg(m.content);
   }

   for (auto& m : _saveInbox->getMessages())
   {
      onSaveButtonMsg(m.content);
   }

   for (auto& m : _loadInbox->getMessages())
   {
      onLoadButtonMsg(m.content);
   }

   for (auto& m : _exportInbox->getMessages())
   {
      onExportButtonMsg(m.content);
   }
}

void PanelRight::drawSelf(sf::RenderTarget& target, sf::RenderStates states) const
{
   target.draw(_rect, states);
   target.draw(_projectListBackground, states);
   target.draw(_projectLabel, states);
   target.draw(_header, states);
   target.draw(*_actList, states);
}

// bool PanelRight::isClickOnSelf(const sf::Event& event)
// {
//    if (event.type == sf::Event::MouseButtonPressed || event.type == sf::Event::MouseButtonReleased)
//    {
//       auto trans = getGlobalTransform();
//       auto box = trans.transformRect(_rect.getGlobalBounds());
//
//       return box.contains(event.mouseButton.x, event.mouseButton.y);
//    }
//    else
//    {
//       return false;
//    }
// }

} // End namespace right
} // End namespace gui
} // End namespace dsb
