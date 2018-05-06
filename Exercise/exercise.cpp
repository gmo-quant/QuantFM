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
const double ROOT_2_PI = sqrt(2.0 * PI); //  sqrt(2PI) is use often, so make it a const 

static inline  double hornerFunction(double x,  double a0){
	return a0;
}
static inline double hornerFunction(double x, double a0, double a1){
	return a0 + x * a1;
}
static inline double hornerFunction(double x, double a0, double a1, double a2){
	return a0 + x * hornerFunction(x, a1, a2);
}

static inline double hornerFunction(double x, double a0, double a1, double a2, double a3){
	return a0 + x * hornerFunction(x, a1, a2, a3);
}
static inline double hornerFunction(double x, double a0, double a1, double a2, double a3, double a4){
	return a0 + x * hornerFunction(x, a1, a2, a3, a4);
}

static inline double hornerFunction(double x, double a0, double a1, double a2, double a3, double a4, double a5){
	return a0 + x * hornerFunction(x, a1, a2, a3, a4, a5);
}
static inline double hornerFunction(double x, double a0, double a1, double a2, double a3, double a4, double a5, double a6){
	return a0 + x * hornerFunction(x, a1, a2, a3, a4, a5, a6);
}
static inline double hornerFunction(double x, double a0, double a1, double a2, double a3, double a4, double a5, double a6, double a7){
	return a0 + x * hornerFunction(x, a1, a2, a3, a4, a5, a6, a7);
}
static inline double hornerFunction(double x, double a0, double a1, double a2, double a3, double a4, double a5, double a6, double a7, double a8){
	return a0 + x * hornerFunction(x, a1, a2, a3, a4, a5, a6, a7, a8);
}
double normcdf(double x){
	DEBUG_PRINT("normcdf(" << x << ")");
	if (x < 0 ){
		return 1 - normcdf(-x);
	}
	double k = 1 / ( 1 + 0.2316419 * x);
	double poly = hornerFunction(k, 0.0, 0.319381530, 
								-0.356563782, 1.781477937 , 
								-1.821255978 , 1.330274429);
	return (1.0 - (1.0/ROOT_2_PI) * exp(- x*x / 2.0) * poly );
}


/*  Constants required for Moro's algorithm */
static const double a0 = 2.50662823884;
static const double a1 = -18.61500062529;
static const double a2 = 41.39119773534;
static const double a3 = -25.44106049637;
static const double b1 = -8.47351093090;
static const double b2 = 23.08336743743;
static const double b3 = -21.06224101826;
static const double b4 = 3.13082909833;
static const double c0 = 0.3374754822726147;
static const double c1 = 0.9761690190917186;
static const double c2 = 0.1607979714918209;
static const double c3 = 0.0276438810333863;
static const double c4 = 0.0038405729373609;
static const double c5 = 0.0003951896511919;
static const double c6 = 0.0000321767881768;
static const double c7 = 0.0000002888167364;
static const double c8 = 0.0000003960315187;

double norminv(double x, bool checkRange = true){
	DEBUG_PRINT( "norminv(" << x << ")");

	if (checkRange && ( x < 0 || x > 1.0 ) ){
		throw logic_error("parameter x is out of range for norminv. it should be between 0 an d 1");
	}
	double y = x- 0.5;
	if ( y < 0.42 && y > -0.42){
		double r = y * y;
		DEBUG_PRINT("Case 1, r = " << r);
		return y * hornerFunction( r , a0, a1, a2, a3) / hornerFunction(r, 1.0, b1, b2, b3, b4);
	}else{
		double r = 0.0;
		if (y < 0.0){
			r = x;
		}else{
			r = 1 - x;
		}
		DEBUG_PRINT("Case 2, r = " << r);
	    double s = log( -log( r ));
		double t = hornerFunction(s,c0,c1,c2,c3,c4,c5,c6,c7,c8);
		if (x > 0.5){
			return t;
		}else{
			return -t;
		}
	}
}


/* 

Black-Scholes is a pricing model used to determine the fair price or theoretical value for a call or a put option based on six variables such as volatility, type of option, underlying stock price, time, strike price, and risk-free rate. 
The quantum of speculation is more in case of stock market derivatives, and hence proper pricing of options eliminates the opportunity for any arbitrage.
*/

double blackScholesCallPrice(double strike, double time2Maturity, double spot, double volatility, double risk_free_rate){
	double numerator = log(spot/strike) + (risk_free_rate + volatility * volatility * 0.5 ) * time2Maturity;
	double denominator = volatility * sqrt(time2Maturity);
	double d1 = numerator / denominator ;
	double d2 = d1 - denominator ;
	double t1 = normcdf(d1) * spot;
	double t2 = normcdf(d2) * strike * exp( - risk_free_rate * time2Maturity);
	return t1 - t2;
}

/*
 * 4.8.2
 * integrateSin, use rectange rule approximation
 */
double integrateSin(double a, double b, int N){
	double h = (b - a)/N;
	// double x = 0.0;
	// double f = 0.0;
	double total = 0.0;
	for (int i = 0; i< N; i++){
		double x = a +(i+0.5) * h;
		double f = sin(x);
		total += f;
	}
	return total/N;
}

/*
 * 4.8.3
 * infiniteIntegral, 
 */

double infiniteIntegral(double x){
	double a = 0;
	double b = 1;
	int N = 1000;
	double h = ( b - a) / N;
	double total = 0.0;
	for (int i =0; i < N; i++){
		double s = (i + 0.5) * h + a;
		double t = x + 1 - 1/s;
		double f = pow(s, -2) * exp( -0.5 * t * t); 
		total += f;
	}
	return total/N;
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

static void testHornerFunction(){

}

static void testNorminv(){
	ASSERT_APPROX_EQUAL(norminv(0.975), 1.96, 0.01);
}

static void testBlackScholesCallPrice(){
	double strike = 100.0;
    double spot = 110.0;
    double vol = 0.1;
    double riskFreeRate = 0.03;
    double timeToMaturity = 0.5;
    cout << "\nExercise8\n";
    cout << "The call price calculated is ";
    cout << blackScholesCallPrice( strike, timeToMaturity, spot, vol, riskFreeRate );
    cout << "\nExpected the value 11.677\n";
}


static void testIntegrateSin(){

	// why the actual result is half of the expected one?
	ASSERT_APPROX_EQUAL( integrateSin(1, 3, 100) , 1.53, 0.01);
}

static void testInfiniteIntegral(){
	ASSERT_APPROX_EQUAL( infiniteIntegral(1.96), 0.975 * sqrt(2 * PI), 0.01);
}
void testExercise(){
	setDebugEnabled(true);
	TEST(testSum);
	TEST(testPrintInRange);
	TEST(testFibonacci);
	TEST(testNormcdf);
	TEST(testHornerFunction);
	TEST(testNorminv);
	TEST(testBlackScholesCallPrice);
	TEST(testInfiniteIntegral);
	TEST(testIntegrateSin);
	
}