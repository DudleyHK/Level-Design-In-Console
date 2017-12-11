/*



*/
#pragma once
#include <string>
#include <tuple>
#include <vector>


class MarkovMain
{
public:
	MarkovMain();
	~MarkovMain() = default;

	const bool init();
	void run();
	void shutdown();


private:
	void fillTransitionMatrix();
	void fillDenominatorList();
	void calculateProbability();
	void createNewSequence(const unsigned short permutation_index);
	void logDigit(const float digit, const float previous_value);
	void outputFinalData();
	const float selectNextValue(const std::vector<std::pair<float, float>> probability_list, const bool select_at_random = false);
	const float getDenominator(const float from);
	const float getRandomFloat(const float min_inclusive, const float max_exculsive);
	const float getStartValue();
	const float parseCharToFloat(const char character);
	const bool  chanceSelected(const float probability);
	const bool  pairContains(const float from, int& index);
	const bool  transitionMatrixContains(const float from, const float to, int& index);
	const std::vector<std::pair<float, float>> getProbabilityList(const float from_value);


	std::vector<std::tuple<float, float, float>> transition_matrix;
	std::vector<std::pair<float, float>> denominators;
	std::vector<float> current_sequence;

	std::string initial_sequence = "";
	unsigned short number_of_permutations = 0;
	unsigned short sequence_total = 0;
	bool select_at_random = false;
};