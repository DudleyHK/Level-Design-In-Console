/*



*/
#pragma once
#include <string>
#include <vector>


/*I think this would be better reading from a JSON file. DO THIS LATER NOT NOW!!!!!!!!!*/
class Dictionary
{
public:
	Dictionary();
	~Dictionary() = default;

	// 
	std::string getPlatforming(const int idx);
	std::string getNewSkillLearning(const int idx);
	std::string getCombat(const int idx);
	std::string getPickUpCache(const int idx);
	std::string getBossEncounter(const int idx);

	// Grammar
	const std::string getSpace();
	const std::string getFullStop();

	// CONTAINERS
	std::vector<std::string> platforming;
	std::vector<std::string> newSkillLearning;
	std::vector<std::string> combat;
	std::vector<std::string> pickUpCache;
	std::vector<std::string> bossEncounters;


private:

	//INITIALISATION
	void initAll();
	void initPlatforming();
	void initNewSkillLearning();
	void initCombat();
	void initPickUpCache();
	void initBossEncounter();



	// GRAMMAR
	const std::string SPACE     = " ";
	const std::string FULL_STOP = ".";


	// ERROR STR
	const std::string ERROR_PLATFORMING         = "ERROR_PLATFORMING";
	const std::string ERROR_NEW_SKILL_LEARNING  = "ERROR_NEW_SKILL_LEARNING";
	const std::string ERROR_COMBAT              = "ERROR_COMBAT";
	const std::string ERROR_PICK_UP_CACHE       = "ERROR_PICK_UP_CACHE";
	const std::string ERROR_BOSS_ENCOUNTER      = "ERROR_BOSS_ENCOUNTER";


// DEBUG
#ifdef _DEBUG
	/*Turn to true for sentence structure*/
	const bool init_off = false;
#endif

};