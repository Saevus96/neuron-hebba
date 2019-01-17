#include<iostream>
#include <cmath>

double f(double s)
{
	double beta = 4.0;
	return(1.0 - exp(-beta * s)) / (1.0 + exp(-beta * s));

}
int main() {


	//wartosci
	double tab1[13] = { 1.0,-1.0,-1.0,1.0,-1.0,-1.0,1.0,-1.0,-1.0,1.0 ,-1.0,-1.0,1.0 }; //jedynka	
	double tab4[13] = { 1,1,-1,1,1,1,1,-1,-1,1,-1,-1,1 }; //czworka

	//wpsolczynniki
	double d1 = 1.0;
	double d4 = -1.0;
	double E;
	double E1;
	double E4;
	double ni = 0.4;
	double sum;
	double y1;
	double y4;

	//wagi	
	double wx1[13] = {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0};
	double wx2[13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0};
	
	int d = 0; //kroki 	
	
	do {
		//dla jedynki 
		sum = 0;
		for (int i = 0; i < 13; i++)
		{
			sum = sum + tab1[i] * wx1[i];
			y1 = f(sum);	
			wx1[i] = wx1[i] + ni * d1*tab1[i];
			E1 = (0.5)*((d1 - y1)*(d1 - y1));
			d++;
		}
		
		//dla czworki
		sum = 0;
		for (int i = 0; i < 13; i++)
		{
			sum = sum + tab4[i] * wx2[i];
			y4 = f(sum);
			wx2[i] = wx2[i] + ni * d4*tab4[i];
			E4 = (0.5)*((d4 - y4)*(d4 - y4));
			d++;
		}
		
		d++; //krok programu
		E = E1 + E4;
		if (E < 0.03) {
			std::cout <<"Wynik dla jeden: "<< y1 << "  Wynik dla cztery: " << y4 << std::endl;
			std::cout << "Krok programu: " << d << std::endl;
		}
		
	} while (E > 0.03);
	


	system("pause");
	return 0;
	
	
}