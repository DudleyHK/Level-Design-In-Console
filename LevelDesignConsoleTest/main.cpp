/*



*/


#include <iostream>
#include <memory>
#include "Generator.h"


int main()
{
	std::unique_ptr<Generator> gen = std::make_unique<Generator>();
	while(true)
	{
		std::cout << "..................................." << std::endl;
		std::cout << gen->generate() << std::endl;
		std::cout << "..................................." << std::endl;
		system("PAUSE");
		std::cout << std::endl;
	}
	return 0;
}