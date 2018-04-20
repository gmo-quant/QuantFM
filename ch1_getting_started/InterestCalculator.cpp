#include<iostream>
#include<cmath>

using namespace std;



int main(){
	int principle = 0;
	double interestRate = 0;
	int numberOfYears = 0;


	char a ;
	cin >> a;
	cout << (char)(a-32) << endl;

	cout << " what is your principle?" << endl;
	cin >> principle;

	cout << "what is the annual interest Rate" << endl;
	cin >> interestRate;

	cout << "how long for (years) " << endl;
	cin >> numberOfYears;

	double finalBalance = pow (1.0 + interestRate * 0.01, numberOfYears) * principle;
	double interest = finalBalance - principle;

	cout << "you will earn : " << interest << endl;


	return 0;
}