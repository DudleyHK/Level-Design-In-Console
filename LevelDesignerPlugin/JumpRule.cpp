/*



*/
#include "JumpRule.h"
// ------------------------------
#include <fstream>
#include <random>

#include "jsoncons\json.hpp"
#include "jsoncons_ext\jsonpath\json_query.hpp"

using jsoncons::json;


void JumpRule::init()
{
	parseJson();
}



/* Generate a simple/ easy to complete level with a single easy jump.
*/
const std::string JumpRule::createEasy()
{
	auto length = getRandVal(4, 8);

	std::string easy_level = "";
	easy_level += basic_jump;

	unsigned short difference = length - easy_level.size();
	// is there space for another jump?
	while (difference > 0)
	{
		// is there space for another easy jump?
		if (difference >= basic_jump.size())
		{
			// shall we put a jump in?
			if (static_cast<bool>(getRandVal(0, 1)))
			{
				insertJump(easy_level, basic_jump);
			}
		}
		insertBlank(easy_level);
		difference = length - easy_level.size();
	}
	return easy_level;
}



/* Creates a intermediate level with a minimum of one medium jump and
possibly a single easy jump.*/
const std::string JumpRule::createMedium()
{
	auto length = getRandVal(5, 10);

	std::string medium_level = "";
	medium_level +=  intermediate_jump;

	unsigned short difference = length - medium_level.size();
	// is there space for another jump?
	while (difference > 0)
	{
		// is there space for another jump?
		if (difference >=  intermediate_jump.size())
		{
			// shall we put a jump in?
			if (static_cast<bool>(getRandVal(0, 1)))
			{
				insertJump(medium_level, basic_jump);
			}
		}
		insertBlank(medium_level);
		difference = length - medium_level.size();
	}
	return medium_level;
}


/*Creates a difficult level with one long jump and the possiblity of a middle jump. */
const std::string JumpRule::createHard()
{
	auto length = getRandVal(10, 15);

	std::string hard_level = "";
	hard_level +=  difficult_jump;

	unsigned short difference = length - hard_level.size();
	// is there space for another jump?
	while (difference > 0)
	{
		// is there space for another jump?
		if (difference >=  difficult_jump.size())
		{
			// shall we put a jump in?
			if (static_cast<bool>(getRandVal(0, 1)))
			{
				insertJump(hard_level,  intermediate_jump);
			}
		}
		insertBlank(hard_level);
		difference = length - hard_level.size();
	}
	return hard_level;
}

/*This is copied and pasted from internet*/
/*returns a random number which isn't bias to either end of the scale. */
const unsigned short JumpRule::getRandVal(int min, int max)
{
	std::random_device rand_device;                    // only used once to initialise (seed) engine
	std::mt19937 mt_engine(rand_device());             // random-number engine used (Mersenne-Twister in this case)
	std::uniform_int_distribution<unsigned short> uni_dist(min, max);  // guaranteed unbiased

	auto rand_val = uni_dist(mt_engine);
	return rand_val;
}


/*Inserts a blank tile randomly into the string. a check is done
so the tile doesnt break-up a jump. */
void JumpRule::insertBlank(std::string& level_str)
{
	while (true)
	{
		auto rand_idx = getRandVal(0, level_str.size());
		auto next_idx = rand_idx + 1;

		if (next_idx > level_str.size())
		{
			continue;
		}
		else
		{
			if (level_str[rand_idx] != 'J')
			{
				level_str.insert(rand_idx, "X");
				break;
			}
		}
	}
}

/*inserts a jump at the end of the string
TODO: to add some more randomnes decided at which point the obsticle should be added.*/
void JumpRule::insertJump(std::string& level_str, std::string jump)
{
	level_str.pop_back();
	level_str += jump;
}



/*Read the json file and unpack the rules. */
void JumpRule::parseJson()
{

	std::ifstream is(JUMP_DATA_PATH);

	json jumpData;
	is >> jumpData;

	for (const auto type : jumpData.members())
	{
		const auto& name = type.name();
		const auto& data = type.value();

		if (name == "Jump Pit")
			unpackRule(data.members());
	}
}

/*unpack the rule and get the string format of each obsticle type. I
used a template here because a) the type is incrediably long to type out and b)
I could find the exact type in the code. */
template<typename Members>
void JumpRule::unpackRule(Members members)
{
	for (const auto type : members)
	{
		const auto& name = type.name();
		const auto& data = type.value();

		auto format = data["Format"].as_string();

		if (name == "Basic")
		{
			basic_jump = format;
		}
		else if (name == "Intermediate")
		{
			 intermediate_jump = format;
		}
		else if (name == "Difficult")
		{
			 difficult_jump = format;
		}
		else
		{
			std::cout << "Invalid type found!!!" << std::endl;
		}
	}
}