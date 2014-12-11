/*
 * Problem99.h
 *
 */

#ifndef SRC_MINIGAMES_PROJECTEULER_PROBLEMS_PROBLEM99_H_
#define SRC_MINIGAMES_PROJECTEULER_PROBLEMS_PROBLEM99_H_

#include <Minigames/ProjectEuler/problems/Problem.h>

namespace Minigames {
namespace ProjectEuler {

class Problem99 : public Problem
{
public:
   Problem99();
   virtual ~Problem99();

   virtual std::string getSolution();
};

} /* namespace ProjectEuler */
} /* namespace Minigames */

#endif /* SRC_MINIGAMES_PROJECTEULER_PROBLEMS_PROBLEM99_H_ */
