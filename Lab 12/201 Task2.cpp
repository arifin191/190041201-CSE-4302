// arrover3.cpp
#include <iostream>
using namespace std;
#include <process.h> //for exit()
const int LIMIT = 10; //array size

template<class T>
T amax( T* array, int maxSizeOfArray)
    {
        T maxValue = array[0];
        for(int i = 0; i < maxSizeOfArray; i++)
            if (array[i] > maxValue)
                maxValue = array[i];

        return maxValue;
    }
int main()
{
    double sa1[10];
    for(int j=0; j<LIMIT; j++)
        sa1[j] = j*0.5;
    cout<< amax(sa1, 10)<<endl;

    int sa2[10];
    for(int j=0; j<LIMIT; j++)
        sa1[j] = j*10;
    cout<< amax(sa1, 10)<<endl;


    return 0;
}
