/*



*/
#include "Dictonary.h"



Dictionary::Dictionary()
{
	platforming.reserve(11);
	new_skill_learning.reserve(10);
	combat.reserve(10);
	pick_up_cache.reserve(10);
	boss_encounters.reserve(10);

	initAll();

}



void Dictionary::initAll()
{
	#ifdef _DEBUG
	if (init_off)
		return;
	#endif // DEBUG

	initSafeZone();
	initPlatforming();
	initNewSkillLearning();
	initCombat();
	initPickUpCache();
	initBossEncounter();
}

void Dictionary::initSafeZone()
{
	safe_zones =
	{
		"small cave",
		"little room", 
		"grand hall", 
		"garden"

	};
}


void Dictionary::initPlatforming()
{
	platforming =
	{
		"ledge up",
		"ledge down",
		"slope up",
		"slope down",
		"thin path",
		"wide open space",
		"corridor",
		"stairs up",
		"stairs down",
		"ladder down",
		"ladder up"
	};
}



void Dictionary::initNewSkillLearning()
{
	new_skill_learning =
	{
		"learn wall run", 
		"learn swing", 
		"learn run jump"
	};
}



void Dictionary::initCombat()
{
	combat =
	{
		"fight with two swordsmen", 
		"fight with one longsword knight", 
		"fight with samurai", 
		"fight with ninja", 
		"fight with tiger"
	};
}



void Dictionary::initPickUpCache()
{
	pick_up_cache =
	{
		"pick up gold", 
		"pick up gems", 
		"pick up xp", 
		"pick up chest", 
		"pick up nothing"
	};
}



void Dictionary::initBossEncounter()
{
	boss_encounters =
	{
		"boss fight with Lizard King", 
		"boss fight with Skelaton Knight", 
		"boss fight with Slime Ball", 
		"boss fight with Queen Fuzzy Kitten Killer", 
		"boss fight with Purple Blob"
	};
}


const std::string Dictionary::getLevelPart(const LevelPart part)
{
	std::string level_part = "";
	int size = 0;

	switch (part)
	{
		case SAFE_ZONE:
			size = safe_zones.size() - 1;
			level_part = getSafeZone(getRandVal(0, size));
			break;

		case PLATFORMING:
			size = platforming.size() - 1;
			level_part = getPlatforming(getRandVal(0, size));
			break;

		case NEW_SKILL_LEARNING:
			size = new_skill_learning.size() - 1;
			level_part = getNewSkillLearning(getRandVal(0, size));
			break;

		case COMBAT:
			size = combat.size() - 1;
			level_part = getCombat(getRandVal(0, size));
			break;

		case PICK_UP_CACHE:
			size = pick_up_cache.size() - 1;
			level_part = getPickUpCache(getRandVal(0, size));
			break;

		case BOSS_ENCOUNTER:
			size = boss_encounters.size() - 1;
			level_part = getBossEncounter(getRandVal(0, size));
			break;

		default:
			break;
	}
	return level_part;
}




const std::string Dictionary::getSafeZone(const int idx)
{
	return !safe_zones.empty() ? safe_zones[idx] : ERROR_SAFE_ZONE;
}



const std::string Dictionary::getPlatforming(const int idx)
{
	return !platforming.empty() ? platforming[idx] : ERROR_PLATFORMING;
}



const std::string Dictionary::getNewSkillLearning(const int idx)
{
	return !new_skill_learning.empty() ? new_skill_learning[idx] : ERROR_NEW_SKILL_LEARNING;
}



const std::string Dictionary::getCombat(const int idx)
{
	return !combat.empty() ? combat[idx] : ERROR_COMBAT;
}



const std::string Dictionary::getPickUpCache(const int idx)
{
	return !pick_up_cache.empty() ? pick_up_cache[idx] : ERROR_PICK_UP_CACHE;
}



const std::string Dictionary::getBossEncounter(const int idx)
{
	return !boss_encounters.empty() ? boss_encounters[idx] : ERROR_BOSS_ENCOUNTER;
}



const std::string Dictionary::getSpace()
{
	return SPACE;
}


const std::string Dictionary::getCommar()
{
	return COMMAR;
}



const std::string Dictionary::getFullStop()
{
	return FULL_STOP;
}


