#pragma once
#include "stdafx.h"

/**
 * write a  pie chart
 */

void pieChart( std::string& file, std::vector<std::string>& labels, std::vector<double>& values);

/**
 * run unit tests for the charts package
 */

void testCharts();