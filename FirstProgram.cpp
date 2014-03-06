// working from: http://www.learncpp.com/cpp-tutorial

#include <iostream> // preprocessor directive - this is the in/out stream library for printing to the console

int main()
{
	using namespace std; // also needed with iostram, 'standard' holds the definitions of cout/cin
	cout << "First C++ program!" << endl;
	
	int x; // declaration
	x = 5; // assignment
	cout << x << endl; // output, '<<' is the output operator, cout prints anything sent to it with << to the console
		//endl makes a new line after what is printed
	int y;
	y = x + 2;
	cout << y << endl;
	
	// I can also do this:
	cout << x << " is less than " << y << endl;
	
	// now practice using cin
	cout << "Pick a number" << endl;
	int z = 0; // good practice to always initialize a variable, even as a dummy value, and then check it later to see that it was reassigned
	cin >> z;  // read what I tell the console into z
	cout << "You entered the number " << z << endl;
	
	return 0; // return value, zero generally means a successful run
}

// all statements end with semicolons

/*
remember that I can also do block comments this way
*/

// int is for integer variables
// all variables are also called l-values, an l-value has an address in memory (l because they were on the left side of an assignment statement)
// r- values are the opposite of l-values, they are any value that can be assigned to an l-value, e.g. 5

/* BEWARE of doing something like this:  (uninitialized variable)
#include <iostream>
 
int main()
{
    using namespace std;    // gives us access to cout and endl
    int x;                  // declare an integer variable named x
 
    // print the value of x to the screen (dangerous, because x is uninitialized)
    cout << x << endl;
}
*/


// good habit is to always initialize a variable as it's declared, e.g. int x = 0;