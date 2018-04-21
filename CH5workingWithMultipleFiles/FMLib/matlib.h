/*
The use of #pragma once can reduce build times 
as the compiler will not open and read the file 
after the first #include of the file in the translation unit. 
This is referred to as multiple-include optimization. 
It has an effect similar to the #include guard idiom, 
which uses preprocessor macro definitions to prevent multiple inclusion of the contents of the file. 
This also helps to prevent violations of the one definition rule—
the requirement that all templates, types, functions, 
and objects have no more than one definition in your code.

We recommend the #pragma once directive for new code 
because it doesn't pollute the global namespace with a preprocessor symbol. 
It requires less typing, is less distracting, 
and can't cause symbol collisions—
errors caused when different header files use the same preprocessor symbol as the guard value. 
It is not part of the C++ Standard, but it is implemented portably by several common compilers.

There is no advantage to use of both the #include guard idiom and #pragma once in the same file. 
The compiler recognizes the #include guard idiom and 
implements the multiple include optimization the same way as the #pragma once directive 
if no non-comment code or preprocessor directive comes before or after the standard form of the idiom:

#ifndef HEADER_H_
#define HEADER_H_

xxxx
#endif

*/

/*
	what should be in header file
	* declaration of functions you wish to make available from your library.
	* Declarations of global variables you wish to make available.
	* Definitions of constant global variables.

	where as your source file you should put:
	* Definitions of functions declared in the header.
	* Definitions of global variables missing from the header.


	The reason why constants are treated differently is that the C++ compiler
	can “inline” them. This means to replace every use of the constant with the
	actual value. This gives a slight performance boost. As a consequence, how-
	ever, the definition needs to be in the header, so that every file knows the
	correct value to inline.

	This is called a linker error. The phrase “unresolved external” is an unhelpful
	way of saying that either:
	(i) you forgot the definition altogether;
	(ii) the type information in the definition doesn’t exactly match the type
	information in the declaration;
	(iii) you haven’t installed a library correctly;
	(iv) some more subtle problem has happened. For example, on Visual Studio
	you need to check whether the cpp file is actually listed under "Source
	Files" in your project.


*/
//#pragma once


#ifndef MATLIB_H_
#define MATLIB_H_

const double PI = 3.14159265358979;

/**
 * Computes the cumulative 
 * distribution function of the 
 * normal distribution
 */
double normcdf(double x);

/**
 * computes the inverse of normcdf
 */
double norminv(double x);

#endif