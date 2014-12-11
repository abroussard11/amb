/*
 * Problem42.h
 *
 */

#ifndef SRC_MINIGAMES_PROJECTEULER_PROBLEMS_PROBLEM42_H_
#define SRC_MINIGAMES_PROJECTEULER_PROBLEMS_PROBLEM42_H_

#include <Minigames/ProjectEuler/problems/Problem.h>

namespace Minigames {
namespace ProjectEuler {

class Problem42 : public Problem
{
public:
   Problem42();
   virtual ~Problem42();

   virtual std::string getSolution();
};

} /* namespace ProjectEuler */
} /* namespace Minigames */

#endif /* SRC_MINIGAMES_PROJECTEULER_PROBLEMS_PROBLEM42_H_ */
