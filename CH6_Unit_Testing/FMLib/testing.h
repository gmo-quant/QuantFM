#pragma once

#include<stdexcept>
#include<sstream>
#include<iostream>
#include<stdlib.h>
#include<cassert>

/* is debugging currently enabled */
bool isDebugEnabled();
/* enabled/disable debug */
void setDebugEnabled(bool enabled);

/* log an information statement */
#define INFO(A)  do{\
	std::cerr << "INFO: \n" << __FILE__ << ":" << __LINE__ << ":\n" << A << endl;\
}while(false)

#define TEST(f) do{\
	std::cerr<<"Calling" << #f <<"()\n";\
	try{\
		f();\
	} catch(...){\
		std::cerr<<"\n";\
		std::cerr<<"***** " << #f << "() FAILED. *******\n";\
		std::cerr<<"\n";\
		exit(1);\
	}\
	std::cerr<<""<<#f<<"() passed\n";\
	std::cerr<<"\n";\
}while(false)

// on windoss, define debug mode to be 1 when _DEBUG is set 
#ifdef _DEBUG
#define DEBUG_MODE 1
#endif

// on unix, define debug mode to be when _GLTBCXX is set
#ifdef _GLTBCXX_DEBUG
#define DEBUG_MODE 1
#endif

#ifdef DEBUG
#define DEBUG_MODE 1
#endif

//  assertion macros behave differently in test mode
#ifndef DEBUG_MODE

#define DEBUG_PRINT( A )
#define ASSERT( C ) 
#define ASSERT_APPROX_EQUAL(x, y, tolerance)

#else
/* Write A to std::cerr so long as debug is enabled*/
#define DEBUG_PRINT(A) do {\
	if (isDebugEnabled()){\
		std::cerr<<"DEBUG:\n" << __FILE__ << ":"<<__LINE__ << ":\n" << A << "\n";\
	}\
}while(false)

#define ASSERT(C) do{\
	if (!(C)) {\
		std::stringstream testing_ss_ ; \
		testing_ss_ << "ASSERTION FAILED \n"; \
		testing_ss_ << __FILE__ << ": " << __LINE__ << ":\n" << #C; \
		std::cerr << testing_ss_.str(); \
		throw std::runtime_error(testing_ss_.str());\
	}\
}while(false)


/*
	why use do-while(false)

	the whole idea of using 'do/while' version is to make a macro which will expand into 
	a regular statement, not into a compound statement. 
	this is done in order to make the use of function-style macros uniform wiht the use
	of ordinary functions in all contexts.

	for example:

	Consider the following code sketch

if (<condition>)
  foo(a);
else
  bar(a);
where 'foo' and 'bar' are ordinary functions. Now imagine that you'd like to replace function 'foo' with a macro of the above nature

if (<condition>)
  CALL_FUNCS(a);
else
  bar(a);
Now, if your macro is defined in accordance with the second approach (just '{' and '}') the code will no longer compile, because the 'true' branch of 'if' is now represented by a compound statement. And when you put a ';' after this compound statement, you finished the whole 'if' statement, thus orphaning the 'else' branch (hence the compilation error).

One way to correct this problem is to remember not to put ';' after macro "invocations"

if (<condition>)
  CALL_FUNCS(a)
else
  bar(a);
This will compile and work as expected, but this is not uniform. The more elegant solution is to make sure that macro expand into a regular statement, not into a compound one. One way to achieve that is to define the macro as follows

#define CALL_FUNCS(x) \
do { \
  func1(x); \
  func2(x); \
  func3(x); \
} while (0)
Now this code

if (<condition>)
  CALL_FUNCS(a);
else
  bar(a);
will compile without any problems.

However, note the small but important difference between my definition of CALL_FUNCS and the first version in your message. I didn't put a ; after } while (0). Putting a ; at the end of that definition would immediately defeat the entire point of using 'do/while' and make that macro pretty much equivalent to the compound-statement version.

I don't know why the author of the code you quoted in your original message put this ; after while (0). In this form both variants are equivalent. The whole idea behind using 'do/while' version is not to include this final ; into the macro (for the reasons that I explained above).

*/

#define ASSERT_APPROX_EQUAL(x, y, tolerance) do{\
	if (!(fabs((x) - (y) ) <= (tolerance))) {\
		std::stringstream testing_ss_ ;\
		testing_ss_ << "ASSERTION FAILED \n" ;\
		testing_ss_ << "Expected " << (x) << "\n" ;\
		testing_ss_ << "ACtual " << (y) << "\n"; \
		testing_ss_ << __FILE__ << ":" << __LINE__ << ":\n"; \
		std::cerr << testing_ss_.str(); \
		throw std::runtime_error(testing_ss_.str()); \
	}\
}while(false)

#endif