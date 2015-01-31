/*
 * TileFactory.h
 *
 *  Created on: Dec 30, 2014
 *      Author: aaron
 */

#ifndef SRC_MINIGAMES_X2048_TILEFACTORY_H_
#define SRC_MINIGAMES_X2048_TILEFACTORY_H_

#include <map>
#include <Minigames/X2048/Tile.h>

namespace Minigames {
namespace X2048 {

class TileFactory
{
public:
   TileFactory();
   virtual ~TileFactory();

   static Tile::Ptr getTile(unsigned int val);
   static std::map<unsigned int, Tile::Ptr>* getMap();

private:
   static std::map<unsigned int, Tile::Ptr>* s_tileMap;
};

} /* namespace X2048 */
} /* namespace Minigames */

#endif /* SRC_MINIGAMES_X2048_TILEFACTORY_H_ */
