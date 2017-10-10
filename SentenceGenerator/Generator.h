/*



*/
#pragma once

#include <string>
#include <memory>
#include <vector>

#include "Dictonary.h"



class Generator
{
public:
	Generator();
	~Generator() = default;

	const std::string generate();



private:
	std::unique_ptr<Dictionary> dictionary = nullptr;
	std::string sentence = "";
	int totalClauses = 1;


	/* Layer One */
	void addLevel();
	
	/* Layer Two */
	void addFirstPhase();
	void addCentralPhase();
	void addEndPhase();

	/* Layer Three */
	void safeSection();
	void learnSection();
	void conflictSection();
	void gainSection();
	void endBossSection();

	/* Layer Four */
	void addSafeZone();
	void addPlatforming();
	void addNewSkillLearning();
	void addCombat();
	void addPickupCache();
	void addBossEncounter();

	/* Grammar */
	void fixGrammar();
	void addSpace();
	void addCommar();
};



