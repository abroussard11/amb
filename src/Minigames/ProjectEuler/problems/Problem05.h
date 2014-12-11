/*
 * Problem05.h
 *
 */

#ifndef SRC_MINIGAMES_PROJECTEULER_PROBLEMS_PROBLEM05_H_
#define SRC_MINIGAMES_PROJECTEULER_PROBLEMS_PROBLEM05_H_

#include <Minigames/ProjectEuler/problems/Problem.h>

namespace Minigames {
namespace ProjectEuler {

class Problem05 : public Problem
{
public:
   Problem05();
   virtual ~Problem05();

   virtual std::string getSolution();
};

} /* namespace ProjectEuler */
} /* namespace Minigames */

#endif /* SRC_MINIGAMES_PROJECTEULER_PROBLEMS_PROBLEM05_H_ */
