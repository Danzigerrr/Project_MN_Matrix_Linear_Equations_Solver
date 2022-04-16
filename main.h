#pragma once

double vectorEuclNorm(int size, double* x);
double* calcResiduum(Matrix A, Vector b, Vector x);
void solveJacobi(Matrix* A, Vector* b);
void solveGaussSeidl(Matrix* A, Vector* b);
void solveLUFactorisation(Matrix* A, Vector* b);
void LU(Matrix* L, Matrix* U);
void compareJacobi(int NArray[], int size);
void compareGaussSeidl(int NArray[], int size);