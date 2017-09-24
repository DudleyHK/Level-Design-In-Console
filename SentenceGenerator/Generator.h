/*



*/
#pragma once

#include <string>
#include <random>
#include <vector>



class Generator
{
public:
	Generator();
	~Generator() = default;

	const std::string generate();

	template<class Ty = int>
	const unsigned short getRandVal(Ty min, Ty max)
	{
		std::random_device rand_device;                    // only used once to initialise (seed) engine
		std::mt19937 mt_engine(rand_device());             // random-number engine used (Mersenne-Twister in this case)
		std::uniform_int_distribution<unsigned short> uni_dist(min, max);  // guaranteed unbiased

		auto rand_val = uni_dist(mt_engine);
		return rand_val;
	}


private:

	void init();

	std::vector<std::string> nouns        = { "" };
	std::vector<std::string> verbs        = { "" };
	std::vector<std::string> adjectives   = { "" };
	std::vector<std::string> adverbs	  = { "" };
	std::vector<std::string> pronouns	  = { "" };
	std::vector<std::string> prepositions = { "" };
	std::vector<std::string> conjunctions = { "" };
	std::vector<std::string> determiners  = { "" };

	const std::string SPACE = " ";


};



