/*
 * Library.h
 *
 *  Created on: Dec 6, 2014
 *      Author: aaron
 */

#ifndef SRC_MINIGAMES_MADLIB_LIBRARY_H_
#define SRC_MINIGAMES_MADLIB_LIBRARY_H_

#include <string>

namespace Minigames {
namespace MadLib {

class Library {
public:
	static const std::string LetterFromCamp;

	virtual ~Library();

};

} /* namespace MadLib */
} /* namespace Minigames */

#endif /* SRC_MINIGAMES_MADLIB_LIBRARY_H_ */
