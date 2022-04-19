#include <math.h>
#include "vector.h"

Vector::Vector(int Size, int f) {
	size = Size;
	valuesArr = new double[size];
	for (int i = 0; i < size; i++) {
		valuesArr[i] = sin(i * (f + 1));
	}
}



int Vector::getSize() {
	return size;
}
