#include <iostream>
#include <ctime>
#include <cmath>
#include <math.h>

double beta = 0.4;

double f(double s) {
	return (1.0 - exp(-beta * s)) / (1.0 + exp(-beta * s));
}

int main() {
	double tabx[2][13] = { { 1.0,-1.0,-1.0,1.0,-1.0,-1.0,1.0,-1.0,-1.0,1.0,-1.0,-1.0,1.0 },
						   { 1.0,1.0,-1.0,1.0,1.0,1.0,1.0,-1.0,-1.0,1.0,-1.0,-1.0,1.0 } };
	double d[2] = { 1.0, -1.0 };
	double wx[13] = { 0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0 };
	double taby[2];
	double ni = 0.4;
	double E;
	double sum;

	do {
		E = 0.0;
		for (int i = 0; i < 2; i++) {
			sum = 0.0;
			for (int j = 0; j < 13; j++) {
				sum += tabx[i][j] * wx[j];
			}

			taby[i] = f(sum);

			for (int j = 0; j < 13; j++) {
				wx[j] = wx[j] + ni * d[i] * tabx[i][j];
			}

			E += 0.5*(d[i] - taby[i])*(d[i] - taby[i]);
		}

	} while (E > 0.0003);

	std::cout << taby[0] << " " << taby[1] << std::endl;

	system("pause");
	return 0;
}