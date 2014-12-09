/*
 * MadLibMinigame.h
 *
 *  Created on: Dec 6, 2014
 *      Author: aaron
 */

#ifndef SRC_MINIGAMES_MADLIB_MADLIBMINIGAME_H_
#define SRC_MINIGAMES_MADLIB_MADLIBMINIGAME_H_

namespace Minigames {
namespace MadLib {

class MadLibMinigame {
public:
	MadLibMinigame();
	virtual ~MadLibMinigame();

	virtual void play();
};

} /* namespace MadLib */
} /* namespace Minigames */

#endif /* SRC_MINIGAMES_MADLIB_MADLIBMINIGAME_H_ */
