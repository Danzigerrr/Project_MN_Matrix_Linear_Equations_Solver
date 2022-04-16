#include "Constants.h"
#include "EquationResult.h"
#include "main.h"

int main() {
	Matrix* A = new Matrix(N, 5 + 4, -1, -1);
	Vector* b = new Vector(N, 4);
	
	cout << endl << "B:" << endl;
	solveJacobi(A,b);

	//solveGaussSeidl(A, b);

	cout << endl << "C:" << endl;
	A = new Matrix(N, 3, -1, -1);
	//solveJacobi(A, b);
	//solveGaussSeidl(A, b);

	cout << endl << "D:" << endl;
	//solveLUFactorisation(A, b);

	cout << endl << "E:" << endl;
	int NArray[] = { 500, 1000, 2000, 3000, 4000, 5000};
	int NArraySize = sizeof(NArray) / sizeof(NArray[0]);
	compareJacobi(NArray, NArraySize);
	compareGaussSeidl(NArray, NArraySize);

	return 0;
}
void compareJacobi(int NArray[], int size)
{
	cout << "JACOBI" << endl;
	cout << "N" << "\tt[s]" << endl;
	for (int i = 0; i < size; i++) {
		int currN = NArray[i]; //get N size
		Matrix* Anew = new Matrix(currN, 5 + 4, -1, -1);
		Vector* bnew = new Vector(currN, 4);
		solveJacobi(Anew, bnew);
	}
}
void compareGaussSeidl(int NArray[], int size)
{
	cout << "GAUSS-SEIDL" << endl;
	cout << "N" << "\tt[s]" << endl;
	for (int i = 0; i < size; i++) {
		int currN = NArray[i]; //get N size
		Matrix* Anew = new Matrix(currN, 5 + 4, -1, -1);
		Vector* bnew = new Vector(currN, 4);
		solveGaussSeidl(Anew, bnew);
	}
}