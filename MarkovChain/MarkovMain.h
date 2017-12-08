/*



*/
#pragma once
#include <string>
#include <tuple>
#include <vector>

#include "Matrix.h"


class MarkovMain
{
public:
	MarkovMain();
	~MarkovMain() = default;

	const bool run();
	void shutdown();


private:
	void fillTransitionMatrix();
	void fillDenominatorList();
	void calculateProbability();
	void outputSequence();
	const float selectNextValue(const std::vector<std::pair<float, float>> probability_list);
	const float getDenominator(const float from);
	const float getRandomFloat(const float min_inclusive, const float max_exculsive);
	const float getStartValue();
	const bool  chanceSelected(const float probability);
	const std::vector<std::pair<float, float>> getProbabilityList(const float from_value);

	void logDigit(const float digit, const float previous_value);
	const bool pairContains(const float from);
	const unsigned short getPairListID(const float from);
	const bool tupleContains(const float from, const float to);
	const unsigned short getTupleListID(const float from, const float to);



	//Matrix* transition_matrix;
	const std::string INITIAL_SEQUENCE = "987235234"; // Enter string of numbers between 1 and 4
	unsigned short sequence_total = 0;



	std::vector<std::tuple<float, float, float>> transition_matrix;
	std::vector<std::pair<float, float>> denominators;
	std::vector<float> initial_sequence;
};