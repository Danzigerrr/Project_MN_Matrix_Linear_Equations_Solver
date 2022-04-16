#include "Constants.h"
#include "EquationResult.h"


double* calcResiduum(Matrix A, Vector b, Vector x) {
	Vector c = A.matrixMultiplicationVector(x.valuesArr);
	for (int i = 0; i < A.getSize(); i++) {
		c.valuesArr[i] -= b.valuesArr[i];
	}
	return c.valuesArr;
}


double vectorEuclNorm(int size,double* x) {
	double tmp = 0;
	for (int i = 0; i < size; i++) {
		tmp += (x[i] * x[i]);
	}
	return sqrt(tmp);
}


//------
double* runJacobiFormula(Matrix* A, Vector* b, double* x1) {
	int size = A->getSize();
	double* x = new double[size];
	double sum = 0;
	for (int i = 0; i < size; i++) {
		sum = 0;
		for (int j = 0; j < size; j++) {
			if (i != j)sum += A->valuesArr[i][j] * x1[j];
		}
		sum = b->valuesArr[i] - sum;
		x[i] = sum / A->valuesArr[i][i];
	}
	return x;
}
void solveJacobi(Matrix* A, Vector* b) {
	int size = A->getSize();
	clock_t begin, finish;
	double final_time;
	begin = clock();
	
	int iterCounter = 0;
	double currRes = 0, finalRes = pow(10, -9);
	Vector* x = new Vector(size, 1);
		
	while (true) {
		iterCounter++;
		x->valuesArr = runJacobiFormula(A, b, x->valuesArr);
		currRes = vectorEuclNorm(A->getSize(),calcResiduum(*A, *b, *x));
		if (currRes < finalRes || iterCounter == 5000)
			break;
	}
	finish = clock();
	final_time = (double)(finish - begin) / CLOCKS_PER_SEC;

	equResult* result = new equResult("Jacobi", currRes, iterCounter, final_time);
	result->printResult();
}


// -------
double* runGaussSeidlFormula(Matrix* A, Vector* b, double* x1) {
	int size = A->getSize();

	double sum = 0;
	for (int i = 0; i < size; i++) {
		sum = 0;
		for (int j = 0; j < i; j++) {
			sum += A->valuesArr[i][j] * x1[j];
		}
		for (int j = i + 1; j < size; j++) {
			sum += A->valuesArr[i][j] * x1[j];
		}
		sum = b->valuesArr[i] - sum;
		x1[i] = sum / A->valuesArr[i][i];
	}
	return x1;
}
void solveGaussSeidl(Matrix* A, Vector* b) {
	clock_t begin, finish;
	double final_time;
	begin = clock();

	int size = A->getSize();
	int iterCounter = 0;
	double currRes = 0, finalRes = pow(10, -9);
	Vector* x = new Vector(size, 1);
	
	while (true) {
		iterCounter++;
		x->valuesArr = runGaussSeidlFormula(A, b, x->valuesArr);
		currRes = vectorEuclNorm(A->getSize(),calcResiduum(*A, *b, *x));
		if (currRes < finalRes|| iterCounter == 5000)
			break;
	}
	finish = clock();
	final_time = (double)(finish - begin) / CLOCKS_PER_SEC;

	equResult* result = new equResult("Gauss-Seidl", currRes, iterCounter, final_time);
	result->printResult();
}

// -------

void LU(Matrix* L, Matrix* U) {
	int size = L->getSize();
	for (int k = 0; k < size - 1; k++) {
		for (int j = k + 1; j < size; j++) {
			L->valuesArr[j][k] = U->valuesArr[j][k] / U->valuesArr[k][k];

			for (int r = k; r < size; r++) {
				U->valuesArr[j][r] = U->valuesArr[j][r] - L->valuesArr[j][k] * U->valuesArr[k][r];
			}
		}
	}
}

void solveLUFactorisation(Matrix *A, Vector *b) {
	clock_t begin, finish;
	double final_time;
	begin = clock();
	int size = A->getSize();
	Matrix* U = new Matrix(size, 3, -1, -1);
	Matrix* L = new Matrix(size, 1, 0, 0);
	LU(L, U);
	Vector* y = new Vector(size, 0);

	for (int i = 0; i < size; i++) {
		double sum = 0;
		for (int j = 0; j < i; j++) {
			sum += L->valuesArr[i][j] * y->valuesArr[j];
		}
		y->valuesArr[i] = b->valuesArr[i] - sum;
	}
	double* x = new double[size];
	for (int i = 0; i < size; i++) {
		x[i] = 0;
	}

	for (int i = size - 1; i >= 0; i--) {
		double sum = 0;
		for (int j = i; j < size; j++) {
			sum += U->valuesArr[i][j] * x[j];
		}
		x[i] = (y->valuesArr[i] - sum) / U->valuesArr[i][i];
	}
	Vector* z = new Vector(size, 0);
	z->valuesArr = x;
	double res = vectorEuclNorm(A->getSize(), calcResiduum(*A, *b, *z));
	finish = clock();
	final_time = (double)(finish - begin) / CLOCKS_PER_SEC;

	equResult *result = new equResult();
	result->printResult("LUFact", res, final_time);
}



