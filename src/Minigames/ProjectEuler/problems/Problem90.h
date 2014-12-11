/*
 * Problem90.h
 *
 */

#ifndef SRC_MINIGAMES_PROJECTEULER_PROBLEMS_PROBLEM90_H_
#define SRC_MINIGAMES_PROJECTEULER_PROBLEMS_PROBLEM90_H_

#include <Minigames/ProjectEuler/problems/Problem.h>

namespace Minigames {
namespace ProjectEuler {

class Problem90 : public Problem
{
public:
   Problem90();
   virtual ~Problem90();

   virtual std::string getSolution();
};

} /* namespace ProjectEuler */
} /* namespace Minigames */

#endif /* SRC_MINIGAMES_PROJECTEULER_PROBLEMS_PROBLEM90_H_ */
