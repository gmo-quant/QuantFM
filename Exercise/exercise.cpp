/*
 *	 3.9.2: how to do unit test for it? 
 * 
 */


#include"stdafx.h"
#include"exercise.h"

using namespace std;

/*
 * 3.9.1 
 * a recursive function to compute the sum of numbers between 1 and n
 */
int sum(int n){
	if (n == 1){
		return 1;
	}
	return sum(n-1) + n;
}

/*
 * 3.9.2 
 * a recursive function that takes two integer parameters a and b
 * and print out all the numbers from a and b
 */
void recursivePrintInRange(int a, int b){
	cout << a << " ";
	if (a < b){
		recursivePrintInRange(a+1, b);
	}
	return;
}

/*
 * 3.9.3
 * Write a function fibonacci that evaluates the n-th Fibonacci number by recursion.
 */
int fibonacci(int n){
	if (n <= 1 ){
		return n;
	}else{
		return fibonacci(n-1) + fibonacci(n-2);
	}
}

/*
 * 3.9.4
 * cumulative normal function
 */
const double PI = 3.1415926535897932384626433832795028842;
const double ROOT_2_PI = sqrt(2.0 * PI);

double normcdf(double x){
	DEBUG_PRINT("normcdf(" << x << ")");
	if (x < 0 ){
		return 1 - normcdf(-x);
	}
	double k = 1 / ( 1 + 0.2316419 * x);
	return (1 - (1/ROOT_2_PI) * exp(- x*x / 2.0) * k * (0.319381530 + k * ( -0.356563782 + k* (1.781477937 + k * (-1.821255978 + 1.330274429 * k)))));
}

///////////////////////////////////
//
// 
// unit test
//
// 
//////////////////////////////
static void testSum(){
	ASSERT( 15 == sum(5));
}
static void testPrintInRange(){

	recursivePrintInRange(2, 6);
	cout << endl;
}
static void testFibonacci(){
	// ASSERT (1 == fibonacci(1));
	// ASSERT( 1 == fibonacci(2));
	ASSERT (2 == fibonacci(3));
	ASSERT (3 == fibonacci(4));
	ASSERT (5 == fibonacci(5));
	ASSERT( 34 == fibonacci(9));
}

static void testNormcdf(){
	ASSERT_APPROX_EQUAL( normcdf( 1.96 ), 0.975, 0.001 );
}

void testExercise(){
	setDebugEnabled(true);
	TEST(testSum);
	TEST(testPrintInRange);
	TEST(testFibonacci);
	TEST(testNormcdf);
}