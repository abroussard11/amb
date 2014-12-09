/*
 * Library.cpp
 *
 *  Created on: Dec 6, 2014
 *      Author: aaron
 */

#include <Minigames/MadLib/Library.h>

namespace Minigames {
namespace MadLib {

const std::string Library::LetterFromCamp =
"Dear [RELATIVE], \n\
 I am having a(n) [ADJECTIVE] time at camp. The counselor is [ADJECTIVE] and the food is [ADJECTIVE].\
 I met [NAME OF PERSON] and we became [ADJECTIVE] friends. Unfortunately, [SAME NAME OF PERSON] is [ADJECTIVE]\
 and I [VERB ENDING IN 'ED'] my [BODY PART]\
 so we couldn`t go [VERB ENDING IN 'ING'] like everybody else. I need more [PLURAL NOUN] and a [NOUN] sharpener, so please\
 [ADVERB] [VERB] more when you [VERB] back.\n\
 Your [TYPE OF RELATIVE],\n\
 [MY NAME] \n";

Library::~Library()
{
   // Empty
}

} /* namespace MadLib */
} /* namespace Minigames */
