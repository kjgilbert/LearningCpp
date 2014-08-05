// question 2 for quiz 5.5
#include <iostream>

//want to write a program that prints out the letters a-z along with their ASCII codes. 
//	Hint: to print characters as integers, you have to use a static_cast.

int main()
{
    using namespace std;
	char chChar = 'a';
	while (chChar < 'a' + 26) //go until the 26th letter of the alphabet is finished
	// could also have done while (chChar <= 'z')
	{
		cout << chChar << " ";	// print the ascii character
		cout << (int)chChar	<< endl;	//print the ascii code
		chChar++; //yes, this works because chars are stored as their numeric code, and the alphabet iterates up from 'a'
	}    
	return(0);
}