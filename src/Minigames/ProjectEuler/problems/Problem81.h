/*
 * Problem81.h
 *
 */

#ifndef SRC_MINIGAMES_PROJECTEULER_PROBLEMS_PROBLEM81_H_
#define SRC_MINIGAMES_PROJECTEULER_PROBLEMS_PROBLEM81_H_

#include <Minigames/ProjectEuler/problems/Problem.h>

namespace Minigames {
namespace ProjectEuler {

class Problem81 : public Problem
{
public:
   Problem81();
   virtual ~Problem81();

   virtual std::string getSolution();
};

} /* namespace ProjectEuler */
} /* namespace Minigames */

#endif /* SRC_MINIGAMES_PROJECTEULER_PROBLEMS_PROBLEM81_H_ */
