/*



*/
#include "Generator.h"
// ----------------------------------





Generator::Generator() :
	dictionary(std::make_unique<Dictionary>())
{ }



const std::string Generator::generate()
{
	sentence = "";
	addSentence();
	fixGrammar();

	return !sentence.empty() ? sentence : "ERROR_SENTENCE_EMPTY";
}


void Generator::addSentence()
{
	auto connect = false;
	for (auto i = 0; i < totalClauses; i++)
	{
		// TODO: for more than one phrase
		if (i % 2 == 0)
		{
			connect = false;
		}
		else
		{
			connect = true;
		}
		addClause(connect);	
	}
}


/* Add a conjunciton if the sentence will be connected to another sentence. */
void Generator::addClause(const bool connect)
{
	addPhrase();
	
	if(connect)
		addConjunction();

}



void Generator::addPhrase()
{
	auto flip_coin = getRandVal(0, 1);
	
	//if(flip_coin) 
		addNounPhrase();
	//else          
	//	addPronounPhrase();

	addVerbPhrase();
	addNounPhrase();
}



void Generator::addNounPhrase()
{
	addDeterminer();
	addAdjective();
	addNoun();
}



void Generator::addPronounPhrase()
{
	addPronoun();
	addPreposition();
}



void Generator::addVerbPhrase()
{
	addAdverb();
	addVerb();
	addPreposition();
}



void Generator::addDeterminer()
{
	auto rand_determiner = getRandVal(0, 4);
	sentence += dictionary->getDeterminers(rand_determiner);
	addSpace();
}



void Generator::addConjunction()
{
	auto rand_conjunc = getRandVal(0, 5);
	sentence += dictionary->getConjunctions(rand_conjunc);
	addSpace();
}


void Generator::addAdjective()
{
	auto rand_adj = getRandVal(0, 9);
	sentence += dictionary->getCombat(rand_adj);
	addSpace();
}



void Generator::addNoun()
{
	auto size = static_cast<int>(dictionary->platforming.size());
	auto rand_noun = getRandVal(0, size); 
	sentence += dictionary->getPlatforming(rand_noun);
	addSpace();
}



void Generator::addPronoun()
{
	auto rand_pronoun = getRandVal(0, 4);
	sentence += dictionary->getBossEncounter(rand_pronoun);
	addSpace();
}



void Generator::addVerb()
{
	auto rand_verb = getRandVal(0, 9);         
	sentence += dictionary->getNewSkillLearning(rand_verb);
	addSpace();
}



void Generator::addAdverb()
{
	auto rand_adverb = getRandVal(0, 9);
	sentence += dictionary->getPickUpCache(rand_adverb);
	addSpace();
}



void Generator::addPreposition()
{
	auto rand_prepos = getRandVal(0, 5);
	sentence += dictionary->getPrepositions(rand_prepos);
	addSpace();
}




/* Currently:
- Make first letter uppercase
- Add fullstop
*/
void Generator::fixGrammar()
{
	// make a copy just incase something happens to the sentence.
	auto sentence_temp = sentence;
	if (!sentence_temp.empty())
	{
		sentence_temp[0] = toupper(sentence_temp.front());
		
		// Remove the space at the end of the string. 
		sentence_temp.pop_back();
		sentence_temp.append(dictionary->getFullStop());
	}
	sentence = sentence_temp;
}


void Generator::addSpace()
{
	sentence += dictionary->getSpace();
}
