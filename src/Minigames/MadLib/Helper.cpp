/*
 * Helper.cpp
 *
 *  Created on: Dec 6, 2014
 *      Author: aaron
 */

#include <iostream>
#include <sstream>
#include <Minigames/MadLib/Helper.h>

namespace Minigames {
namespace MadLib {

Helper::Helper()
{
	// Empty
}

Helper::~Helper()
{
	// Empy
}

std::string Helper::parseString(const std::string str)
{
	std::stringstream paragraphOutput;
	const char* charString = str.c_str();

	for (unsigned int i = 0; i < str.size(); i++) {

		if (charString[i] != '[') {
			paragraphOutput << charString[i];
		} else {
			std::stringstream prompt;
			for (i++; charString[i] != ']'; i++) {
				prompt << charString[i];
			}

			std::cout << prompt.str() << ": ";

			std::string input;
			std::cin >> input;
			paragraphOutput << input;
		}
	}

	return paragraphOutput.str();
}

} /* namespace MadLib */
} /* namespace Minigames */
