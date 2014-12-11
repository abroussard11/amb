/*
 * Problem01.h
 *
 */

#ifndef SRC_MINIGAMES_PROJECTEULER_PROBLEMS_PROBLEM01_H_
#define SRC_MINIGAMES_PROJECTEULER_PROBLEMS_PROBLEM01_H_

#include <Minigames/ProjectEuler/problems/Problem.h>

namespace Minigames {
namespace ProjectEuler {

class Problem01 : public Problem
{
public:
   Problem01();
   virtual ~Problem01();

   virtual std::string getSolution();
};

} /* namespace ProjectEuler */
} /* namespace Minigames */

#endif /* SRC_MINIGAMES_PROJECTEULER_PROBLEMS_PROBLEM01_H_ */
