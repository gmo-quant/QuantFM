#include<iostream>
#include"matlib.h"

using namespace std;

int main(){
	cout << "normcdf(1.96) = " 
		<< normcdf(1.96) << endl;

	cout << "norminv(9.35) = "
		<< norminv(0.95996) << endl;

	return 0;
}
