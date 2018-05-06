#include<iostream>
#include<cmath>
#include<stdexcept>

using namespace std;


const double PI = 3.14159;
const double PIRoot = 1/pow(2 * PI, 0.5);
double sum(double n); // 3.9.1
void recursivePrint(int a, int b); // 3.9.2
long double normcdf(long double x); // 3.9.4
double hornerFunction(int poly[], int n, int x); // 3.9.6
double norminv(double x); // 3.9.7

int main(){
	// recursivePrint(1, 5);
	// cout << endl;

	// cout << normcdf(-4) << endl;
	int poly[] = {2, -6, 2, -1};
	int n = sizeof(poly) / sizeof(poly[0]);
	cout << hornerFunction(poly, n, 3) << endl;
}


double sum(double n){
	if (  0 != n){
		return n + sum(n-1);
	}else{
		return 0;
	}
}

void recursivePrint(int a, int b){
	cout << a ;
	if (a < b){
		recursivePrint(a+1, b);
	}
	return;
}

long double normcdf( long double x){
	long double result =  0.0;
	long double k = 1/ ( 1 + 0.2316419 * x);
	long double ks = k * (0.319391530 + k * ( - 0.356563782 + k * (1.781477937 + k* (-1.821255978 + 1.330274429 * k  )))); // stray error, because copy and paste
	long double e = exp( - x*x / 2 );
	result = 1 - PIRoot * e * ks ;
	if (x >= 0.0){
		return result;
	}else{
		return 1 - result;
	}
}

double hornerFunction(int poly[], int n, int x){
	double result = poly[0];
	for (int i = 1; i < n; i++){
		result = result * x + poly[i];
	}
	return result;
}

double norminv(double x){
	double y = 0;
	double r = 0;
	if ( x >= 0.0 && x <= 1.0){
		y = x - 0.5;
		if ( abs(y) < 0.42){
			r = y * y;
			return y * ( hornerFunction( a, 4, r)) / hornerFunction(b, 5, r);
		}else{
			
		}

	}else{
		throw logic_error("x not in range [0, 1]") ;
	}
}