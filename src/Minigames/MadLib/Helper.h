/*
 * Helper.h
 *
 *  Created on: Dec 6, 2014
 *      Author: aaron
 */

#ifndef SRC_MINIGAMES_MADLIB_HELPER_H_
#define SRC_MINIGAMES_MADLIB_HELPER_H_

#include <string>

namespace Minigames {
namespace MadLib {

class Helper {
public:
	Helper();
	virtual ~Helper();

	std::string parseString(std::string str);
};

} /* namespace MadLib */
} /* namespace Minigames */

#endif /* SRC_MINIGAMES_MADLIB_HELPER_H_ */
