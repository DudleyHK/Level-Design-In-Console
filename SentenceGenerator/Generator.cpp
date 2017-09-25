/*



*/
#include "Generator.h"
// ----------------------------------





Generator::Generator() :
	dictionary(std::make_unique<Dictionary>())
{

}



const std::string Generator::generate()
{
	std::string sentence = "";

	auto rand_verb       = getRandVal(0, 9);
	auto rand_noun       = getRandVal(0, 9);
	auto rand_pronoun    = getRandVal(0, 4);
	auto rand_determiner = getRandVal(0, 3);
	
	sentence += dictionary->getPronouns   (rand_pronoun)    + dictionary->getSpace();
	sentence += dictionary->getVerbs      (rand_verb)       + dictionary->getSpace();
	sentence += dictionary->getDeterminers(rand_determiner) + dictionary->getSpace();
	sentence += dictionary->getNouns      (rand_noun);

	return grammar(sentence);
}



/* Currently:
	- Make first letter uppercase
	- Add fullstop
*/
const std::string Generator::grammar(std::string sentence)
{
	// make a copy just incase something happens to the sentence.
	auto sentence_temp = sentence;
	if (!sentence_temp.empty())
	{
		sentence_temp[0] = toupper(sentence_temp.front());
		sentence_temp.append(dictionary->getFullStop());
	}
	return sentence_temp;
}




