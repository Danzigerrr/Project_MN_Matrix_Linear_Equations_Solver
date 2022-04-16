#pragma once
#include "Constants.h"

class equResult {
private:
	double residuum = 0;
	int iterCoutner = 0;
	double final_time = 0;
	string mathodName = "";
public:
	void printResult() {
		cout << endl << "Method: " << mathodName << ":\tNorm: " << residuum << ".\tIterations: " << iterCoutner << ".\tTime: " << final_time << " seconds." << endl;
	}
	void printResult(string MethName, double val,  double final_time) {
		cout << endl << "Method: " << MethName << ":\tResult: " << val << ".\tTime: " << final_time << " seconds." << endl;
	}
	equResult(string name, double res, int iter, double ftime) {
		this->mathodName = name;
		this->residuum = res;
		this->iterCoutner = iter;
		this->final_time = ftime;
	}
	equResult() {};
};