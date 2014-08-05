// when calling this program, it starts, then type stuff in, then it stops when you hit enter

#include <cstdio> // for getchar()
#include <iostream>
 
using namespace std;
 
int main()
{
    // count how many spaces the user has entered
    int nSpaceCount = 0;
 	cout << "Type the desired text then hit enter." << endl;
    // loop 80 times - i.e. only counts up to 80 characters and the spaces contained within
    for (int nCount=0; nCount < 80; nCount++)
    {
        char chChar = getchar(); // read a char from user
 
        // exit loop if user hits enter
        if (chChar == '\n')
            break;
 
        // increment count if user entered a space
        if (chChar == ' ')
            nSpaceCount++;
    }
 
    cout << "You typed " << nSpaceCount << " spaces" << endl;
 
    return 0;
}