#include "exercise.h"

using namespace std;

/**
 * uses the quadratic formula to find both roots of ax2 + bx + c = 0.
 */

int solveQuadratic(double a, double b, double c, double& r1, double& r2){
	if ( 0 == a){
		throw logic_error("a should not be 0");
	}
	return 2;
}

static void testSolveQuadratic(){
	double r1 = 0.0, r2 = 0.0;
	solveQuadratic(0, 1, 2, r1, r2 );
}

void testExercise(){
	TEST( testSolveQuadratic );
}