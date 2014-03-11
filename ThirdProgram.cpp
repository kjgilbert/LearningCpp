/*
	using preprocessors:
	
	e.g. the #include ....
	#include <filename> tells the compiler to look for the file in a special place defined by the OS
	#include "filename" tells the compiler to look in the current directory for the source file, if that fails, it does the above
	
	e.g. the #define ....
	#define identifier replacement
		this makes any further occurrence of 'identifier' to be replaced by 'replacement'
		usually the identifier is typed in all caps with underscores for spaces
		
		this is helpful because it can be used to give a descriptive name to something like a number (e.g. a hard-coded number / magic number that does not have any context within the code, but comes for some outside reason)
	
	e.g. the #undef ....
	#undef will undefine a previously defined value
	
	conditional compilation:
	#ifdef		allows the preprocessor to cehck if a value has been previously defined, if so it compiles anything between this and the #endif
	#ifndef		the opposite of above, compile section if item is not defined
	#endif
	
	header guards - prevent the same header from being brought in twice which can cause the compiler to fail
		#ifndef UNIQUE_NAME_HERE  --- if the header has not been called previously, it is included, otherwise it isn't
		#define UNIQUE_NAME_HERE
		// declaratiosn here
		#endif

*/


#include <iostream>

#define MY_NAME "Kim"
#define YEN_PER_DOLLAR 122
	
int main()
{
	using namespace std;
	
	cout << "Hello, " << MY_NAME << endl;
	int nYen = nDollars * YEN_PER_DOLLAR;
	
	return 0;
}

