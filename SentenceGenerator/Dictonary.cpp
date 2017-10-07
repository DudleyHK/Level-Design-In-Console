/*



*/
#include "Dictonary.h"



Dictionary::Dictionary()
{
	platforming.reserve(10);
	newSkillLearning.reserve(10);
	combat.reserve(10);
	pickUpCache.reserve(10);
	bossEncounters.reserve(10);

	initAll();

}



void Dictionary::initAll()
{
	#ifdef _DEBUG
	if (init_off)
		return;
	#endif // DEBUG

	initPlatforming();
	initNewSkillLearning();
	initCombat();
	initPickUpCache();
	initBossEncounter();
}


void Dictionary::initPlatforming()
{
	platforming =
	{
		"boy","girl","cat","dog","man","woman",
		"country", "nation", "state", "county"
		"city",
		"rainfall"
	};
}



void Dictionary::initNewSkillLearning()
{
	newSkillLearning =
	{
		"jump",
		"stop",
		"explore",
		"be",
		"snow",
		"evolve",
		"shrink",
		"stop",
		"happen",
		"have"
	};
}



void Dictionary::initCombat()
{
	combat =
	{
		"excited",
		"green",
		"tidy",
		"lush",
		"newest",
		"special",
		"tasty",
		"hot",
		"cold",
		"nasty"

	};
}



void Dictionary::initPickUpCache()
{
	pickUpCache =
	{
		"fast",
		"loudly",
		"patiently",
		"fast",
		"loudly",
		"patiently",
		"now",
		"recently",
		"nearly",
		"gently"

	};
}



void Dictionary::initBossEncounter()
{
	bossEncounters =
	{
		"I",
		"he",
		"she",
		"little",
		"both"
	};
}


std::string Dictionary::getPlatforming(const int idx)
{
	return !platforming.empty() ? platforming[idx] : ERROR_PLATFORMING;
}



std::string Dictionary::getNewSkillLearning(const int idx)
{
	return !newSkillLearning.empty() ? newSkillLearning[idx] : ERROR_NEW_SKILL_LEARNING;
}



std::string Dictionary::getCombat(const int idx)
{
	return !combat.empty() ? combat[idx] : ERROR_COMBAT;
}



std::string Dictionary::getPickUpCache(const int idx)
{
	return !pickUpCache.empty() ? pickUpCache[idx] : ERROR_PICK_UP_CACHE;
}



std::string Dictionary::getBossEncounter(const int idx)
{
	return !bossEncounters.empty() ? bossEncounters[idx] : ERROR_BOSS_ENCOUNTER;
}



const std::string Dictionary::getSpace()
{
	return SPACE;
}



const std::string Dictionary::getFullStop()
{
	return FULL_STOP;
}


