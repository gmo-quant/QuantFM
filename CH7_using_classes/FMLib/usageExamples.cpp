#include "usageExamples.h"
#include "testing.h"

using namespace std;

static void writeCSVChartData( ostream& out,
		const vector<double>& x, 
		const vector<double>& y ){
	ASSERT(x.size() == y.size() );
	int n = x.size();
	for (int i = 0; i < n; i++){
		out << x[i] << "," << y[i] << endl;
	}
}

void writeCSVChart(const std::string& filename, 
		const std::vector<double>& x, 
		const std::vector<double>& y){
	ofstream out;
	out.open(filename.c_str() );
	writeCSVChartData(out, x, y);
	out.close();
}

static void testWriteCSVChart(){

}

/**
 * unit test
 */

void testUsageExamples(){
	TEST( testWriteCSVChart );
}