#pragma once


/*
 * 3.9.1 
 * a recursive function to compute the sum of numbers between 1 and n
 */
int sum(int n); 

/*
 * 3.9.2 
 * a recursive function that takes two integer parameters a and b
 * and print out all the numbers from a and b
 */
void recursivePrintInRange(int a, int b);

/*
 * 3.9.3
 * Write a function fibonacci that evaluates the n-th Fibonacci number by recursion.
 * n > 2
 * O(n^2)
 */
int fibonacci(int n);

/*
 * 3.9.4
 * cumulative normal function
 */

double normcdf(double x);

/*
 * 3.9.8
 * option pricing, using black scholes method
 */

double blackScholesCallPrice(double strike, double time2Maturity, double spot, double volatility, double risk_free_rate);

/*
 * 4.8.2
 * integrateSin
 */
double integrateSin(double a, double b, int N);


/*
 * 4.8.3
 * infiniteIntegral
 */
double infiniteIntegral(double x);


/*
 * 7.7.1
 * 
 */


void testExercise();
