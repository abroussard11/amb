/*
 * Problem06.h
 *
 */

#ifndef SRC_MINIGAMES_PROJECTEULER_PROBLEMS_PROBLEM06_H_
#define SRC_MINIGAMES_PROJECTEULER_PROBLEMS_PROBLEM06_H_

#include <Minigames/ProjectEuler/problems/Problem.h>

namespace Minigames {
namespace ProjectEuler {

class Problem06 : public Problem
{
public:
   Problem06();
   virtual ~Problem06();

   virtual std::string getSolution();
};

} /* namespace ProjectEuler */
} /* namespace Minigames */

#endif /* SRC_MINIGAMES_PROJECTEULER_PROBLEMS_PROBLEM06_H_ */
