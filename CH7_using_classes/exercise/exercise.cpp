#include "exercise.h"

using namespace std;

/**
 * uses the quadratic formula to find both roots of ax2 + bx + c = 0.
 */

int solveQuadratic(double a, double b, double c, double& r1, double& r2){
	int rootCount = 0;
	if ( 0 == a){
		throw logic_error("a should not be 0");
	}
	double delta = b * b - 4 * a * c;
	if (delta < 0.0){
		rootCount = 0; // there is no real solution
	}else if ( delta > 0.0){
		rootCount = 2; // there are two real solution
	}else{
		rootCount = 1; // there are one real solution
	}
	r1 = (-b + sqrt(delta) ) / (2 * a);
	r2 = (-b - sqrt(delta) ) / (2 * a);
	return rootCount;
}

static void testSolveQuadratic(){
	double r1 = 0.0, r2 = 0.0;
	// solveQuadratic(0, 1, 2, r1, r2 );

	ASSERT( 2 == solveQuadratic(2, -4, -3, r1, r2 ) );
	ASSERT ( (fabs((r1)-(-0.58))<= 0.01 || (fabs((r1)-(2.58))<= 0.01 ) ) );
	ASSERT ( (fabs((r2)-(-0.58))<= 0.01 || (fabs((r2)-(2.58))<= 0.01 ) ) );

	ASSERT( 1 == solveQuadratic(-3, -24, -48, r1, r2 ) );
	ASSERT ( -4 == r1);
	ASSERT ( -4 == r2);

	ASSERT( 0 == solveQuadratic(1, -4, 10, r1, r2 ) );
}

void testExercise(){
	TEST( testSolveQuadratic );
}