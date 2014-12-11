/*
 * ProblemLoader.cpp
 *
 *  Created on: Dec 10, 2014
 *      Author: aaron
 */

#include <Minigames/ProjectEuler/ProblemLoader.h>

namespace Minigames {
namespace ProjectEuler {

ProblemLoader::ProblemLoader() :
         _problems()
{
   _problems.reserve(100);
   _problems.push_back(Problem::Ptr(new Problem01)); // Leave this one here as a dummy so that index 1 is problem 1
   _problems.push_back(Problem::Ptr(new Problem01));
   _problems.push_back(Problem::Ptr(new Problem02));
   _problems.push_back(Problem::Ptr(new Problem03));
   _problems.push_back(Problem::Ptr(new Problem04));
   _problems.push_back(Problem::Ptr(new Problem05));
   _problems.push_back(Problem::Ptr(new Problem06));
   _problems.push_back(Problem::Ptr(new Problem07));
   _problems.push_back(Problem::Ptr(new Problem08));
   _problems.push_back(Problem::Ptr(new Problem09));
   _problems.push_back(Problem::Ptr(new Problem10));
   _problems.push_back(Problem::Ptr(new Problem11));
   _problems.push_back(Problem::Ptr(new Problem12));
   _problems.push_back(Problem::Ptr(new Problem13));
   _problems.push_back(Problem::Ptr(new Problem14));
   _problems.push_back(Problem::Ptr(new Problem15));
   _problems.push_back(Problem::Ptr(new Problem16));
   _problems.push_back(Problem::Ptr(new Problem17));
   _problems.push_back(Problem::Ptr(new Problem18));
   _problems.push_back(Problem::Ptr(new Problem19));
   _problems.push_back(Problem::Ptr(new Problem20));
   _problems.push_back(Problem::Ptr(new Problem21));
   _problems.push_back(Problem::Ptr(new Problem22));
   _problems.push_back(Problem::Ptr(new Problem23));
   _problems.push_back(Problem::Ptr(new Problem24));
   _problems.push_back(Problem::Ptr(new Problem25));
   _problems.push_back(Problem::Ptr(new Problem26));
   _problems.push_back(Problem::Ptr(new Problem27));
   _problems.push_back(Problem::Ptr(new Problem28));
   _problems.push_back(Problem::Ptr(new Problem29));
   _problems.push_back(Problem::Ptr(new Problem30));
   _problems.push_back(Problem::Ptr(new Problem31));
   _problems.push_back(Problem::Ptr(new Problem32));
   _problems.push_back(Problem::Ptr(new Problem33));
   _problems.push_back(Problem::Ptr(new Problem34));
   _problems.push_back(Problem::Ptr(new Problem35));
   _problems.push_back(Problem::Ptr(new Problem36));
   _problems.push_back(Problem::Ptr(new Problem37));
   _problems.push_back(Problem::Ptr(new Problem38));
   _problems.push_back(Problem::Ptr(new Problem39));
   _problems.push_back(Problem::Ptr(new Problem40));
   _problems.push_back(Problem::Ptr(new Problem41));
   _problems.push_back(Problem::Ptr(new Problem42));
   _problems.push_back(Problem::Ptr(new Problem43));
   _problems.push_back(Problem::Ptr(new Problem44));
   _problems.push_back(Problem::Ptr(new Problem45));
   _problems.push_back(Problem::Ptr(new Problem46));
   _problems.push_back(Problem::Ptr(new Problem47));
   _problems.push_back(Problem::Ptr(new Problem48));
   _problems.push_back(Problem::Ptr(new Problem49));
   _problems.push_back(Problem::Ptr(new Problem50));
   _problems.push_back(Problem::Ptr(new Problem51));
   _problems.push_back(Problem::Ptr(new Problem52));
   _problems.push_back(Problem::Ptr(new Problem53));
   _problems.push_back(Problem::Ptr(new Problem54));
   _problems.push_back(Problem::Ptr(new Problem55));
   _problems.push_back(Problem::Ptr(new Problem56));
   _problems.push_back(Problem::Ptr(new Problem57));
   _problems.push_back(Problem::Ptr(new Problem58));
   _problems.push_back(Problem::Ptr(new Problem59));
   _problems.push_back(Problem::Ptr(new Problem60));
   _problems.push_back(Problem::Ptr(new Problem61));
   _problems.push_back(Problem::Ptr(new Problem62));
   _problems.push_back(Problem::Ptr(new Problem63));
   _problems.push_back(Problem::Ptr(new Problem64));
   _problems.push_back(Problem::Ptr(new Problem65));
   _problems.push_back(Problem::Ptr(new Problem66));
   _problems.push_back(Problem::Ptr(new Problem67));
   _problems.push_back(Problem::Ptr(new Problem68));
   _problems.push_back(Problem::Ptr(new Problem69));
   _problems.push_back(Problem::Ptr(new Problem70));
   _problems.push_back(Problem::Ptr(new Problem71));
   _problems.push_back(Problem::Ptr(new Problem72));
   _problems.push_back(Problem::Ptr(new Problem73));
   _problems.push_back(Problem::Ptr(new Problem74));
   _problems.push_back(Problem::Ptr(new Problem75));
   _problems.push_back(Problem::Ptr(new Problem76));
   _problems.push_back(Problem::Ptr(new Problem77));
   _problems.push_back(Problem::Ptr(new Problem78));
   _problems.push_back(Problem::Ptr(new Problem79));
   _problems.push_back(Problem::Ptr(new Problem80));
   _problems.push_back(Problem::Ptr(new Problem81));
   _problems.push_back(Problem::Ptr(new Problem82));
   _problems.push_back(Problem::Ptr(new Problem83));
   _problems.push_back(Problem::Ptr(new Problem84));
   _problems.push_back(Problem::Ptr(new Problem85));
   _problems.push_back(Problem::Ptr(new Problem86));
   _problems.push_back(Problem::Ptr(new Problem87));
   _problems.push_back(Problem::Ptr(new Problem88));
   _problems.push_back(Problem::Ptr(new Problem89));
   _problems.push_back(Problem::Ptr(new Problem90));
   _problems.push_back(Problem::Ptr(new Problem91));
   _problems.push_back(Problem::Ptr(new Problem92));
   _problems.push_back(Problem::Ptr(new Problem93));
   _problems.push_back(Problem::Ptr(new Problem94));
   _problems.push_back(Problem::Ptr(new Problem95));
   _problems.push_back(Problem::Ptr(new Problem96));
   _problems.push_back(Problem::Ptr(new Problem97));
   _problems.push_back(Problem::Ptr(new Problem98));
   _problems.push_back(Problem::Ptr(new Problem99));
}

ProblemLoader::~ProblemLoader()
{
   // Empty
}

Problem::Ptr ProblemLoader::load(int problemNumber)
{
   return _problems.at(problemNumber);
}

} /* namespace ProjectEuler */
} /* namespace Minigames */
