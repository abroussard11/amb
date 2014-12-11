/*
 * Problem03.h
 *
 */

#ifndef SRC_MINIGAMES_PROJECTEULER_PROBLEMS_PROBLEM03_H_
#define SRC_MINIGAMES_PROJECTEULER_PROBLEMS_PROBLEM03_H_

#include <Minigames/ProjectEuler/problems/Problem.h>

namespace Minigames {
namespace ProjectEuler {

class Problem03 : public Problem
{
public:
   Problem03();
   virtual ~Problem03();

   virtual std::string getSolution();
};

} /* namespace ProjectEuler */
} /* namespace Minigames */

#endif /* SRC_MINIGAMES_PROJECTEULER_PROBLEMS_PROBLEM03_H_ */
