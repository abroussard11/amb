# This python script autogenerates class files for the Project Euler problems
# ~ $ python ./createProjectEulerProblems.py

OUTPUT_FOLDER = "../src/Minigames/ProjectEuler/problems/"

##
## Function declarations
##
def createClass(className):
	f = open(OUTPUT_FOLDER + className + ".cpp", 'w')
	f.write("""/*
 * {0}.cpp
 *
 */

#include <string>
#include <Minigames/ProjectEuler/problems/{0}.h>

namespace Minigames {{
namespace ProjectEuler {{

{0}::{0}()
{{
   // Empty
}}

{0}::~{0}()
{{
   // Empty
}}

std::string {0}::getSolution()
{{
   std::string answer("This problem has not yet been solved");
   
   return answer;
}}

}} /* namespace ProjectEuler */
}} /* namespace Minigames */
""".format(className))

def createHeader(className):
	f = open(OUTPUT_FOLDER + className + ".h", 'w')
	f.write("""/*
 * {0}.h
 *
 */

#ifndef SRC_MINIGAMES_PROJECTEULER_PROBLEMS_{1}_H_
#define SRC_MINIGAMES_PROJECTEULER_PROBLEMS_{1}_H_

#include <Minigames/ProjectEuler/problems/Problem.h>

namespace Minigames {{
namespace ProjectEuler {{

class {0} : public Problem
{{
public:
   {0}();
   virtual ~{0}();

   virtual std::string getSolution();
}};

}} /* namespace ProjectEuler */
}} /* namespace Minigames */

#endif /* SRC_MINIGAMES_PROJECTEULER_PROBLEMS_{1}_H_ */
""".format(className, className.upper()))


##
## Main routine
##
problems = []
for i in range(1,100):
   classNum = str(i)
   if (i < 10):
      classNum = "0" + classNum
   problems.append("Problem"+classNum)

for problem in problems:
   createClass(problem)
   createHeader(problem)

# End of script

