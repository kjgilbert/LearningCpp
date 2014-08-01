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
	





*/