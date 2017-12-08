/*



*/
#pragma once
#include <vector>




class Matrix
{
public:
	Matrix(const float x1 = 0.f, const float y1 = 0.f, const float z1 = 0.f, const float w1 = 0.f,
		   const float x2 = 0.f, const float y2 = 0.f, const float z2 = 0.f, const float w2 = 0.f,
		   const float x3 = 0.f, const float y3 = 0.f, const float z3 = 0.f, const float w3 = 0.f,
		   const float x4 = 0.f, const float y4 = 0.f, const float z4 = 0.f, const float w4 = 0.f);
	~Matrix() = default;

	void printMatrix();
	
	const float getFromTable(const unsigned short index);
	const float getFromTable(const unsigned short row, const unsigned short column);

	void setInTable(const unsigned short index, const float value);
	void setInTable(const unsigned short row, const unsigned short column, const float value);


private:
	float x1;
	float y1;
	float z1;
	float w1;

	float x2;
	float y2;
	float z2;
	float w2;

	float x3;
	float y3;
	float z3;
	float w3;

	float x4;
	float y4;
	float z4;
	float w4;

	std::vector<float> table;


};