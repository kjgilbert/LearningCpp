#include <iostream>

int main()
{
    using namespace std;
    unsigned short x = 65535; // largest 2-byte unsigned value possible
    cout << "x was: " << x << endl;
    x = x + 1; // We desire 65536, but we get overflow!
    cout << "x is now: " << x << endl;
    
    
    // overflow at the bottom of the range
    unsigned short y = 0; // smallest 2-byte unsigned value possible
    cout << "y was: " << y << endl;
    y = y - 1; // We expect -1, we get overflow!
    cout << "y is now: " << y << endl;
}