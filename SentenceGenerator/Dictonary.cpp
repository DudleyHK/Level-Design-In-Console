/*



*/
#include "Dictonary.h"



Dictionary::Dictionary()
{
	nouns.reserve(10);
	verbs.reserve(10);
	adjectives.reserve(10);
	adverbs.reserve(10);
	pronouns.reserve(10);
	prepositions.reserve(10);
	conjunctions.reserve(10);
	determiners.reserve(10);

	initAll();

}



void Dictionary::initAll()
{
#ifdef _DEBUG
	if (init_off)
		return;
#endif // DEBUG

	initNouns();
	initVerbs();
	initAdjectives();
	initAdverbs();
	initPronouns();
	initPrepositions();
	initConjunctions();
	initDeterminers();
}


void Dictionary::initNouns()
{
	nouns =
	{
		"boy","girl","cat","dog","man","woman",
		"country", "nation", "state", "county"
		"city",
		//"birth",
		//"danger",
		//"time",
		//"Africa",
		//"coffee",
		"rainfall",
		//"audience",
	};
}



void Dictionary::initVerbs()
{
	verbs =
	{
		"jump",
		"stop",
		"explore",
		"be",
		"snow",
		"evolve",
		"shrink",
		"stop",
		"happen",
		"have"
	};
}



void Dictionary::initAdjectives()
{
	adjectives =
	{
		"excited",
		"green",
		"tidy",
		"lush",
		"newest",
		"special",
		"tasty",
		"hot",
		"cold",
		"nasty"

	};
}



void Dictionary::initAdverbs()
{
	adverbs =
	{
		"fast",
		"loudly",
		"patiently",
		"fast",
		"loudly",
		"patiently",
		"now",
		"recently",
		"nearly",
		"gently"

	};
}



void Dictionary::initPronouns()
{
	pronouns =
	{
		"I",
		"he",
		"she",
		"little",
		"both"
	};
}



void Dictionary::initPrepositions()
{
	prepositions =
	{
		"from",
		"for",
		"after",
		"in",
		"to",
		"on"
	};
}



void Dictionary::initConjunctions()
{	conjunctions =
	{
		"but",
		"for",
		"if",
		"or",
		"and",
		"when"
	};
}



void Dictionary::initDeterminers()
{
	determiners =
	{
		"a",
		"the",
		"every",
		"this"
	};
}



std::string Dictionary::getNouns(const int idx)
{
	return !nouns.empty() ? nouns[idx] : ERROR_NOUN;
}



std::string Dictionary::getVerbs(const int idx)
{
	return !verbs.empty() ? verbs[idx] : ERROR_VERB;
}



std::string Dictionary::getAdjectives(const int idx)
{
	return !adjectives.empty() ? adjectives[idx] : ERROR_ADJECTIVE;
}



std::string Dictionary::getAdverbs(const int idx)
{
	return !adverbs.empty() ? adverbs[idx] : ERROR_ADVERB;
}



std::string Dictionary::getPronouns(const int idx)
{
	return !pronouns.empty() ? pronouns[idx] : ERROR_PRONOUN;
}



std::string Dictionary::getPrepositions(const int idx)
{
	return !prepositions.empty() ? prepositions[idx] : ERROR_PREPOS;
}



std::string Dictionary::getConjunctions(const int idx)
{
	return !conjunctions.empty() ? conjunctions[idx] : ERROR_CONJUNC;
}



std::string Dictionary::getDeterminers(const int idx)
{
	return !determiners.empty() ? determiners[idx] : ERROR_DETERM;
}



const std::string Dictionary::getSpace()
{
	return SPACE;
}



const std::string Dictionary::getFullStop()
{
	return FULL_STOP;
}


