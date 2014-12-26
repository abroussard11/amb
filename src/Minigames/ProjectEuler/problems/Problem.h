/*
 * Problem.h
 *
 *  Created on: Dec 10, 2014
 *      Author: aaron
 */

#ifndef SRC_MINIGAMES_PROJECTEULER_PROBLEMS_PROBLEM_H_
#define SRC_MINIGAMES_PROJECTEULER_PROBLEMS_PROBLEM_H_

#include <memory>
#include <sstream>

namespace Minigames {
namespace ProjectEuler {

/**
 * Another Interface Class
 */
class Problem
{
public:
   typedef std::shared_ptr<Problem> Ptr;

   virtual ~Problem() {}

   virtual std::string getText() { return "The text section has not yet been defined for this problem yet."; }
   virtual std::string getSolution() { return "A solution has not been found yet."; }
};

} /* namespace ProjectEuler */
} /* namespace Minigames */

#endif /* SRC_MINIGAMES_PROJECTEULER_PROBLEMS_PROBLEM_H_ */
