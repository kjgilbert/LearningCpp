#include <iostream>
 
int main()
{
    using namespace std;
    cout << "Enter a number: ";
    int nX;
    cin >> nX;
 
    if (nX > 10)
        {
        // both statements will be executed if nX > 10
        cout << "You entered " << nX << endl;
        cout << nX << " is greater than 10" << endl;
        }
    else
        {
        // both statements will be executed if nX <= 10
        cout << "You entered " << nX << endl;
        cout << nX << " is not greater than 10" << endl;
        }
        
        
        
        
    cout << "Enter another number: ";
    int nX2;
    cin >> nX2;
 
    if (nX2 > 10)
        cout << nX2 << " is greater than 10" << endl;
    else if (nX2 < 5)
        cout << nX2 << " is less than 5" << endl;
    // could add more else if statements here
    else
        cout << nX2 << " is between 5 and 10" << endl;
 
    return 0;
}