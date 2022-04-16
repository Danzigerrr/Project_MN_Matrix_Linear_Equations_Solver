#include "Constants.h"
#include "EquationResult.h"

double vectorEuclNorm(int size, double* x);
double* calcResiduum(Matrix A, Vector b, Vector x);
void solveJacobi(Matrix *A, Vector *b);
void solveGaussSeidl(Matrix* A, Vector* b);
void solveLUFactorisation(Matrix* A, Vector* b);
void LU(Matrix* L, Matrix* U);

int main() {
	Matrix* A = new Matrix(N, 5 + 4, -1, -1);
	Vector* b = new Vector(N, 4);
	equResult jacobiResult, gaussSeildResult;
	
	cout << endl << "B:" << endl;
	solveJacobi(A,b);

	solveGaussSeidl(A, b);

	cout << endl << "C:" << endl;
	A = new Matrix(N, 3, -1, -1);
	solveJacobi(A, b);
	solveGaussSeidl(A, b);

	cout << endl << "D:" << endl;
	solveLUFactorisation(A, b);

	cout << endl << "E:" << endl;
	int NArray[] = { 100, 500, 1000, 2000, 3000 };

	for (int i = 0; i < 5; i++) {

	}

	/*
	GaussSeidla();
	koniec = clock();
	time = (double)(koniec - poczatek) / CLOCKS_PER_SEC;
	cout << "Czas dzialania w metodzie Gaussa-Seidla: " << time << endl << endl;
	delete A;
	A = new matrix(N, 3, -1);
	cout << "Po zmianie macierzy:" << endl;
	poczatek = clock();
	Jacobi();
	koniec = clock();
	time = (double)(koniec - poczatek) / CLOCKS_PER_SEC;
	cout << "Czas dzialania w metodzie Jacobiego: " << time << endl << endl;
	poczatek = clock();
	GaussSeidla();
	koniec = clock();
	time = (double)(koniec - poczatek) / CLOCKS_PER_SEC;
	cout << "Czas dzialania w metodzie Gaussa-Seidla: " << time << endl << endl;
	poczatek = clock();
	cout << "Wynik dla faktoryzacji LU: " << LUfactorization() << endl;
	koniec = clock();
	time = (double)(koniec - poczatek) / CLOCKS_PER_SEC;
	cout << "Czas dzialania faktoryzacji LU: " << time << endl << endl;
	*/
	return 0;
}
/*
void LU(matrix* L, matrix* U) {
	for (int k = 0; k < N - 1; k++) {
		for (int j = k + 1; j < N; j++) {
			L->value[j][k] = U->value[j][k] / U->value[k][k];

			for (int r = k; r < N; r++) {
				U->value[j][r] = U->value[j][r] - L->value[j][k] * U->value[k][r];
			}
		}
	}
}

double LUfactorization() {
	matrix* U = new matrix(N, 3, -1);
	matrix* L = new matrix(N, 1, 0);
	LU(L, U);
	vector* y = new vector(N, 0);
	for (int i = 0; i < N; i++) {
		double sum = 0;
		for (int j = 0; j < i; j++) {
			sum += L->value[i][j] * y->value[j];
		}
		y->value[i] = b->value[i] - sum;
	}
	double* x = new double[N];
	for (int i = 0; i < N; i++) {
		x[i] = 0;
	}

	for (int i = N - 1; i >= 0; i--) {
		double sum = 0;
		for (int j = i; j < N; j++) {
			sum += U->value[i][j] * x[j];
		}
		x[i] = (y->value[i] - sum) / U->value[i][i];
	}
	vector* z = new vector(N, 0);
	z->value = x;
	double res = norma(residuum(*A, *b, *z));
	return res;
}

double* wzorSeidla(double* x1, double* x2) {
	double sum = 0;
	for (int i = 0; i < N; i++) {
		sum = 0;
		for (int j = 0; j < i; j++) {
			sum += A->value[i][j] * x1[j];
		}
		for (int j = i + 1; j < N; j++) {
			sum += A->value[i][j] * x2[j];
		}
		sum = b->value[i] - sum;
		x1[i] = sum / A->value[i][i];
	}
	return x1;
}
void GaussSeidla() {
	int iteracje = 0;
	vector* x = new vector(N, 1);
	double res;
	vector* xp1 = new vector(N, 1);
	while (true) {
		iteracje++;
		xp1->value = wzorSeidla(xp1->value, x->value);
		x->copy(*xp1);
		res = norma(residuum(*A, *b, *x));
		if (res < pow(10, -9) || iteracje>5000) {
			cout << "Norma w metodzie Gaussa-Seidla: " << res << " liczba iteracji: " << iteracje << endl;
			break;
		}
	}
}
*/
