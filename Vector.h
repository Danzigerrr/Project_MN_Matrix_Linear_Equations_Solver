#pragma once
class Vector
{
private:
	int size;
public:
	double* valuesArr;
	Vector(int Size, int f);
	Vector(int Size, bool x);
	int getSize();
	void copy(Vector x);
};

