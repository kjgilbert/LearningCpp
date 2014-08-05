#include <iostream>
 
 struct Employee
{
    int nID;
    int nAge;
    float fWage;
};

void PrintInformation(Employee sEmployee) //we pass an entire Employee struct to PrintInformation(). This prevents us from having to pass each variable individually.
{
    using namespace std;
    cout << "ID:   " << sEmployee.nID << endl;
    cout << "Age:  " << sEmployee.nAge << endl;
    cout << "Wage: " << sEmployee.fWage << endl << endl;
}

//Quiz:
// First we need to define our Advertising struct
struct Advertising
{
    int nAdsShown;
    float fClickThroughRate; // as a %
    float fAverageEarningsPerClick;
};
void PrintAdvertising(Advertising sAd)
{
    using namespace std;
    cout << "Number of ads shown: " << sAd.nAdsShown << endl;
    cout << "Click through rate: " << sAd.fClickThroughRate << endl;
    cout << "Average earnings per click: $" << sAd.fAverageEarningsPerClick << endl;
 
    // The following line is split up to reduce the length
    cout << "Total Earnings: $" <<
        (sAd.nAdsShown * sAd.fClickThroughRate * sAd.fAverageEarningsPerClick) << endl;
}
struct Fraction
{
    int nNumerator;
    int nDenominator;
}; 
void Multiply(Fraction sF1, Fraction sF2)
{
    using namespace std;
 
    // Don't forget the static cast, otherwise the compiler will do integer division!
    cout << static_cast<float>(sF1.nNumerator * sF2.nNumerator) /
        (sF1.nDenominator * sF2.nDenominator) << endl;
}


 
int main()
{
    Employee sJoe; // create an Employee struct for Joe
    sJoe.nID = 14;
    sJoe.nAge = 32;
    sJoe.fWage = 24.15;
 
    Employee sFrank; // create an Employee struct for Frank
    sFrank.nID = 15;
    sFrank.nAge = 28;
    sFrank.fWage = 18.27;
 
    // Print Joe's information
    PrintInformation(sJoe);
 
    // Print Frank's information
    PrintInformation(sFrank);
 
 
	//Quiz:
	using namespace std;
    // Declare an Advertising struct variable
    Advertising sAd;
 
    cout << "How many ads were shown today? ";
    cin >> sAd.nAdsShown;
    cout << "What was the click through rate? ";
    cin >> sAd.fClickThroughRate;
    cout << "What was the average earnings per click? ";
    cin >> sAd.fAverageEarningsPerClick;
 
    PrintAdvertising(sAd);
    
    
    
    // Allocate our first fraction
    Fraction sF1;
    cout << "Input the first numerator: ";
    cin >> sF1.nNumerator;
    cout << "Input the first denominator: ";
    cin >> sF1.nDenominator;
 
    // Allocate our second fraction
    Fraction sF2;
    cout << "Input the second numerator: ";
    cin >> sF2.nNumerator;
    cout << "Input the second denominator: ";
    cin >> sF2.nDenominator;
 
    Multiply(sF1, sF2);
    
 
    return 0;
}