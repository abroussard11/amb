/*
 * Problem04.h
 *
 */

#ifndef SRC_MINIGAMES_PROJECTEULER_PROBLEMS_PROBLEM04_H_
#define SRC_MINIGAMES_PROJECTEULER_PROBLEMS_PROBLEM04_H_

#include <Minigames/ProjectEuler/problems/Problem.h>

namespace Minigames {
namespace ProjectEuler {

class Problem04 : public Problem
{
public:
   Problem04();
   virtual ~Problem04();

   virtual std::string getSolution();
};

} /* namespace ProjectEuler */
} /* namespace Minigames */

#endif /* SRC_MINIGAMES_PROJECTEULER_PROBLEMS_PROBLEM04_H_ */
