#include<iostream>
#include <cmath>

double f(double s)
{
	double beta = 0.5;
	return(1.0 - exp(-beta * s)) / (1.0 + exp(-beta * s));

}
int main() {

	//wartosci
	double tab1[13] = { -1.0, -1.0, 1.0, -1.0, -1.0, 1.0, -1.0, -1.0, 1.0, -1.0, -1.0, 1.0, 1.0 }; //jedynka	
	double tab4[13] = { 1.0, -1.0, 1.0, 1.0, 1.0, 1.0, -1.0, -1.0, 1.0, -1.0, -1.0, 1.0, 1.0 }; //czworka
	
	//wagi	
	double wx1[13] = { 0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0 };
	double wx4[13] = { 0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0 };
	
	//wartosci oczekiwane
	double d1 = 1.0;
	double d4 = -1.0;

	//bledy
	double E;
	double E1;
	double E4;
	
	//wspolczynnik uczenia
	double ni = 0.5;
	
	//wartosc funckji
	double y1;
	double y4;

	//suma
	double suma1 = 0.0;
	double suma4 = 0.0;
	
	
	int d = 0; //kroki 	
	
	do {
		E = 0;
		for (int i = 0; i < 13; i++)
		{
			suma1 += tab1[i] * wx1[i];
			suma4 += tab4[i] * wx4[i];
		}

		y1 = f(suma1);						
		y4 = f(suma4);

		for (int i = 0; i < 13; i++)		
		{
			wx1[i] = wx1[i] + ni * d1 * tab1[i];
			wx4[i] = wx4[i] + ni * d4 * tab4[i];
		}	

		E1 = 0.5 * (d1 - y1)*(d1 - y1);				
		E4 = 0.5 * (d4 - y4)*(d4 - y4);
		
		d++; //krok programu
		E = E1 + E4;		
		
	} while (E > 0.0003);
	
	std::cout << "Wynik dla jeden: " << y1 << "  Wynik dla cztery: " << y4 << std::endl;
	std::cout << "Krok programu: " << d << std::endl;

	system("pause");
	return 0;
	
	
}