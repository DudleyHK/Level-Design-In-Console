/*



*/
#include <iostream>
#include <random>

#include "MarkovMain.h"



MarkovMain::MarkovMain()
{ 
	transition_matrix.reserve(64);
	denominators.reserve(32);
	initial_sequence.reserve(32);
}


const bool MarkovMain::run()
{
	//transition_matrix = new Matrix();
	sequence_total = INITIAL_SEQUENCE.size();
	std::cout << "First Sequence: " << INITIAL_SEQUENCE << std::endl;
	
	fillTransitionMatrix();
	fillDenominatorList();
	calculateProbability();

	
	outputSequence();
	

	//transition_matrix->printMatrix();
	return true;
}

// Initialise the transition_matrix grid and fill it. 
void MarkovMain::fillTransitionMatrix()
{
	for(unsigned short i = 0; i < (sequence_total - 1); i++)
	{
		// Parse the char to float.
		char from = INITIAL_SEQUENCE[i];
		char to   = INITIAL_SEQUENCE[i + 1];
		float from_value = std::atof(&from);
		float to_value   = std::atof(&to);
	
		// Fill initial sequence with numbers.
		initial_sequence.push_back(from_value);
		initial_sequence.push_back(0.f);
		initial_sequence[i + 1] = to_value;

		// log the values.
		logDigit(from_value, to_value);
	}
}



void MarkovMain::calculateProbability()
{
	// for each value in the transition matrix
	for(auto i = 0; i < transition_matrix.size(); i++)
	{
		auto& container = transition_matrix[i];

		// get the row value(from) and the probability value (value).
		auto from = std::get<0>(container);
		auto to   = std::get<1>(container);
		auto value = std::get<2>(container);

		// Find the corralating denominator using the row value (from).
		auto denominator = getDenominator(from);
		if(denominator < 0)
		{
			std::cout << "ERROR: Invalid return type from denominator list" << std::endl;
			continue;
		} 

		// the probability is equal to itself over the rows total.
		value /= denominator;
		std::get<2>(transition_matrix[i]) = value;


		// output to console
		// std::cout << "Row: " << from << " To: " << to << " Probability: " << value << std::endl;


	}
}


void MarkovMain::outputSequence()
{
	auto next_value = getStartValue();
	std::vector<std::pair<float, float>> probability_list;

	std::cout << "Next sequence: ";
	for(int i = 0; i < INITIAL_SEQUENCE.size(); i++)
	{
		std::cout << next_value;
		probability_list = getProbabilityList(next_value);

		// if the list is empty pick a new number to go from.
		if(probability_list.size() <= 0)
		{
			next_value = getStartValue();
			continue;
		}

		next_value = selectNextValue(probability_list);
	}
	std::cout << std::endl;
}




const float MarkovMain::selectNextValue(const std::vector<std::pair<float, float>> probability_list)
{
	float next_value = -1.f;
	while(next_value < 0)
	{
		for(auto value : probability_list)
		{
			if(chanceSelected(value.second))
			{
				next_value = value.first;
			}
		}
	}
	return next_value;
}




const float MarkovMain::getDenominator(const float from)
{
	for(auto& container : denominators)
	{
		if(container.first == from)
		{
			return container.second;
		}
	}
	return -1.f;
}


const float MarkovMain::getRandomFloat(const float min_inclusive, const float max_exclusive)
{
	std::random_device rand_device;                    // only used once to initialise (seed) engine
	std::mt19937 mt_engine(rand_device());             // random-number engine used (Mersenne-Twister in this case)
	std::uniform_real_distribution<float> unif(min_inclusive, max_exclusive);  // guaranteed unbiased

	auto rand_val = unif(mt_engine);
	//std::cout << rand_val << std::endl;
	return rand_val;
}

 
const bool MarkovMain::chanceSelected(const float probability)
{
	return getRandomFloat(0.f, 1.f) < probability;
}

const float MarkovMain::getStartValue()
{
	for(auto& value : initial_sequence)
	{
		if(getRandomFloat(0.f, 1.f) < 0.5f)
		{
			return value;
		}
	}
	return initial_sequence[0];
}

// Return a list with each number, value, can go to. Along with the probability.
const std::vector<std::pair<float, float>> MarkovMain::getProbabilityList(const float from_value)
{
	std::vector<std::pair<float, float>> probability_list;

	for(auto& container : transition_matrix)
	{
		auto from = std::get<0>(container);
		auto to = std::get<1>(container);
		auto value = std::get<2>(container);

		if(from == from_value)
		{
			probability_list.push_back({to, value});
		}
	}
	return probability_list;
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



// Tally up each row to get the denominator value. 
void MarkovMain::fillDenominatorList()
{
	for(auto& container : transition_matrix)
	{
		// Get the row value (from) and the probability value (value).
		auto from = std::get<0>(container);
		auto value = std::get<2>(container);

		// If the denominator list doesn't contain the row value. 
		if(!pairContains(from))
		{
			// Add it to the list with a row total of zero.
			denominators.push_back({from, 0.f});
		}

		// find the index at which this row value sits in the denominator list.
		auto index = getPairListID(from);

		// add the probability value from the transition matrix. 
		// This will end up giving a total for each row.
		denominators[index].second += value;
	}
}


// If the from_to container doesn't contain this combo. Log it. 
// Then, adjust the probablity of this combination accordinly. 
void MarkovMain::logDigit(const float from, const float to)
{
	if(!tupleContains(from, to))
	{
		transition_matrix.push_back({ from, to, 0.f });
	}
	
	auto index = getTupleListID(from, to);
	auto row_tuple = transition_matrix[index];
	
	// Get the current probability at that index and increment it. 
	// The percentage can be found later.
	float x = std::get<2>(row_tuple);
	x++;
	std::get<2>(transition_matrix[index]) = x;

	// output to console
	// std::cout << "From: " << from << ". To: " << to << ". Hits: " << x << std::endl;
}



const bool MarkovMain::pairContains(const float from)
{
	for (auto& pair : denominators)
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
	for (auto& pair : denominators)
	{
		auto first = pair.first;
		if (first == from)
		{
			return i;
		}
		i++;
	}
	return  i;
}


// Return true if the current combination has already been found.
const bool MarkovMain::tupleContains(const float from, const float to)
{
	for (auto& tuple : transition_matrix)
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
	for (auto& tuple : transition_matrix)
	{
		auto tuple_from = std::get<0>(tuple);
		auto tuple_to = std::get<1>(tuple);
	
		if (tuple_from == from && tuple_to == to)
		{
			return i;
		}
		i++;
	}
	return  i;
}
