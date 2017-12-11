/*



*/
#include <iostream>
#include <random>

#include "MarkovMain.h"



MarkovMain::MarkovMain()
{ 
	transition_matrix.reserve(64);
	denominators.reserve(32);
	current_sequence.reserve(32);
}


const bool MarkovMain::init()
{
	std::cout << "Enter a sequence of numbers: ";
	std::cin >> initial_sequence;
	std::cout << std::endl;

	std::cout << "How many permutations do you want? ";
	std::cin >> number_of_permutations;
	std::cout << std::endl;

	char selection_process = 'N';
	std::cout << "Choose which type of selection process is used" << std::endl;
	std::cout << "Press 'Y' to use probability. Press 'N' to flip a coin." << std::endl;
	std::cin >> selection_process;
	std::cout << std::endl;

	putchar(toupper(selection_process));
	switch (selection_process)
	{
	case 'Y': select_at_random = false; break;
	case 'N': select_at_random = true;  break;
	}

	std::cout << "Go!" << std::endl << std::endl << std::endl;

	std::cin.clear();



	sequence_total = initial_sequence.size();

	if(sequence_total <= 0)
	{
		std::cout << "ERROR: sequence_total = 0 in MarkovMain init()" << std::endl;
		return false;
	}

	std::cout << "Initial Sequence: ";
	for(unsigned short i = 0; i < sequence_total; i++)
	{
		float value = parseCharToFloat(initial_sequence[i]);
		current_sequence.push_back(value);

		std::cout << value;
	}
	std::cout << std::endl;
	
	return true;
}

void MarkovMain::run()
{
	for(unsigned short i = 1; i <= number_of_permutations; i++)
	{
		fillTransitionMatrix();
		fillDenominatorList();
		calculateProbability();
		createNewSequence(i);
	}

	outputFinalData();
}

// Initialise the transition_matrix grid and fill it. 
void MarkovMain::fillTransitionMatrix()
{
	for(unsigned short i = 0; i < (sequence_total - 1); i++)
	{		
		float from = current_sequence[i];
		float to   = current_sequence[i + 1];
		
		logDigit(from, to);
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
		// std::cout << "Row: " << from << " To: " << to << " Probability: " << value << std::endl;
	}
}


void MarkovMain::createNewSequence(const unsigned short permutation_index)
{
	std::vector<float> next_sequence;
	auto next_value = getStartValue();

	std::cout << "Permuation Sequence " << permutation_index << ": ";
	for(int i = 0; i < sequence_total; i++)
	{
		std::cout << next_value;
		next_sequence.push_back(next_value);

		auto probability_list = getProbabilityList(next_value);
		// if the list is empty pick a new number to go from.
		if(probability_list.size() <= 0)
		{
			next_value = getStartValue();
			continue;
		}
		next_value = selectNextValue(probability_list, select_at_random);
	}
	std::cout << std::endl;

	// Set new current sequence.
	current_sequence.clear();
	current_sequence = next_sequence;
	sequence_total = current_sequence.size();
}


const float MarkovMain::selectNextValue(const std::vector<std::pair<float, float>> probability_list, const bool select_at_random)
{
	float next_value = -1.f;
	while(next_value < 0)
	{
		for(auto value : probability_list)
		{
			if (!select_at_random)
			{
				// Use the probability
				if (chanceSelected(value.second))
				{
					next_value = value.first;
					break;
				}
			}
			else
			{
				// Use a 50% chance (flip a coin).
				if (chanceSelected(0.5f))
				{
					next_value = value.first;
					break;
				}
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
	for(auto& value : current_sequence)
	{
		if(getRandomFloat(0.f, 1.f) < 0.5f)
		{
			return value;
		}
	}
	return current_sequence[0];
}


const float MarkovMain::parseCharToFloat(const char character)
{
	return std::atof(&character);
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
	int index = 0;
	for(auto& container : transition_matrix)
	{
		// Get the row value (from) and the probability value (value).
		auto from = std::get<0>(container);
		auto value = std::get<2>(container);

		// If the denominator list doesn't contain the row value. 
		if(!pairContains(from, index))
		{
			// Add it to the list with a row total of zero.
			denominators.push_back({from, 0.f});
		}

		// add the probability value from the transition matrix. 
		// This will end up giving a total for each row.
 		denominators[index].second += value;
	}
}


// If the from_to container doesn't contain this combo. Log it. 
// Then, adjust the probablity of this combination accordinly. 
void MarkovMain::logDigit(const float from, const float to)
{
	int index = 0;
	if(!transitionMatrixContains(from, to, index))
	{
		transition_matrix.push_back({ from, to, 0.f });
	}
	auto container = transition_matrix[index];
	
	// Get the current probability at that index and increment it. 
	// The percentage can be found later.
	
	float x = std::get<2>(container);
	x++;
	std::get<2>(transition_matrix[index]) = x;

	// output to console
	// std::cout << "From: " << from << ". To: " << to << ". Hits: " << x << std::endl;
}

void MarkovMain::outputFinalData()
{
	std::cout << "______________________________" << std::endl;
	std::cout << "Final Transition Matrix Data: " << std::endl;
	for(auto& container : transition_matrix)
	{
		auto container_from  = std::get<0>(container);
		auto container_to    = std::get<1>(container);
		auto container_value = std::get<2>(container);

		std::cout << "From: " << container_from << " To: " << container_to << " Probability of: " << container_value << std::endl;


	}
}



const bool MarkovMain::pairContains(const float from, int& index)
{
	index = 0;
	for (auto& pair : denominators)
	{
		auto first = pair.first;
		if (first == from)
		{
			return true;
		}
		index++;
	}
	return false;
}

// Return true if the current combination has already been found.
const bool MarkovMain::transitionMatrixContains(const float from, const float to, int& index)
{
	index = 0;
	for (auto& container : transition_matrix)
	{
		auto container_from = std::get<0>(container);
		auto container_to   = std::get<1>(container);
	
		if (container_from == from && container_to == to)
		{
			return true;
		}
		index++;
	}
	return false;
}