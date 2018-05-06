#pragma once
#include "BlackScholesModel.h"
class CallOption{
public:
	double strike;
	double maturity;

	CallOption();
	CallOption(double strike, double maturity);

	/* 
	 * compute the payoff at maturity 
	 */
	double payoff( double stockAtMaturity) const;
	/* 
	 * comput the price given some hypothetical market data 
	 * in the form of a BlackScholesModel
	 */
	double price(const BlackScholesModel& bsm) const;
};

void testCallOption();