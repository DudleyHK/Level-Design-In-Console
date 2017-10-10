/*



*/
#include "Generator.h"
// ----------------------------------





Generator::Generator() :
	dictionary(std::make_unique<Dictionary>())
{ }



const std::string Generator::generate()
{
	sentence = "";
	addLevel();
	fixGrammar();

	return !sentence.empty() ? sentence : "ERROR_SENTENCE_EMPTY";
}



/* Layer One */
void Generator::addLevel()
{
	addFirstPhase();
	addCentralPhase();
	addEndPhase();
}


/* Layer Two */
void Generator::addFirstPhase()
{
	safeSection();
	learnSection();
}




void Generator::addCentralPhase()
{
	conflictSection();
	gainSection();
}



void Generator::addEndPhase()
{
	endBossSection();
}


/* Layer Three */
void Generator::safeSection()
{
	addSafeZone();
	addPlatforming();
}



void Generator::learnSection()
{
	addNewSkillLearning();
	addPlatforming();
}



void Generator::conflictSection()
{
	addCombat();
}



void Generator::gainSection()
{
	addPlatforming();
	addPickupCache();
}



void Generator::endBossSection()
{
	addPlatforming();
	addBossEncounter();
	addPlatforming();
}





/* Layer Four */
void Generator::addSafeZone()
{
	sentence += dictionary->getLevelPart(Dictionary::LevelPart::SAFE_ZONE);
	addSpace();
}


void Generator::addPlatforming()
{
	sentence += dictionary->getLevelPart(Dictionary::LevelPart::PLATFORMING);
	addSpace();
}



void Generator::addNewSkillLearning()
{
	sentence += dictionary->getLevelPart(Dictionary::LevelPart::NEW_SKILL_LEARNING);
	addSpace();
}



void Generator::addCombat()
{
	sentence += dictionary->getLevelPart(Dictionary::LevelPart::COMBAT); 
	addSpace();
}



void Generator::addPickupCache()
{
	sentence += dictionary->getLevelPart(Dictionary::LevelPart::NEW_SKILL_LEARNING);
	addSpace();
}



void Generator::addBossEncounter()
{
	sentence += dictionary->getLevelPart(Dictionary::LevelPart::BOSS_ENCOUNTER);
	addSpace();
}






/* Currently:
- Make first letter uppercase
- Add fullstop
*/
void Generator::fixGrammar()
{
	// make a copy just incase something happens to the sentence.
	auto sentence_temp = sentence;
	if (!sentence_temp.empty())
	{
		sentence_temp[0] = toupper(sentence_temp.front());
		
		// Remove the space at the end of the string. 
		sentence_temp.pop_back();
		sentence_temp.append(dictionary->getFullStop());
	}
	sentence = sentence_temp;
}

// DEBUG
void Generator::addSpace()
{
	sentence += dictionary->getCommar();
}


void Generator::addCommar()
{
	sentence += dictionary->getSpace();
}
