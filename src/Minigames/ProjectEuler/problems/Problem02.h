/*
 * Problem02.h
 *
 */

#ifndef SRC_MINIGAMES_PROJECTEULER_PROBLEMS_PROBLEM02_H_
#define SRC_MINIGAMES_PROJECTEULER_PROBLEMS_PROBLEM02_H_

#include <Minigames/ProjectEuler/problems/Problem.h>

namespace Minigames {
namespace ProjectEuler {

class Problem02 : public Problem
{
public:
   Problem02();
   virtual ~Problem02();

   virtual std::string getSolution();
};

} /* namespace ProjectEuler */
} /* namespace Minigames */

#endif /* SRC_MINIGAMES_PROJECTEULER_PROBLEMS_PROBLEM02_H_ */
