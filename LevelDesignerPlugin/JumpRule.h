/*



*/
#pragma once
#include <string>


/*Could turn this into a set of .hpp files like the jsoncons library*/
class JumpRule
{
public:
	JumpRule() = default;
	~JumpRule() = default;

	void init();
	const std::string createEasy();
	const std::string createMedium();
	const std::string createHard();


private:

	const unsigned short getRandVal(int min, int max);
	void insertBlank(std::string& level_str);
	void insertJump(std::string& level_str, std::string jump);
	void parseJson();
	template<typename Members>
	void unpackRule(Members);


	const std::string JUMP_DATA_PATH = "..\\Resources\\Data\\JumpData.json";

	std::string basic_jump        = "";
	std::string intermediate_jump = "";
	std::string difficult_jump    = "";

};

