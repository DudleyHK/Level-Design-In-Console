/*



*/
#include <iostream>

#include "Matrix.h"

Matrix::Matrix(const float x1, const float y1, const float z1, const float w1,
			   const float x2, const float y2, const float z2, const float w2,
			   const float x3, const float y3, const float z3, const float w3,
			   const float x4, const float y4, const float z4, const float w4) :
	x1(x1), x2(x2), x3(x3), x4(x4),
	y1(y1), y2(y2), y3(y3), y4(y4),
	z1(z1), z2(z2), z3(z3), z4(z4),
	w1(w1), w2(w2), w3(w3), w4(w4)	
{ 
	table.reserve(16);
	table.resize(16);


	table[0] = x1;
	table[1] = y1;
	table[2] = z1;
	table[3] = w1;

	table[4] = x2;
	table[5] = y2;
	table[6] = z2;
	table[7] = w2;

	table[8]  = x3;
	table[9]  = y3;
	table[10] = z3;
	table[11] = w3;

	table[12] = x4;
	table[13] = y4;
	table[14] = z4;
	table[15] = w4;


}



void Matrix::printMatrix()
{
	x1 = table[0];
	y1 = table[1];
	z1 = table[2];
	w1 = table[3];
	
	x2 = table[4];
	y2 = table[5];
	z2 = table[6];
	w2 = table[7];
	
	x3 = table[8];
	y3 = table[9];
	z3 = table[10];
	w3 = table[11];
	
	x4 = table[12];
	y4 = table[13];
	z4 = table[14];
	w4 = table[15];



	std::cout << "________ |1| __ |2| __ |3| __ |4| ________" << std::endl;
	std::cout << "______________________________________________________________" << std::endl;
	std::cout << "1\t| " << x1 << ",\t " << y1 << ",\t " << z1 << ",\t " << w1 << "| " << std::endl;
	std::cout << "2\t| " << x2 << ",\t " << y2 << ",\t " << z2 << ",\t " << w2 << "| " << std::endl;
	std::cout << "3\t| " << x3 << ",\t " << y3 << ",\t " << z3 << ",\t " << w3 << "| " << std::endl;
	std::cout << "4\t| " << x4 << ",\t " << y4 << ",\t " << z4 << ",\t " << w4 << "| " << std::endl;
	std::cout << "______________________________________________________________" << std::endl;
}


const float Matrix::getFromTable(const unsigned short index)
{
	if (index >= table.size() || index < 0)
	{
		return -1;
	}
	return table[index];
}

const float Matrix::getFromTable(const unsigned short from, const unsigned short to)
{
	// (w * r) + c
	unsigned int row    = (from - 1);
	unsigned int columm = (to - 1);

	unsigned short index = (4 * row) + columm;

	if (index >= table.size() || index < 0)
	{
		return -1;
	}
	return table[index];
}



void Matrix::setInTable(const unsigned short index, const float value)
{
	table[index] = value;
}

void Matrix::setInTable(const unsigned short from, const unsigned short to, const float value)
{
	// (w * r) + c
	unsigned int row = (from - 1);
	unsigned int columm = (to - 1);

	unsigned short index = (4 * row) + columm;

	table[index] = value;
}






