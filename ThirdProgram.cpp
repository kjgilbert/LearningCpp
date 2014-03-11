/*
	using preprocessors:
	
	e.g. the #include ....
	#include <filename> tells the compiler to look for the file in a special place defined by the OS
	#include "filename" tells the compiler to look in the current directory for the source file, if that fails, it does the above
	
	e.g. the #define ....
	#define identifier replacement
		this makes any further occurrence of 'identifier' to be replaced by 'replacement'
		usually the identifier is typed in all caps with underscores for spaces

*/


#include <iostream>

#define MY_NAME "Kim"
	
int main()
{
	using namespace std;
	
	cout << "Hello, " << MY_NAME << endl;
	
	return 0;
}

