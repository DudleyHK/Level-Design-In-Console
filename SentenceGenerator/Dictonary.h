/*



*/
#pragma once
#include <string>
#include <random>
#include <vector>


/*I think this would be better reading from a JSON file. DO THIS LATER NOT NOW!!!!!!!!!*/
class Dictionary
{
public:

	enum LevelPart
	{
		SAFE_ZONE,
		PLATFORMING, 
		NEW_SKILL_LEARNING, 
		COMBAT, 
		PICK_UP_CACHE, 
		BOSS_ENCOUNTER
	};


public:
	Dictionary();
	~Dictionary() = default;


	const std::string getLevelPart(const LevelPart);

	// Grammar
	const std::string getSpace();
	const std::string getCommar();
	const std::string getFullStop();

	// CONTAINERS
	std::vector<std::string> safe_zones;
	std::vector<std::string> platforming;
	std::vector<std::string> new_skill_learning;
	std::vector<std::string> combat;
	std::vector<std::string> pick_up_cache;
	std::vector<std::string> boss_encounters;


private:

	//INITIALISATION
	void initAll();
	void initSafeZone();
	void initPlatforming();
	void initNewSkillLearning();
	void initCombat();
	void initPickUpCache();
	void initBossEncounter();

	/* Return level parts */
	const std::string getSafeZone(const int idx);
	const std::string getPlatforming(const int idx);
	const std::string getNewSkillLearning(const int idx);
	const std::string getCombat(const int idx);
	const std::string getPickUpCache(const int idx);
	const std::string getBossEncounter(const int idx);


	template<class Ty = int>
	const unsigned short getRandVal(Ty min, Ty max)
	{
		std::random_device rand_device;										// only used once to initialise (seed) engine
		std::mt19937 mt_engine(rand_device());								// random-number engine used (Mersenne-Twister in this case)
		std::uniform_int_distribution<unsigned short> uni_dist(min, max);  // guaranteed unbiased

		auto rand_val = uni_dist(mt_engine);
		return rand_val;
	}



	// GRAMMAR
	const std::string SPACE     = " ";
	const std::string FULL_STOP = ".";
	const std::string COMMAR    = ", ";


	// ERROR STR
	const std::string ERROR_SAFE_ZONE           = "ERROR_SAFE_ZONE";
	const std::string ERROR_PLATFORMING         = "ERROR_PLATFORMING";
	const std::string ERROR_NEW_SKILL_LEARNING  = "ERROR_NEW_SKILL_LEARNING";
	const std::string ERROR_COMBAT              = "ERROR_COMBAT";
	const std::string ERROR_PICK_UP_CACHE       = "ERROR_PICK_UP_CACHE";
	const std::string ERROR_BOSS_ENCOUNTER      = "ERROR_BOSS_ENCOUNTER";


// DEBUG
#ifdef _DEBUG
	/* Turn to true for sentence structure */
	const bool init_off = false;
#endif

};