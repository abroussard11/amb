/**
 * dsb/gui/top/PanelTop.cpp
 */

#include <amb/Color.h>
#include <amb/Font.h>
#include <dsb/gui/top/PanelTop.h>
#include <dsb/gui/top/SearchBar.h>
#include <dsb/gui/top/Button.h>
#include <dsb/gui/left/Button.h>
#include <dsb/interface/SaveButtonMsg.h>
#include <dsb/interface/LoadButtonMsg.h>
#include <dsb/interface/ExportButtonMsg.h>

namespace dsb {
namespace gui {
namespace top {

PanelTop::PanelTop(sf::VideoMode mode) :
   GuiComponent(), //
   _rect(), //
   _search("Search:", amb::Font::defaults[0]), //
   _searcha("Search:", amb::Font::defaults[0])
{
   _rect.setSize(sf::Vector2f(mode.width, mode.height / 10.F));
   _rect.setPosition(0, 0);
   _rect.setFillColor(amb::Color::Gray);

   _search.setPosition(5, mode.height / 40.F);
   _search.setCharacterSize(20);
   _search.setColor(sf::Color::Black);

   auto box = _search.getLocalBounds();
   auto searchTextRightSideX = box.left + box.width;

   auto searchBar = std::make_unique<SearchBar>();
   searchBar->setSize(mode.width / 2.F, mode.height / 20.F);
   searchBar->setPosition(searchTextRightSideX + 7, mode.height / 40.F);
   addComponent(std::move(searchBar));

   auto btnOffsetX = mode.width * 0.7F;
   auto btnOffsetY = 30.F;
   auto btnWidth = 100.F;
   auto btnHeight = 30.F;
   auto btnGap = 20.F;
   auto delta = btnWidth + btnGap;

   auto saveBtn = std::make_unique<top::Button<SaveButtonMsg>>();
   saveBtn->move(btnOffsetX + (delta * 0), btnOffsetY);
   saveBtn->setString("save");
   saveBtn->setSize(btnWidth, btnHeight);
   saveBtn->centerText();
   addComponent(std::move(saveBtn));

   auto loadBtn = std::make_unique<top::Button<LoadButtonMsg>>();
   loadBtn->move(btnOffsetX + (delta * 1), btnOffsetY);
   loadBtn->setString("load");
   loadBtn->setSize(btnWidth, btnHeight);
   loadBtn->centerText();
   addComponent(std::move(loadBtn));

   auto exportBtn = std::make_unique<top::Button<ExportButtonMsg>>();
   exportBtn->move(btnOffsetX + (delta * 2), btnOffsetY);
   exportBtn->setString("export");
   exportBtn->setSize(btnWidth, btnHeight);
   exportBtn->centerText();
   addComponent(std::move(exportBtn));
}

void PanelTop::drawSelf(sf::RenderTarget& target, sf::RenderStates states) const
{
   target.draw(_rect, states);
   target.draw(_search, states);
}

} // End namespace top
} // End namespace gui
} // End namespace dsb
