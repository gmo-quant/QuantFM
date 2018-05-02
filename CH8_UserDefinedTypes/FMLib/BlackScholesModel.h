#pragma once

#include"stdafx.h"

class BlackScholesModel{
public:
	BlackScholesModel();
	// explicit, prevent automatic conversion
	explicit BlackScholesModel(double stockPrice);

public:
	double stockPrice;
	double volatility;
	double riskFreeRate;
	double date;


};

void testBlackScholesModel();