/*



*/
#pragma once
#include <string>
#include <vector>

#include "Matrix.h"


class MarkovMain
{
public:
	MarkovMain();
	~MarkovMain() = default;

	const bool run();
	void readData();

	void shutdown();
private:
	void adjustProbability();
	void logDigit(const float digit, const float previous_value);
	const bool pairContains(const float from);
	const unsigned short getPairListID(const float from);
	const bool tupleContains(const float from, const float to);
	const unsigned short getTupleListID(const float from, const float to);



	//Matrix* transition_matrix;
	const std::string NUMBER_SEQUENCE = "111234354"; // Enter string of numbers between 1 and 4
	unsigned short sequence_total = 0;



	std::vector<std::tuple<float, float, float>> from_to_value;
	//	Layout of tuple vector.
	//	1 1 = 0.5
	//	1 2 = 0
	//	1 3 = 0.5
	//	1 4 = 0 
	//  2 1 = 0.34
	// ect
	std::vector<std::pair<float, float>> probabilities;
};