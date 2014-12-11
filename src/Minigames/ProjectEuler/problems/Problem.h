/*
 * Problem.h
 *
 *  Created on: Dec 10, 2014
 *      Author: aaron
 */

#ifndef SRC_MINIGAMES_PROJECTEULER_PROBLEMS_PROBLEM_H_
#define SRC_MINIGAMES_PROJECTEULER_PROBLEMS_PROBLEM_H_

#include <memory>

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
   virtual std::string getSolution() = 0;
};

} /* namespace ProjectEuler */
} /* namespace Minigames */

#endif /* SRC_MINIGAMES_PROJECTEULER_PROBLEMS_PROBLEM_H_ */
