#include <iostream>
 
void IncrementAndPrint()
{
    using namespace std;
    static int s_nValue = 1; // fixed duration
    ++s_nValue;
    cout << s_nValue << endl;
} // s_nValue is not destroyed here, but becomes inaccessible
 
 // static variables are very useful for assigning something a unique ID
 int GenerateID()
{
    static int nNextID = 0;
    return nNextID++;
}

int main()
{
    using namespace std;

    IncrementAndPrint();
    IncrementAndPrint();
    IncrementAndPrint();
    
    int test1 = GenerateID();
    int test2 = GenerateID();
    int test3 = GenerateID();

    cout << "ID1 " << test1 << endl << "ID2 " << test2 << endl << "ID3 " << test3 << endl;
}