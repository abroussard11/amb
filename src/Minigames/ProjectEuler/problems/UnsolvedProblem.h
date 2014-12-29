/*
 * UnsolvedProblem.h
 *
 *  Created on: Dec 29, 2014
 *      Author: aaron
 */

#ifndef SRC_MINIGAMES_PROJECTEULER_PROBLEMS_UNSOLVEDPROBLEM_H_
#define SRC_MINIGAMES_PROJECTEULER_PROBLEMS_UNSOLVEDPROBLEM_H_

#include <Minigames/ProjectEuler/problems/Problem.h>

namespace Minigames {
namespace ProjectEuler {

class UnsolvedProblem : public Problem
{
public:
   UnsolvedProblem();
   virtual ~UnsolvedProblem();

   virtual std::string getSolution();
};

} /* namespace ProjectEuler */
} /* namespace Minigames */

#endif /* SRC_MINIGAMES_PROJECTEULER_PROBLEMS_UNSOLVEDPROBLEM_H_ */
