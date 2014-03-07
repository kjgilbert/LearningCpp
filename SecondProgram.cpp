#include <iostream>
#include "SecondProgram_Header.h"  // include the header with the multiply function prototype


/*
forward declaration can be used so that functions called within other functions don't necessarily have to be defined first
	do so by declaring it before defining it, in what is called a function prototype
	this includes the function's name, parameters, and return type
if you forward declare but forget to define the function, but still call it, the program still compiles and gives a 'could not resolve' error
*/



int add(int x, int y); //forward declaration here
// I could equally do:
// int add(int, int);

// forward declare the function in the additional file (usu. better to use a header, but this is a simple example)
int subtract(int x, int y);

int main()
{
	using namespace std;
	cout << "The sum of 3 and 4 is: " << add(3, 4) << endl;
	cout << "The difference of 3 and 4 is: " << subtract(3, 4) << endl;
	cout << "The product of 3 and 4 is: " << multiply(3, 4) << endl;  // don't need a forward declaration anywhere because we're using a header file
	
	return 0;
}


int add(int x, int y) // this is a silly example because we could just move this to the top, but it makes a point for more complicated programs
{
	return x + y;
}



// easy to compile this with:   g++ -o SecondProgram SecondProgram.cpp SecondProgram_Subtract.cpp