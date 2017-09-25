/*



*/
#pragma once

#include <string>
#include <random>
#include <memory>
#include <vector>

#include "Dictonary.h"



class Generator
{
public:
	Generator();
	~Generator() = default;

	const std::string generate();
	const std::string grammar(std::string sentence);

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
	std::unique_ptr<Dictionary> dictionary = nullptr;
};



