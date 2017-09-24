/*



*/


#include <iostream>
#include "Generator.h"


int main()
{
	Generator gen;
	while(true)
	{
		std::cout << "..................................." << std::endl;
		std::cout << gen.generate() << std::endl;
		std::cout << "..................................." << std::endl;
		system("PAUSE");
		std::cout << std::endl;
	}
	return 0;
}