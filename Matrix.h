#pragma once
#include "vector.h"
class Matrix
{
private:
	int size;
public:
	double** valuesArr;
	Matrix(int N, int a1, int a2, int a3);
	~Matrix();
	Vector matrixMultiplicationVector(double* x);
	int getSize();
};

