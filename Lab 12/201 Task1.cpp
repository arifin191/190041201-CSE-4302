// arrover3.cpp
#include <iostream>
using namespace std;
#include <process.h> //for exit()
const int LIMIT = 10; //array size
////////////////////////////////////////////////////////////////

template<class T>
class safearay
{
private:
   T arr[LIMIT];
public:
    T& operator [](int n) //note: return by reference
    {
        if( n< 0 || n>=LIMIT )
        {
            cout << "\nIndex out of bounds";
            exit(1);
        }
        return arr[n];
    }
};
////////////////////////////////////////////////////////////////
int main()
{
    safearay<double> sa1;
    for(int j=0; j<LIMIT; j++) //insert elements
        sa1[j] = j*0.5; //*left* side of equal sign
    for(int j=0; j<LIMIT; j++) //display elements
    {
        double temp1 = sa1[j]; //*right* side of equal sign
        cout << "Element " << j << " is " << temp1 << endl;
    }

    cout<<"\n_____________\n\n";

    safearay<char> sa2;
    for(int j=0;j<LIMIT;j++)
    {
        sa2[j]= (char)(j+65);
    }
    for(int j=0; j<LIMIT; j++)
    {
        char temp2 = sa2[j];
        cout << "Element " << j << " is " << temp2 << endl;
    }
    return 0;
}
