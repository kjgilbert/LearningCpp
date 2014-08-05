//GoTo statements are SHUNNED!!! because it is logically difficult to follow the flow of the program

#include <iostream>
#include <cmath>
 
int main()
{
    using namespace std;
tryAgain: // this is a statement label
    cout << "Enter a non-negative number";
    double dX;
    cin >> dX;
 
    if (dX < 0.0)
        goto tryAgain; // this is the goto statement
 
    cout << "The sqrt of " << dX << " is " << sqrt(dX) << endl;
}