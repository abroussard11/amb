/*
 * ProblemLoader.h
 *
 *  Created on: Dec 10, 2014
 *      Author: aaron
 */

#ifndef SRC_MINIGAMES_PROJECTEULER_PROBLEMLOADER_H_
#define SRC_MINIGAMES_PROJECTEULER_PROBLEMLOADER_H_

#include <vector>
#include <Minigames/ProjectEuler/problems/Problem.h>
#include <Minigames/ProjectEuler/problems/allProblems.h>

namespace Minigames {
namespace ProjectEuler {

class ProblemLoader
{
public:
   ProblemLoader();
   virtual ~ProblemLoader();

   virtual Problem::Ptr load(unsigned int problemNumber);

private:
   std::vector<Problem::Ptr> _problems;
};

} /* namespace ProjectEuler */
} /* namespace Minigames */

#endif /* SRC_MINIGAMES_PROJECTEULER_PROBLEMLOADER_H_ */
