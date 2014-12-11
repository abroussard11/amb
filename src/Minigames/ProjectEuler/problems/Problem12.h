/*
 * Problem12.h
 *
 */

#ifndef SRC_MINIGAMES_PROJECTEULER_PROBLEMS_PROBLEM12_H_
#define SRC_MINIGAMES_PROJECTEULER_PROBLEMS_PROBLEM12_H_

#include <Minigames/ProjectEuler/problems/Problem.h>

namespace Minigames {
namespace ProjectEuler {

class Problem12 : public Problem
{
public:
   Problem12();
   virtual ~Problem12();

   virtual std::string getSolution();
};

} /* namespace ProjectEuler */
} /* namespace Minigames */

#endif /* SRC_MINIGAMES_PROJECTEULER_PROBLEMS_PROBLEM12_H_ */
