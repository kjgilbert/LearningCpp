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
	to assign a character, use single quotes (the following do the same thing)*/
		char chValue = 'a';
		char chValue2 = 97;
/*	because 97th code in ASCII is the letter a
	cout will give the characters, not the underlying numeric code
		if we want to print the numeric cost, cast it as an integer, i.e. cout << (int) chChar;
	likewise, these are not the same: 	*/
		char chValue = '5'; // assigns 53 (ASCII code for '5')
		char chValue2 = 5; // assigns 5
	
/*	escape sequence with a \ in front of something, e.g. a line ending with \n or a tab with \t
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
		can use Donald Knuth's function:	*/
#include <cmath>
bool IsEqual(double dX, double dY)
{
    const double dEpsilon = 0.000001; // or some other small number
    return fabs(dX - dY) <= dEpsilon * fabs(dX);
}


/*	and operator = &&, or operator = ||  useful in multiple comparisons
	not operator = ! and has very high precedence, so be sure to use needed parentheses around it
	the or operator returns true if either side is true or if both sides are true
	
	important to remember that && and || don't evaluate past the first element unless they need to, so if there are iterate steps or something in a later part of the line, they are not necessarily performed
	&& also has higher precedence than || and will be evaluated first, so use ()
	
	!(x && y) is equivalent to !x || !y
	!(x || y) is equivalent to !x && !y
	
	
	declaring a variable outside of any block makes it a global variable accessible anywhere
		they can also be accessed across files, but need a forward declaration to say you will be referring to it
		this is called an extern keyword
			global.cpp:	*/
				// declaration of g_nValue
				int g_nValue = 5;
//			main.cpp:
				// extern tells the compiler this variable is declared elsewhere
				extern int g_nValue;
 
				int main()
				{
				    g_nValue = 7;
				    return 0;
				}
//		Here is an example of using a header file extern:
//				global.cpp:
					// declaration of g_nValue
					int g_nValue = 5;
					global.h:

					#ifndef GLOBAL_H // header guards
					#define GLOBAL_H
					// extern tells the compiler this variable is declared elsewhere
					extern int g_nValue;
					#endif
/*	if a global variable is going to be used in more than 2 files, it’s better to use the header file approach
	Some programmers place all of a programs global variables in a file called globals.cpp, and create a header file named globals.h to be included by other .cpp files that need to use them
	Local variables with the same name as a global variable hide the global variable inside that block. However, the global scope operator (::) can be used to tell the compiler you mean the global version
	Using Hungarian Notation, it is common to declare global variables with a “g_” prefix
	generally best not to use global variables though
	
	a variable can have scope just within one file if it's declared with the static scope, e.g.:	*/
		static int nValue; // file scoped variable
		float fValue; // global variable
		int main()
		{
		    double dValue; // local variable
		}
/*	they are global but only within the one file and cannot be externed to another - also not commonly used
	
	**STATIC means something entirely different when not used outside a block
	Using the static keyword on local variables changes them from automatic duration to fixed duration (also called static duration)
	A fixed duration variable is one that retains it’s value even after the scope in which it has been created has been exited
	Fixed duration variables are only created (and initialized) once, and then they are persisted throughout the life of the program
	Using hungarian notation, it is common to prefix fixed duration variables with “s_”
	
	type conversion - convert data of one type to another type
	in the expression 2 + 3.14159, the + operator requires both operands to be the same type. In this case, the left operand is an int, and the right operand is a double. Because double is higher in the heirarchy, the int gets converted to a double
	the hierarchy is: 
		Long double (highest)
		Double
		Float
		Unsigned long int
		Long int
		Unsigned int
		Int (lowest)
	Char and short are always implicitly promoted to integers (or unsigned integers) before evaluation. This is called widening
	Many mixed conversion work as expected. For example, int nValue = 10 * 2.7 yields the result 27. 10 is promoted to a float, 10.0 * 2.7 evaluates to 27.0, and 27.0 is truncated into an integer (which the compiler will complain about)
	Many new programmers try something like this: float fValue = 10 / 4;. However, because 10 and 4 are both integers, no promotion takes place. Integer division is performed on 10 / 4, resulting in the value of 2, which is then implicitly converted to 2.0 and assigned to fValue
	use casting to tell it to do floating point division
		int nValue1 = 10;
		int nValue2 = 4;
		float fValue = (float)nValue1 / nValue2;
	
	In order to announce to the compiler that you are explicitly doing something you recognize is potentially unsafe (but want to do anyway), you should use a static_cast:
		int nValue = 48;
		char ch = static_cast<char>(nValue);
	casting should be avoided if at all possible, because any time a cast is used, there is potential for trouble. But there are many times when it can not be avoided
	in these cases, the C++ static_cast should be used instead of the C-style cast
	
	An enumerated type is a data type where every possible value is defined as a symbolic constant (called an enumerator). Enumerated types are declared via the enum keyword. Let’s look at an example:
*/		// define a new enum named Color
		enum Color
		{
		    // Here are the enumerators
		    // These define all the possible values this type can hold
		    COLOR_BLACK,
		    COLOR_RED,
		    COLOR_BLUE,
		    COLOR_GREEN,
		    COLOR_WHITE,
		    COLOR_CYAN,
		    COLOR_YELLOW,
		    COLOR_MAGENTA
		};
		// Declare a variable of enumerated type Color
		Color eColor = COLOR_WHITE;
	
/*	Defining an enumerated type does not allocate any memory. When a variable of the enumerated type is declared (such as eColor in the example above), memory is allocated for that variable at that time
	Enum variables are the same size as an int variable. This is because each enumerator is automatically assigned an integer value based on it’s position in the enumeration list

	It is possible to explicitly define the value of enumerator. These integer values can be positive or negative and can be non-unique. Any non-defined enumerators are given a value one greater than the previous enumerator.
*/		// define a new enum named Animal
		enum Animal
		{
    		ANIMAL_CAT = -3,
		    ANIMAL_DOG, // assigned -2
    		ANIMAL_PIG, // assigned -1
    		ANIMAL_HORSE = 5,
    		ANIMAL_GIRAFFE = 5,
    		ANIMAL_CHICKEN // assigned 6
		};
//	because enumerated values evaluate to integers, they can be assigned to integer variables:
		int nValue = ANIMAL_PIG;
//	However, the compiler will not implicitly cast an integer to an enumerated value. The following will produce a compiler error:
		Animal eAnimal = 5; // will cause compiler error
	
/*	Enumerated types are incredibly useful for code documentation and readability purposes when you need to represent a specific number of states
	
	Typedefs allow the programmer to create an alias for a data type, and use the aliased name instead of the actual type name. To declare a typedef, simply use the typedef keyword, followed by the type to alias, followed by the alias name
		typedef long miles; // define miles as an alias for long
		// The following two statements are equivalent:
		long nDistance;
		miles nDistance;
	A typedef does not define new type, but is just another name for an existing type
	they're used for readability
		typedef int testScore;
 		int GradeTest(); // less clear what the returned value means
		testScore GradeTest(); // here we know its returning the score
	
	also makes it easy to go back and change a variable's type just in the one place where it was defined as an int or long for example
	
	a struct is a group of info - a user-defined aggregate of data
		allows us to group variables of mixed data types together into a single unit
	
	Because structs are user-defined, we first have to tell the compiler what our struct looks like before we can begin using it. To do this, we declare our struct using the struct keyword. Here is an example of a struct declaration:
*/		struct Employee
		{
		    int nID;
		    int nAge;
		    float fWage;
		};
//	declare an employee simply by: Employee sJoe;
//	In order to access the individual members, we use the member selection operator (which is a period)
		Employee sJoe;
		sJoe.nID= 14; // initialize nID within sJoe
		sJoe.nAge = 32; // initialize nAge within sJoe
		sJoe.fWage = 24.15; // initialize fWage within sJoe
	
		Employee sFrank; // create an Employee struct for Frank
		sFrank.nID = 15;
		sFrank.nAge = 28;
		sFrank.fWage = 18.27;
	
		int nTotalAge = sJoe.nAge + sFrank.nAge;
		if (sJoe.fWage > sFrank.fWage)
		    cout << "Joe makes more than Frank" << endl;
		// Frank got a promotion
		sFrank.fWage += 2.50;
		// Today is Joe's birthday
		sJoe.nAge++;
	
/*	Another big advantage of using structs over individual variables is that we can pass the entire struct to a function that needs to work with the members
	
	Structs can contain other structs - call something within with another level of dot:  sMyCompany.sCEO.fWage;
	
	Initializing structs member by member is a little cumbersome, so C++ supports a faster way to initialize structs using an initializer list. This allows you to initialize some or all the members of a struct at declaration time.
*/		struct Employee
		{
		    int nID;
		    int nAge;
		    float fWage;
		};
/*		Employee sJoe = {1, 42, 60000.0f}; // nID=1, nAge=42, fWage=60000.0
	this also works for nested structs, just have something like: Company sCo1 = {{1, 42, 60000.0f}, 5};
	It is common to declare structs in a header file, so they can be accessed by multiple source files
	
	
	QUIZ: (4.7)
*/	struct Advertising
	{
		int numAds;
		float percentUsersClicked;
		float earnedPerAd;
	};
	Advertising steak = {5, 0.76, 40};
	void PrintInformation(Advertising sAdvertising)
	{
	    using namespace std;
	    cout << "Number of Ads:   " << sAdvertising.numAds << endl;
	    cout << "Percent of users who clicked on ads:  " << sAdvertising.percentUsersClicked << endl;
	    cout << "Amount earned per ad: " << sAdvertising.earnedPerAd << endl << endl;
		cout << sAdvertising.numAds * sAdvertising.percentUsersClicked * sAdvertising.earnedPerAd << endl;
	}
	
/*	straight-line programs have sequential flow that never changes - not always desired since we may want to allow secondary options if something invalid is entered for e.g.
	flow control statements let the author change the CPU's path through the program
	several tools:
		halt the program at any point = exit()   --- can do exit(0) to return a 0 to the OS, need the C standard library from: #include <cstdlib>
		jump to another statement = goto(), break(), continue()
		conditional branch = if()  -- if statements generate multiple possible paths, there are also switch statements
		loops = do while, while, for  -- repeat something a certain amount of times
		exceptions -- if an error pops up, program goes to the exception - this is advanced
	if (expression)
		statement;
	OR
	if (expression)
		statement;
	else
		statement2;
		
	else statements always pair up with the last unmatched if statement, so bad form to leave only one afte 2 ifs that were nested because it will not be clear which it belongs to
		this is called a dangling else
		so it i best to enclose all if statements within a block
		e.g.:  if (){if () else} else;
	if's can be used as error checking or to do early returns
	
	switches are used instead of doing one after another after another if statement when you want to find variable equality
	the switch expression is evalutated to produce a value, and each case label is tested against this value for equality
	If a case label matches, the statements after the case label are executed. If no case label matches the switch expression, the code under the default label is executed (if it exists)
*/		void PrintColor(Colors eColor)
		{
			using namespace std;
			switch (eColor)		//Floating point variables and other non-integral types may not be used here.
			{
				case COLOR_BLACK:		//this is a case label, it is followed by a constant expression which must be a unique value within that case, and that expression is tested for equality against the expression following the switch keyword
					cout << "Black";		//executed if quality is TRUE
					break;		//this is just to say we're done with this case
				case COLOR_WHITE:
					cout << "White";
					break;
				case COLOR_RED:
					cout << "Red";
					break;
				default:		//this is the default label and is executed only if none of the above match -- it is optional to have here
					cout << "Unknown";
				break;
			}
		}
/*	This also works - multiple case labels for the same statement	*/
		bool IsNumber(char cChar)
		{
    		switch (cChar)
    		{
        		case '0': //if any of the labels match, it returns true
        		case '1':
        		case '2':
        		case '3':
        		case '4':
        		case '5':
        		case '6':
            		return true;
        		default:
            		return false;
    		}
		}
/*	** IMPORTANT to know that a case statement does not stop executing until either it reaches the end of the block, a return statement, a goto statement, or a break statement
		that is why each case has something to stop it from overflowing into the next, otherwise "fall-through" happens
		e.g.:*/	switch (2)
				{
				   case 1: // Does not match -- skipped
				       cout << 1 << endl;
				   case 2: // Match!  Execution begins at the next statement
				       cout << 2 << endl; // Execution begins here
				   case 3:
				       cout << 3 << endl; // This is also executed
				   case 4:
				       cout << 4 << endl; // This is also executed
				   default:
				       cout << 5 << endl; // This is also executed
				}
/*	a break statement tells the compiler that we are done with the current statement (e.g. a switch, or a while or do while or for loop_ and will continue on to the statement after the end of the switch block
	
	QUIZ 5.3:	*/
	using namespace std;
	int Calculate(int x, int y, char z)
	{
		
		switch(z)
		{
			case '+':
				cout << x + y << endl;
				break;
			case '-':
				cout << x - y << endl;
				break;
			case '*':
				cout << x * y << endl;
				break;
			case '/':
				cout << x / y << endl;
				break;
			default:
				cout << "Error" << endl;
				exit(1)
		}
	}	/*
		
	goto statements make the CPU jump to another spot in the code
	useful to make something try again if it fails previously
	The goto statement and it’s corresponding statement label must appear in the same function
		you write a statement label, and follow it with a clon, and then use the goto at a later point to say goto staetment.label;
	you cannot jump forward to a variable that's initialized in the same block as the goto
	generally people don't use goto's
	
	while loop - simplest of all loop types */
		while (expression)
			statement;
//	while expression is true, it will evaluate the statement continuously until expression is no longer true
	int iii = 0;
	while (iii < 10)
	    {
	    cout << iii << " ";
	    iii++;
	    }
	cout << "done!";
/*	have to be careful about infinite loops or it will execute forever
	while (1) {}; will execute forever
	useful to iterate and keep track in the console
*/	// Loop through every number between 1 and 50
	int iii = 1;
	while (iii <= 50)
	{
	    // print the number
	    cout << iii << " "; 
	    // if the loop variable is divisible by 10, print a newline
	    if (iii % 10 == 0)
	        cout << endl; 
	    // increment the loop counter
	    iii++;
	}
/*	5.5 QUIZ:
	we want jjj to return to the value of 1 each time the iii loop iterates
	q2 is in PrintASCII program
	
	do while lets the loop execute at least once even if the condition is false
*/	do
		statement;
	while (condition);
/*	so it checks the condition at the end and either stops if false or continues through again if true
	** NOTE that the variable for which the condition is tested on MUST be declared outside the block, otherwise it will be deleted (b/c of scope) before the condition is reached
	
	for statements are useful when we know exactly how long we want to do something for
*/	for (init-statement; expr1; expr2)
		statement;
/*	Variables with loop scope exist only within the loop, and are not accessible outside of it
	the init-statement is only evaluated once, usually this is a variable declaration and assignment
	then expr1 is evaluated - if false, the loop terminates immediately, if true, then statement is evaluated
	then expr2 is evaluated, usually this increments a variable from the init-statement
	then it evaluates expr1 and repeats
*/	for (int iii=0; iii < 10; iii++) \\ assign iii to zero, while iii < 10, print iii, increment iii by 1 and repeat
    cout << iii << " ";
//	so in the above loop 0-9 will be printed out
int Exponent(int nBase, int nExp)  // returns the value nBase ^ nExp
{
    int nValue = 1;
    for (int iii=0; iii < nExp; iii++)
        nValue *= nBase;
    return nValue;
}	
/*	the above function returns the value nBase^nExp (nBase to the nExp power)
	If nExp is 0, the for loop will execute 0 times, and the function will return 1.
	If nExp is 1, the for loop will execute 1 time, and the function will return 1 * nBase.
	If nExp is 2, the for loop will execute 2 times, and the function will return 1 * nBase * nBase.
	
	avoid off-by-one errors! When writing for loops, remember that the loop will execute as long as expr1 is true 
	it's also possible to omit some parameters: */
int iii=0;
for ( ; iii < 10; )
{
    cout << iii << " ";
    iii++;
}	
/*	that still prints out 0-9
	
	you can also omit the statement that is executed during the loop by simply putting a semicolon there.
		this is called a null statement
	BEWARE of accidentally doing this, e.g.:
	it is easy to make the following mistake: */
if (nValue == 0);
    nValue = 1;
//	The programmer's intent was to assign nValue the value of 1 only if nValue had the value 0. However, due to the misplaced semicolon after the if statement, this actually executes as:
if (nValue == 0)
    ;
nValue = 1;
/*	in the above case, nValue is set to one whether or not it previously equalled zero!!!
	one can also iterate over several variables at once by using a comma */
	for (int iii=0, jjj=9; iii < 10; iii++, jjj--)
    cout << iii << " " << jjj << endl;
/*	
	5.7 QUIZ:
	1. for (i = 0; i <=20; i += 2)
		cout << i << endl;
	2.	int SumTo(int nValue)
		{
			int sumValue;
			for (i=1; i<=nValue; i++)
				sumValue = i + sumValue; // could also do sumValue += i;
			cout << sumValue << endl; // could also do return(sumValue);
		}
	3. it will try to make it -1 before the loop stops, but it was initiated as unsigned, so causes an error and the loop will run forever
	
	5.8-- break and continue
	break statement causes a loop or switch statement to terminate
	continue statement lets you jump back to the beginning of a loop sooner than otherwise reaching the end of the block
*/
for (int iii=0; iii < 20; iii++)
{
    // if the number is divisible by 4, skip this iteration
    if ((iii % 4) == 0)
        continue;
 
    cout << iii << endl;
}
/*	the above program prints all numbers between 0-19 that are not divisible by 4
	BE CAREFUL with continue though since it is easier to create an infinite loop
	
	generally breaks and continues can make flow hard to read, but they can also help a lot
	Keeping the number of nested blocks down often improves code readability more than a break or continue harms it
	
	5.9-- random number generation
	PRNG = pseudo random number generator
		this is a program that takes a starting number called a seed and using math transforms it into some other number seemingly unrelated to the seed
		then repeats to make more "random" numbers
	the c standard library has random number generator functions
		rand() and srand()
		srand() sets the initial seed value. srand() should only be called once
		rand() generates the next random number in the sequence (starting from the seed set by srand())
	rand() generates pseudo-random integers between 0 and RAND_MAX, a constant in cstdlib that is typically set to 32767
	often we want numbers between two other values, not RAND_MAX, which we’ll call nLow and nHigh
		we can take the results of rand() and convert them to what we want
*/
// Generate a random number between nLow and nHigh (inclusive)
unsigned int GetRandomNumber(int nLow, int nHigh)
{
    return (rand() % (nHigh - nLow + 1)) + nLow;
}
/*
	If you run the rand() sample program above multiple times, you will note that it prints the same result every time! This means that while each number in the sequence is seemingly random with regards to the previous ones, the entire sequence is not random at all
		that means our program ends up totally predictable (the same inputs lead to the same outputs every time)
		this can be useful if you want to replicate a result
		that is why you can provide the same seed and get the same answer
	we need some way to pick a seed that’s not a fixed number
		usually done by using the system clock because the time is always different whenever something is run
	time() is a function that returns the number of seconds since midnight on Jan 1, 1970
		uses the ctime header
		then initialize srand() with a call to time(0)
	
	
	arrays - aggregate data type that lets you access multiple variables through a single name by the use of an index
		all the variables within an array must have the same type
		int anTestScores[30]; // allocate 30 integers
		arrays always count from 0 to n-1 where n is the number of elements in the array
*/	int anArray[5]; // Ok -- 5 is a literal constant

	#define ARRAY_SIZE 5
	int anArray[ARRAY_SIZE]; // Ok -- ARRAY_SIZE is a symbolic cons

	int nSize = 5;
	int anArray[nSize]; // Not ok! -- nSize is not a constant!	
/*	
	arrays must be declared using constants
	an array’s size must be known at compile time
		arrays can even hold structs
	elements of an array are treated just like normal variables
	
	* if you don't initialize all the elements of an array, the remaining ones becomes 0's
	// Initialize all elements to 0
	int anArray[5] = { 0 };
	
	if you use a list to initialize the elements of an array, you don't have to say how long the array is
	int anArray[] = { 0, 1, 2, 3, 4 }; // declare array of 5 elements
	
	no direct way to access number of elements in an array, but can do it indirectly:
	int nElements = sizeof(anArray) / sizeof(anArray[0]);
	
	
	QUIZ 6.2
	1)
	double anTemps[365] = { 0 };
	2)
	enum animals
	{
		chicken,
		dog,
		cat,
		elephant,
		duck,
		snake,
		max_animals
	};
	int anAnimals[max_animals] = { 2, 4, 4, 4, 2, 0};
	
	usu. arrays are used with loops
	
	Loops are typically used with arrays to do one of three things:
	1) Search for a value (eg. highest, lowest).
	2) Calculate a value (eg. average, total)
	3) Reorganize the array (eg. sort from lowest to highest)
	
	When searching for a value, a variable is typically used to hold the best candidate value seen so far (or the array index of the best candidate)
	
	QUIZ 6.3
	1)
	int anArray[9] = { 4, 6, 7, 3, 8, 2, 1, 9, 5 };
	for(int nIndex = 0; nIndex < 9 ; nIndex++)
		cout << anArray[nIndex] << \n;
	
	2)
	see "PrintNumber.cpp"
	
	sorting arrays is very useful, done with a few diff. algorithms
		swap function in the C std library can be used to swap elements of an array
		#include <algorithm>
	usu sort by going through the array and moving pairs of things around, e.g.:  */
#include <algorithm> // for swap
#include <iostream>

int main()
{
    using namespace std;

    int x = 2;
    int y = 4;
    cout << "Before swap: x = " << x << ", y = " << y << endl;
    swap(x, y); // swap also lives in std namespace
    cout << "After swap:  x = " << x << ", y = " << y << endl;
}/*
	This program prints:
	Before swap: x = 2, y = 4
	After swap:  x = 4, y = 2
	
	"selection sort" is slower but easy to understand
	Selection sort performs the following steps:
	1) Starting at index 0, search the entire array to find the smallest value
	2) Swap the smallest value found with the value at index 0
	3) Repeat steps 1 & 2 starting from the next index	*/
const int nSize = 5;
int anArray[nSize] = { 30, 50, 20, 10, 40 };

// Step through each element of the array
for (int nStartIndex = 0; nStartIndex < nSize; nStartIndex++)
{
    // nSmallestIndex is the index of the smallest element we've encountered so far.
    int nSmallestIndex = nStartIndex; // THIS ITERATES UP WITH THE LOOP

    // Search through every element starting at nStartIndex+1
    for (int nCurrentIndex = nStartIndex + 1; nCurrentIndex < nSize; nCurrentIndex++)
    {
        // If the current element is smaller than our previously found smallest
        if (anArray[nCurrentIndex] < anArray[nSmallestIndex])
            // Store the index in nSmallestIndex
            nSmallestIndex = nCurrentIndex;
    }

    // Swap our start element with our smallest element
    swap(anArray[nStartIndex], anArray[nSmallestIndex]);
}/*
	
	QUIZ 6.4
	1)
	selection sort {30,60,20,50,40,10}
	
	#include <algorithm> // for swap
	const int nSize = 6;
	int anArray[nSize] = {30,60,20,50,40,10};
	for(int nStart = 0; nStart < nSize; nStart++)
	{
		int nSmallest = nStart;
		for(int nCurrent = nStart + 1; nCurrent < nSize; nCurrent++)
		{
			if (anArray[nCurrent] < anArray[nSmallest])
				nSmallest = nCurrent;
		}
		swap(anArray[nStart], anArray[nSmallest]);
	}
	
	2)
	descending order	
	
	#include <algorithm> // for swap
	const int nSize = 6;
	int anArray[nSize] = {30,60,20,50,40,10};
	for(int nStart = 0; nStart < nSize; nStart++)
	{
		int nLargest = nStart;
		for(int nCurrent = nStart + 1; nCurrent < nSize; nCurrent++)
		{
			if (anArray[nCurrent] > anArray[nLargest])
				nLargest = nCurrent;
		}
		swap(anArray[nStart], anArray[nLargest]);
	}
		
		
	6.5 multidimensional arrays
	elements of an array can be an array!! this is a multidimensional array
		int anArray[3][5]; // a 3-element array of 5-element arrays, i.e. 3 rows, 5 columns
		to access an element: anArray[2][3] = 7;
	In a two-dimensional array, it is convenient to think of the first subscript as 
		being the row, and the 2nd subscript as being the column
	initialize values in it using nested braces, much like Nemo
int anArray[3][5] =
{
{ 1, 2, 3, 4, 5, }, // row 0
{ 6, 7, 8, 9, 10, }, // row 1
{ 11, 12, 13, 14, 15 } // row 2
};
	the compiler actually ignores the inner braces, but keep them for readability!
	it is possible to omit the first size specifier only, but never both
int anArray[][5] =
{
{ 1, 2, 3, 4, 5, },
{ 6, 7, 8, 9, 10, },
{ 11, 12, 13, 14, 15 }
};
	Accessing all of the elements of a two-dimensional array requires two loops: one for the row, and one for the column.
	Usually the row index is in the outer loop
		to go through each column one row at a time
	3-D arrays are possible but harder to initialize (use a loop)
	
	6.6 - strings - a sequence of chars that are interpreted as a piece of text
		they are represented by char arrays that have a null terminator
		meaning the string ends with a \0 (ASCII code 0)
		declare with: char szString[] = "string";
			the above will be of length 7 because it has the null terminator
		the size of a string cannot be changed once it is declared
		you never want to replace with more chars because this will overwrite the null terminator and the CPU won't know where the string ends
			so printing such a thing will continue through the memory slot until it hits a zero
		you can change individual characters in the string by putting that char's location in the brackets []
			remember it counts from zero
char szString[] = "string"; // ok
szString = "rope"; // not ok!
	just like cannot do:
int anArray[] = { 3, 5, 7, 9 };
anArray = 8; // what does this mean?
	
	The recommended way of reading strings using cin is as follows:
char szString[255];
cin.getline(szString, 255);
cout << "You entered: " << szString << endl;
	This call to cin.getline() will read up to 254 characters into szString (leaving room for the null terminator!). 
	Any excess characters will be discarded. In this way, we guarantee that buffer overflow will not occur.
	
	strcpy() allows you to make a copy of a string
	
char szSource[] = "Copy this!";
char szDest[50];
strcpy(szDest, szSource);
cout << szDest; // prints "Copy this!"
	BUT HIS CAN STILL CAUSE BUFFER OVERFLOWS
	
	It is better to use strncpy(), which takes a length parameter to prevent buffer overflow
char szSource[] = "Copy this!";
char szDest[50];
strncpy(szDest, szSource, 49); // copy at most 49 characters (indices 0-48)
szDest[49] = 0; // ensures the last character is a null terminator
cout << szDest; // prints "Copy this!"
	
	Other useful functions:
	strcat() — Appends one string to another (dangerous)
	strncat() — Appends one string to another (with buffer length check)
	strcmp() — Compare two strings (returns 0 if equal)
	strncmp() — Compare two strings up to a specific number of characters (returns 0 if equal)
	strlen() — Returns the length of a string (excluding the null terminator)
	
	THESE STRINGS ARE ALL IN THE STYLE OF PLAIN C
	
	it can be better to use the string class in the standard library for C++ (std::string) which comes from the string header
	these strings can automatically resize if you assign things to them
	e.g.:*/
#include <string> // for std::string
#include <iostream>

int main()
{
    using namespace std; // for both cout and string
    cout << "Enter your name: ";
    string strString;
    cin >> strString;
    cout << "Hello, " << strString << "!" << endl;

    cout << "Your name has: " << strString.length() <<
            " characters in it" << endl;
    cout << "The 2nd character is: " << strString[1] << endl;

    strString = "Dave";
    cout << "Your name is now " << strString << endl;
    cout << "Goodbye, " << strString << endl;

    return 0;
}/*
	One extremely useful function to use with std::string is getline()
	this allows you to read an entire string even if it includes whitespace
	This works:
cout << "Enter your full name: ";
string strName;
getline(cin, strName);
cout << "You entered: "<< strName <<endl;
	
	6.7 Pointers
	a pointer is a variable that holds the address of another variable
	declared with an asterisk between the data type and name
int *pnPtr; // a pointer to an integer value
double *pdPtr; // a pointer to a double value
int* pnPtr2; // also valid syntax
int * pnPtr3; // also valid syntax
	Since pointers only hold addresses, when we assign a value to a pointer, the value 
	has to be an address. To get the address of a variable, we can use the address-of operator (&)
int nValue = 5;
int *pnPtr = &nValue; // assign address of nValue to pnPtr
	this means that pnPtr will have a value of 5 because it points to nValue's address which holds 5
	the type of pointer needs to match the type of variable being pointed to
	
	dereference operator '*' evaluates the contents of the address it is pointing to
	address symbol is '&'
int nValue = 5;
cout << &nValue; // prints address of nValue
cout << nValue; // prints contents of nValue
	
int *pnPtr = &nValue; // pnPtr points to nValue
cout << pnPtr; // prints address held in pnPtr, which is &nValue
cout << *pnPtr; // prints contents pointed to by pnPtr, which is contents of nValue
	so, when pnPtr is assigned to &nValue:
		pnPtr is the same as &nValue
		*pnPtr is the same as nValue
	Because *pnPtr is the same as nValue, you can assign values to it just as if it were nValue
	
	sometimes it is useful to make a pointer to nothing, this is called a null pointer
		assigned by setting it to address 0
int *pnPtr;
pnPtr = 0; // assign address 0 to pnPtr
	OR
int *pnPtr = 0;  // assign address 0 to pnPtr
	
	C (but not C++) also defines a special preprocessor define called NULL that evaluates to 0. 
	Even though this is not technically part of C++, it’s usage is common enough that it will work in every C++ compiler
	
	null pointers are useful inside conditionals, to test if they have a value or not
		also often used w/ dynamic memory allocation
	the size of the pointer is always the same. This is because a pointer is just a memory address, 
	and the number of bits needed to access a memory address on a given machine is always constant
	
	6.8 pointers, arrays, and pointer arithmetic
	
	arrays are actually in effect pointers that point to the first element of the array
	so dereferencing an array returns element 0 (first element) of that array
	because you can also do integer math on pointers, you can simply point to the next or previous space with pnPntr + 1 (or - 1)
	it is not pointing to the address, but the next object of whatever type the array contains
	the compiler automatically scales the objects by their byte size
	it is rare to see + a number of minus 1 number with arrays
	BUT ++ or -- are common for moving through contents of an array via pointers!
	
	* operator has higher precedence than addition, so parentheses are necessary, e.g.:
int anArray[5] = { 9, 7, 5, 3, 1 };
cout << *(anArray+1) << endl; // prints 7
	
	6.9 Dynamic memory allocation
	because everything muts be declared at compile time, it can be difficult to do things conditionally
	Dynamic memory allocation allows us to allocate memory of whatever size we want when we need it
	
	To allocate a single variable dynamically, we use the scalar (non-array) form of the new operator:
		int *pnValue = new int; // dynamically allocate an integer
	The new operator returns the address of the variable that has been allocated
	
	This address can be stored in a pointer, and the pointer can then be dereferenced to access the variable.
int *pnValue = new int; // dynamically allocate an integer
*pnValue = 7; // assign 7 to this integer
	When we are done with a dynamically allocated variable, we need to explicitly tell C++ to free the memory for reuse. This is done via the scalar (non-array) form of the delete operator:
delete pnValue; // unallocate memory assigned to pnValue
pnValue = 0;
	(the delete operator does not delete the pointer — it deletes the memory that the pointer points to)
	
	To allocate an array dynamically, we use the array form of new and delete (often called new[] and delete[]):
int nSize = 12;
int *pnArray = new int[nSize]; // note: nSize does not need to be constant!
pnArray[4] = 7;
delete[] pnArray;	
	Because we are allocating an array, C++ knows that it should use the array version of new instead 
	of the scalar version of new. Essentially, the new[] operator is called, even though the [] isn’t 
	placed next to the new keyword
	
	When deleting a dynamically allocated array, we have to use the array version of delete, which 
	is delete[]. This tells the CPU that it needs to clean up multiple variables instead of a single variable
	
	Using the scalar version of delete on an array can cause data corruption or other problems
	
	Dynamically allocated memory effectively has no scope. That is, it stays allocated until it is explicitly deallocated or until the program ends
	However, the pointers used to access dynamically allocated memory follow the scoping rules of normal variables
	
	memory leak - if a dynamically allocated integer can not be or was not deleted, and its address can not be reallocated or reused
	Memory leaks eat up free memory while the program is running, making less memory available not only to this program, but to other programs as well
	
	Memory leaks can also result if the pointer holding the address of the dynamically allocated memory is reassigned to another value:
int nValue = 5;
int *pnValue = new int;
pnValue = &nValue; // old address lost, memory leak results
	It is also possible to get a memory leak via double-allocation:
int *pnValue = new int;
pnValue = new int; // old address lost, memory leak results
	The address returned from the second allocation overwrites the address of the first allocation. Consequently, the first allocation becomes a memory leak
	
	Null pointers (pointers set to address 0) are particularly useful when dealing with dynamic 
	memory allocation. A null pointer basically says “no memory has been allocated yet”. This allows us to do things like conditionally allocate memory:
// If pnValue isn't already allocated, allocate it
if (!pnValue)
    pnValue = new int;
    
    it is a good idea to set all pointers that are not used right away to 0
int *pnValue = new int;
int *pnOtherValue = 0; // will allocate later
	Similarly, when a dynamically allocated variable is deleted, the pointer pointing to it 
	is not zero’d. Consider the following snippet:
int *pnValue = new int;
delete pnValue; // pnValue not set to 0
if (pnValue)
    *pnValue = 5; // will cause a crash
		Because pnValue has not been set to 0, the if statement condition evaluates to true, 
		and the program tries to assign 5 to deallocated memory. This almost inevitably will cause 
		a program to crash. It is never a good idea to leave a pointer pointing to deallocated memory. 
		When deallocating memory, set the pointer that has been deallocated to 0 immediately afterward
	need to add this line in program above: pnValue = 0;
	
	Finally, deleting a null pointer has no effect. Thus, there is no need for the following:
if (pnValue)
    delete pnValue;
		Instead, you can just write:
delete pnValue;
		If pnValue is non-null, the dynamically allocated variable will be deleted. If it is null, nothing will happen
	
	Just like normal variables, pointers can be declared constant. 
	There are two different ways that pointers and const can be intermixed, and they are very easy to mix up
	
	To declare a const pointer, use the const keyword between the asterisk and the pointer name
int nValue = 5;
int *const pnPtr = &nValue;
	Just like a normal const variable, a const pointer must be initialized to a value upon declaration, 
		and its value can not be changed. This means a const pointer will always point to the same value
	pnPtr will always point to the address of nValue in the above example
	However, because the value being pointed to is still non-const, it is possible to change 
		the value being pointed to via dereferencing the pointer
	
	It is also possible to declare a pointer to a constant variable by using the const before the data type.
int nValue = 5;
const int *pnPtr = &nValue;
*pnPtr = 6; // allowed, since pnPtr points to a non-const int
	
	Because a pointer to a const value is a non-const pointer, the pointer can be redirected to point at other values:
int nValue = 5;
int nValue2 = 6;
const int *pnPtr = &nValue;
pnPtr = &nValue2; // okay
	
	
	To summarize:
		A non-const pointer can be redirected to point to other addresses.
		A const pointer always points to the same address, and this address can not be changed.
		A pointer to a non-const value can change the value it is pointing to.
		A pointer to a const value treats the value as const (even if it is not), and thus can not change the value it is pointing to.
	
	6.11 References
	References are a type of C++ variable that act as an alias to another variable
	A reference variable acts just like the original variable it is referencing. 
	References are declared by using an ampersand (&) between the reference type and the variable name
int nValue = 5; // normal integer
int &rnRef = nValue; // reference to nValue
	this ampersand does not indicate an address of something
	
	References are implicitly const. Like normal constant objects, references must be given a value upon declaration
	a reference can not be “redirected” to another variable. Consider the following snippet:
int nValue = 5;
int nValue2 = 6;
int &rnRef = nValue;
rnRef = nValue2; // assigns value 6 to nValue -- does NOT change the reference!
	
	references are often used as function parameters because they allow us to access but not change the value of an object
	they also work well to provide access to nested data, e.g. in a struct
	
	Consider the following struct:
struct Something
{
    int nValue;
    float fValue;
};
struct Other
{
    Something sSomething;
    int nOtherValue;
};
Other sOther;

int &rnValue = sOther.sSomething.nValue;
// rnValue can now be used in place of sOther.sSomething.nValue
	
	6.12 references vs pointers and member selection
	References and pointers have an interesting relationship — a reference acts like a 
	const pointer that is implicitly dereferenced
int nValue = 5;
int *const pnValue = &nValue;
int &rnValue = nValue;
	*pnValue and rnValue evaluate identically. As a result, the following two statements produce the same effect:
*pnValue = 6;
rnValue = 6;
	
	Similarly, a const reference acts just like a const pointer to a const object that is implicitly dereferenced
	Because references always “point” to valid objects, and can never be pointed to deallocated memory, references are safer to use than pointers
	If a task can be solved with either a reference or a pointer, the reference should generally be preferred
	Pointers should generally only be used in situations where references are not sufficient (such as dynamically allocating memory)
	
	It is common to have either a pointer or a reference to a struct (or class). 
	You can select the member of a struct using the member selection operator (.)
	
struct Something
{
    int nValue;
    float fValue;
};

// Member selection using actual struct variable
Something sSomething;
sSomething.nValue = 5;

// Member selection using reference to struct
Something &rsSomething = sSomething;
rsSomething.nValue = 5;

// Member selection using pointer to struct
Something *psSomething = &sSomething;
(*psSomething).nValue = 5;

	Note that the pointer dereference must be enclosed in parenthesis, because the member 
	selection operator has a higher precedence than the dereference operator
	
	syntax for access to structs and class members through a pointer is awkward so C++ offers 
	a second member selection operator (->) for doing member selection from pointers. 
	The following two lines are equivalent:
(*psSomething).nValue = 5;
psSomething->nValue = 5;
	when doing member access through a pointer, always use the -> operator
		it is easier to write
		and there are no precedence issues to worry about
	
	
	6.13 Void pointers
	The void pointer, also known as the generic pointer, is a special type of pointer that 
		can be pointed at objects of any data type
	A void pointer is declared like a normal pointer, using the void keyword as the pointer’s type
void *pVoid; // pVoid is a void pointer
	A void pointer can point to objects of any data type:
int nValue;
float fValue;
struct Something
{
    int nValue;
    float fValue;
};
Something sValue;
void *pVoid;
pVoid = &nValue; // valid
pVoid = &fValue; // valid
pVoid = &sValue; // valid
	
	However, because the void pointer does not know what type of object it is pointing to, it can not be dereferenced
	the void pointer must first be explicitly cast to another pointer type before it is dereferenced
	it is also NOT possible to do pointer arithmetic on a void pointer
	
	Here’s an example of a void pointer in use:*/

#include <iostream>

enum Type
{
    INT,
    FLOAT,
    STRING,
};

void Print(void *pValue, Type eType)
{
    using namespace std;
    switch (eType)
    {
        case INT:
            cout << *static_cast<int*>(pValue) << endl;
            break;
        case FLOAT:
            cout << *static_cast<float*>(pValue) << endl;
            break;
        case STRING:
            cout << static_cast<char*>(pValue) << endl;
            break;
    }
}

int main()
{
    int nValue = 5;
    float fValue = 7.5;
    char *szValue = "Mollie";

    Print(&nValue, INT);
    Print(&fValue, FLOAT);
    Print(szValue, STRING);
    return 0;
}
	/*This program prints:
	5
	7.5
	Mollie
	
	the above function seems like a neat way to make a single function handle multiple data 
	types, C++ actually offers a much better way to do the same thing (via function overloading) 
	that retains type checking to help prevent misuse
	
	CHAPTER 7
	
	
	
*/