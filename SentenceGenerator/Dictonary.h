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


	std::string getNouns(const int idx);
	std::string getVerbs(const int idx);
	std::string getAdjectives(const int idx);
	std::string getAdverbs(const int idx);
	std::string getPronouns(const int idx);
	std::string getPrepositions(const int idx);
	std::string getConjunctions(const int idx);
	std::string getDeterminers(const int idx);
	const std::string getSpace();
	const std::string getFullStop();

	// CONTAINERS
	std::vector<std::string> nouns;
	std::vector<std::string> verbs;
	std::vector<std::string> adjectives;
	std::vector<std::string> adverbs;
	std::vector<std::string> pronouns;
	std::vector<std::string> prepositions;
	std::vector<std::string> conjunctions;
	std::vector<std::string> determiners;


private:

	//INITIALISATION
	void initAll();
	void initNouns();
	void initVerbs();
	void initAdjectives();
	void initAdverbs();
	void initPronouns();
	void initPrepositions();
	void initConjunctions();
	void initDeterminers();




	// GRAMMAR
	const std::string SPACE     = " ";
	const std::string FULL_STOP = ".";


	// ERROR STR
	const std::string ERROR_NOUN      = "ERROR_NOUN";
	const std::string ERROR_VERB      = "ERROR_VERB";
	const std::string ERROR_ADJECTIVE = "ERROR_ADJECTIVE";
	const std::string ERROR_ADVERB    = "ERROR_ADVERB";
	const std::string ERROR_PRONOUN   = "ERROR_PRONOUN";
	const std::string ERROR_PREPOS    = "ERROR_PREPOSITION";
	const std::string ERROR_CONJUNC   = "ERROR_CONJUNCTION";
	const std::string ERROR_DETERM    = "ERROR_DETERMINER";


// DEBUG
#ifdef _DEBUG
	/*Turn to true for sentence structure*/
	const bool init_off = false;
#endif

};