/*



*/
#include <iostream>
#include <tuple>

#include "MarkovMain.h"



MarkovMain::MarkovMain()
{ 
	from_to_value.reserve(32);
	probabilities.reserve(32);
}


const bool MarkovMain::run()
{
	//transition_matrix = new Matrix();
	sequence_total = NUMBER_SEQUENCE.size();
	
	readData();
	adjustProbability();

	



	
	
	
	//transition_matrix->printMatrix();
	return true;
}


void MarkovMain::readData()
{
	for(unsigned short i = 0; i < (sequence_total - 1); i++)
	{
		// Parse the char to float.
		char from = NUMBER_SEQUENCE[i];
		char to   = NUMBER_SEQUENCE[i + 1];
		float from_value = std::atof(&from);
		float to_value   = std::atof(&to);

		// output to console
		std::cout << "From: " << from_value << ". To: " << to_value << std::endl;

		// log the values.
		logDigit(from_value, to_value);
	}
}



void MarkovMain::shutdown()
{
	//if (transition_matrix)
	//{
	//	delete transition_matrix;
	//	transition_matrix = nullptr;
	//		 
	//}
}


// Run through each from_to tuple and count how many times a from value appears.
// Then count how many and use this value as the denominator for the corrosponding row values.
void MarkovMain::adjustProbability()
{
	// Tally up each row.
	for(auto& tuple : from_to_value)
	{
		auto tuple_from = std::get<0>(tuple);

		if (!pairContains(tuple_from))
		{
			probabilities.push_back({ tuple_from, 1.f });
		}
		else
		{
			auto index = getPairListID(tuple_from);
			auto probabilities_pair = probabilities[index];

			probabilities_pair.second++;
		}
	}

	// Get the probablity value for each row.
	for (auto& tuple : from_to_value)
	{
		auto tuple_from  = std::get<0>(tuple);
		auto tuple_value = std::get<2>(tuple);

		auto index = getPairListID(tuple_from);
		auto denominator = probabilities[index].second;

		tuple_value = tuple_value / denominator;
		std::get<2>(tuple) = tuple_value;
	}
}


// If the from_to container doesn't contain this combo. Log it. 
// Then, adjust the probablity of this combination accordinly. 
void MarkovMain::logDigit(const float from, const float to)
{
	if(!tupleContains(from, to))
	{
		from_to_value.push_back({ from, to, 0.f });
	}
	
	auto index = getTupleListID(from, to);
	auto row_tuple = from_to_value[index];

	// Get the current probability at that index and increment it. 
	// The percentage can be found later.
	float x = std::get<2>(row_tuple);
	x++;
	std::get<2>(row_tuple) = x;
}



const bool MarkovMain::pairContains(const float from)
{
	for (auto& pair : probabilities)
	{
		auto first = pair.first;
		if (first == from)
		{
			return true;
		}
	}
	return false;
}

const unsigned short MarkovMain::getPairListID(const float from)
{
	unsigned short i = 0;
	for (auto& pair : probabilities)
	{
		auto first = pair.first;
		if (first == from)
		{
			return i;
		}
		i++;
	}
	return i;
}


// Return true if the current combination has already been found.
const bool MarkovMain::tupleContains(const float from, const float to)
{
	for (auto& tuple : from_to_value)
	{
		auto tuple_from = std::get<0>(tuple);
		auto tuple_to   = std::get<1>(tuple);

		if (tuple_from == from && tuple_to == to)
		{
			return true;
		}
	}
	return false;
}



const unsigned short MarkovMain::getTupleListID(const float from, const float to)
{
	unsigned short i = 0;
	for (auto& tuple : from_to_value)
	{
		auto tuple_from = std::get<0>(tuple);
		auto tuple_to = std::get<1>(tuple);

		if (tuple_from == from && tuple_to == to)
		{
			return i;
		}
		i++;
	}
	return i;
}
