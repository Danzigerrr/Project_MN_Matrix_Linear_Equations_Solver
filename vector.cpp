#include <math.h>
#include "vector.h"

Vector::Vector(int Size, int f) {
	size = Size;
	valuesArr = new double[size];
	for (int i = 0; i < size; i++) {
		valuesArr[i] = sin(i * (f + 1));
	}
}

Vector::Vector(int Size, bool x) {
	size = Size;
	valuesArr = new double[size];
	for (int i = 0; i < size; i++) {
		if (true)valuesArr[i] = 1;
		else valuesArr[i] = 0;
	}
}

int Vector::getSize() {
	return size;
}

void Vector::copy(Vector x) {
	if (x.getSize() == size) {
		for (int i = 0; i < size; i++) {
			valuesArr[i] = x.valuesArr[i];
		}
	}
}