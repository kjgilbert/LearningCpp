/*
data types:
	bool	boolean, yes or no
	char	character
	wchar_t
	short	(short int)
	int		integer, whole number
	long	(long int)
	float	floating point, decimal place number (real number), numbers differ in size and precision
	double	floating point number?
	long double
	
	int x, y; works as would    int x = 5, y = 6;

	convention to start all identifiers (names of variables or functions) with lowercase letter
	also convention to either intercap multiword names or use underscores
	
	Hungarian notation is to start each names with a prefix letter that indicates its type
	e.g.: int nValue or bool bValue
	
	\t inserts a tab, useful later
	
	char, short, int & long are all considered integer type variables because they only hold whole numbers
		just vary in size they can hold
	short int nShort; works as does the shorthand   short nShort; (no pun intended)
	same for long int and just plain long
	
	can do signed int or unsigned int when declaring to allow positives/negatives or no signs, and helps hold the desired range of numbers in the space provided
		default is to be signed
	
	we get overflow if you try to put a number outside the data type's range into a variable
	
	integer division always drops the fraction and rounds down
	
	3 different floating point data types: float, double, and long double
		these are always signed, increase in size in the order I just listed
		best to assign numbers to them with a decimal even if it's just 5.0
	can use scientific notation to assign numbers to floating point variables
		e.g. double dValue = 5e-2;
	must be cautious about precision, as it can't be held past the amount the data type can hold.
	
	there are rounding errors that occur too because of how binary stores numbers, e.g. 1/10 comes out as 0.10000000000000001
		can cause problems with == comparisons
	
	boolean variables are assigned as either true or false, e.g. bool bValue = true; OR bool bValue = false;
		but when they're evaluated, 0 is false and 1 is true
	to do if(true) instead type if(1)    or for false if(0)
	and can also use ! to do the opposite, e.g. !true = not true = false
	convention for naming boolean functions is often to use "is", e.g. bool IsEqual(int x, int y) return x == y;

	all non-zero integers resolve to true, while only 0 resolves to false
	
	chars hold a small number or a character in ASCII
	to assign a character, use single quotes (the following do the same thing)
		char chValue = 'a';
		char chValue2 = 97;
	because 97th code in ASCII is the letter a
	cout will give the characters, not the underlying numeric code
		if we want to print the numeric cost, cast it as an integer, i.e. cout << (int) chChar;
	likewise, these are not the same: 
		char chValue = '5'; // assigns 53 (ASCII code for '5')
		char chValue2 = 5; // assigns 5
	
	escape sequence with a \ in front of something, e.g. a line ending with \n or a tab with \t
		\' prints a single quote, \" a double and \\ a backslash
		fun one maybe ->  \a makes an alert, the page says this may make the computer beep!
	
	constants - can be literal or symbolic
		literal constants are numbers that never change, e.g. int x = 5;
	you can declare a symbolic constant with a preprocessor directive, e.g.:
		#define YEN_PER_DOLLAR  122
		int nYen = nDollars * YEN_PER_DOLLAR;
	they can also be made with the "const" keyword, e.g. const int nYen = 122;
		there will be a compiler error if you try to change its value anywhere else
		this is generally better because #define's make things with global scope and defined symbolic constants do not show up in the debugger
	
	in the expression x = 5 - -3;, the first minus is the subtraction operator, and the second is the unary minus operator
	
	the % operand (modulus) gives the remainder of x divided by y, e.g. for x % y
		be careful when using it with negative numbers as it may give either a positive or negative answer for the same result depending on the system
	
	iteration shortcuts: 
		for x = x + y; can also do x += y
		for x = x * 5; can also do x *=5
		for x = x + 1; can do ++x, x++ where the order of these matters (++x adds one then evaluates x vs opposite for x++) --- same for --x and x--
		*** int y = x++; // x is now equal to 6, and 5 is assigned to y
		
	commas allow both expressions to be evaluated, e.g . int z = (++x, ++y); // increment x and y, SO HERE Z = 3 if y was 2 before, regardless of X
		usu. only used in for loops: for (int iii = 1, jjj = 10; iii <= 10; iii++, jjj--)
	
	arithmetic if operator:  " ?: " takes 3 operands to do a type of if/else statement
			if (condition)
    			x = some value
			else
  			  x = some other value
		can be rewritten as:
			x = (condition) ? some value : some other value;
		For example, to put the larger of values x and y in variable z, we could write this:
			z = (x > y) ? x : y;
			and to print it out:  cout << ((x > y) ? x : y);
	**reminder not to use == with floating point numbers since even slight rounding errors will make it false
		can use Donald Knuth's function:
#include <cmath>
bool IsEqual(double dX, double dY)
{
    const double dEpsilon = 0.000001; // or some other small number
    return fabs(dX - dY) <= dEpsilon * fabs(dX);
}


	and operator = &&, or operator = ||  useful in multiple comparisons
	not operator = ! and has very high precedence, so be sure to use needed parentheses around it
	the or operator returns true if either side is true or if both sides are true
	
	important to remember that && and || don't evaluate past the first element unless they need to, so if there are iterate steps or something in a later part of the line, they are not necessarily performed
	&& also has higher precedence than || and will be evaluated first, so use ()
	
	!(x && y) is equivalent to !x || !y
	!(x || y) is equivalent to !x && !y
	
	
	
		
	

*/