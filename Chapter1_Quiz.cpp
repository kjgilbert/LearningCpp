// Chapter 1 quiz -- http://www.learncpp.com/cpp-tutorial/111-comprehensive-quiz/

//#include <iostream> // This can now be commented out since I use the in out library in the io.cpp file
#include "io.h"  	// include the header with the multiply function prototype

/*  now comment this out and instead use io.cpp to read the functions in
//that is done during the compile step in the command line with:
//		g++ -o Ch1Quiz Chapter1_Quiz.cpp io.cpp
int ReadNumber()
{
	using namespace std;
	cout << "Provide a number: ";
	int x;
	cin >> x;
	return x;
}

void WriteAnswer(int x)
{
	using namespace std;
	cout << "The answer is " << x << endl;
}
*/


/* now comment these out and instead use a header file
// these are forward declarations now that the above functions are in their own file
int ReadNumber();
void WriteAnswer(int x);
*/
	
int main()
{
	int x = ReadNumber();
	int y = ReadNumber();
	int z = x + y;
	WriteAnswer(z);
	// OR could have just done WriteAnswer(x + y);
	return 0;
}

// **** DO NOT COMPILE WITH THE HEADER FILE or gives an error.
// it will call the header file if you've properly told it to, from the current directory
