/*
 * Problem09.h
 *
 */

#ifndef SRC_MINIGAMES_PROJECTEULER_PROBLEMS_PROBLEM09_H_
#define SRC_MINIGAMES_PROJECTEULER_PROBLEMS_PROBLEM09_H_

#include <Minigames/ProjectEuler/problems/Problem.h>

namespace Minigames {
namespace ProjectEuler {

class Problem09 : public Problem
{
public:
   Problem09();
   virtual ~Problem09();

   virtual std::string getSolution();
};

} /* namespace ProjectEuler */
} /* namespace Minigames */

#endif /* SRC_MINIGAMES_PROJECTEULER_PROBLEMS_PROBLEM09_H_ */
