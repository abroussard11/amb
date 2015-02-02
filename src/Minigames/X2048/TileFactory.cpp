/*
 * TileFactory.cpp
 *
 *  Created on: Dec 30, 2014
 *      Author: aaron
 */

#include <Minigames/X2048/TileFactory.h>

namespace Minigames {
namespace X2048 {

std::map<unsigned int, Tile::Ptr>* TileFactory::s_tileMap = nullptr;
sf::Font TileFactory::_font;

TileFactory::TileFactory()
{
   // Empty
}

TileFactory::~TileFactory()
{
   // Empty
}

Tile::Ptr TileFactory::getTile(unsigned int val)
{
   return getMap()->at(val);
}

std::map<unsigned int, Tile::Ptr>* TileFactory::getMap()
{
   if (s_tileMap == nullptr)
   {
      s_tileMap = new std::map<unsigned int, Tile::Ptr>();
      _font.loadFromFile("/usr/share/fonts/truetype/luxirb.ttf");

      sf::Color color0(255, 255, 255);
      sf::Color color2(1,255,1);
      sf::Color color4(1,255,1);
      sf::Color color8(1,255,1);
      sf::Color color16(1,255,1);
      sf::Color color32(1,255,1);
      sf::Color color64(1,255,1);
      sf::Color color128(1,255,1);
      sf::Color color256(1,255,1);
      sf::Color color512(1,255,1);
      sf::Color color1024(1,255,1);
      sf::Color color2048(1,255,1);
      sf::Color color4096(1,255,1);

      s_tileMap->insert(std::make_pair(0, Tile::Ptr(new Tile(0, color0, _font))));
      s_tileMap->insert(std::make_pair(2, Tile::Ptr(new Tile(2, color2, _font))));
      s_tileMap->insert(std::make_pair(4, Tile::Ptr(new Tile(4, color4, _font))));
      s_tileMap->insert(std::make_pair(8, Tile::Ptr(new Tile(8, color8, _font))));
      s_tileMap->insert(std::make_pair(16, Tile::Ptr(new Tile(16, color16, _font))));
      s_tileMap->insert(std::make_pair(32, Tile::Ptr(new Tile(32, color32, _font))));
      s_tileMap->insert(std::make_pair(64, Tile::Ptr(new Tile(64, color64, _font))));
      s_tileMap->insert(std::make_pair(128, Tile::Ptr(new Tile(128, color128, _font))));
      s_tileMap->insert(std::make_pair(256, Tile::Ptr(new Tile(256, color256, _font))));
      s_tileMap->insert(std::make_pair(512, Tile::Ptr(new Tile(512, color512, _font))));
      s_tileMap->insert(std::make_pair(1024, Tile::Ptr(new Tile(1024, color1024, _font))));
      s_tileMap->insert(std::make_pair(2048, Tile::Ptr(new Tile(2048, color2048, _font))));
   }

   return s_tileMap;
}

} /* namespace X2048 */
} /* namespace Minigames */
