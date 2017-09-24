/*



*/
#include "Generator.h"

Generator::Generator() 
{
	nouns.reserve(10);
	verbs.reserve(10);
	adjectives.reserve(10);
	adverbs.reserve(10);
	pronouns.reserve(10);
	prepositions.reserve(10);
	conjunctions.reserve(10);
	determiners.reserve(10);

	init();
}

void Generator::init()
{
	/* NOUNS */
	nouns =
	{
		"boy",
		"country",
		"city",
		"birth",
		"danger",
		"time",
		"Africa",
		"coffee",
		"rain",
		"audience"
	};

	/* VERBS */
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

	/* ADJECTIVES */
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

	adverbs =
	{
		"fast",
		"loudly",
		"patiently",
		"fast",
		"loudly",
		"patiently",
		"now",
		"recently"

	};
	pronouns =
	{
		"I",
		"he",
		"she",
		"little",
		"both"
	};
	prepositions =
	{
		"from",
		"for",
		"after",
		"in",
		"to",
		"on"
	};

	conjunctions =
	{
		"but",
		"for",
		"if",
		"or",
		"and",
		"when"
	};

	determiners =
	{
		"a",
		"the",
		"every",
		"this",
		"those"
	};


}

const std::string Generator::generate()
{
	std::string new_str = "";

	new_str += pronouns[getRandVal(0, 4)]    + SPACE;
	new_str += verbs[getRandVal(0, 9)]       + SPACE;
	new_str += determiners[getRandVal(0, 4)] + SPACE;
	new_str += nouns[getRandVal(0, 9)];
	return new_str;
}




