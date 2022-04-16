#include "matrix.h"
#include "vector.h"

Matrix::Matrix(int Size, int a1, int a2, int a3) {
	this->size = Size;
	valuesArr = new double* [size];
	for (int i = 0; i < size; ++i) {
		valuesArr[i] = new double[size];
		for (int j = 0; j < size; ++j) {
			if (j - i == 0) valuesArr[i][j] = a1;
			else if (j - i == 1 || i - j == 1 )valuesArr[i][j] = a2;
			else if (j - i == 2 || i - j == 2) valuesArr[i][j] = a3;
			else valuesArr[i][j] = 0;
		}
	}
}

Matrix::~Matrix() {}

Vector Matrix::matrixMultiplicationVector(double* x) {
	Vector* y = new Vector(size, 0);
	double tmp = 0;
	for (int i = 0; i < size; i++) {
		tmp = 0;
		for (int j = 0; j < size; j++) {
			tmp = tmp + (valuesArr[i][j] * x[j]);
		}
		y->valuesArr[i] = tmp;
	}
	return *y;
}

int Matrix::getSize() {
	return size;
}