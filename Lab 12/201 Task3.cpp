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
    class OutOfBound
    {
    public:
        int val;
        OutOfBound(int v)
        {
            val=v;
        }
    };
    T& operator [](int n) //note: return by reference
    {
        if( n< 0 || n>=LIMIT )
        {
//            cout << "\nIndex out of bounds";
//            exit(1);
            throw OutOfBound(n);
        }
        return arr[n];
    }
};
////////////////////////////////////////////////////////////////
int main()
{

    try
    {
        safearay<double> sa1;
        for(int j=0; j<LIMIT+5; j++) //insert elements
            sa1[j] = j*0.5; //*left* side of equal sign
        for(int j=0; j<LIMIT; j++) //display elements
        {
            double temp1 = sa1[j]; //*right* side of equal sign
            cout << "Element " << j << " is " << temp1 << endl;
        }

    }
    catch( safearay<double>::OutOfBound ob )
    {
        cout<<"Out of Bound at "<< ob.val <<endl;
    }


    return 0;
}
