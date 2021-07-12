#include<iostream>

using namespace std;

class Counter
{
private:
    int Count,step;
public:
    Counter():Count(0),step(1)
    {

    }
    Counter(int C,int S):Count(C),step(S)
    {

    }
    void setIncrementStep(int step_val)
    {
        if(step_val<0)
        {
            cout<<"ERROR!\n";
            return;
        }
        else step=step_val;
    }
    int getCount()
    {
        return Count;
    }
    void increment()
    {
        Count+=step;
    }
    void resetCount()
    {
        Count=0;
    }
    Counter operator +(Counter a)
    {
        return Counter(Count+a.Count,min(step,a.step));
    }
    Counter operator +(int var)
    {
        return Counter(Count+var,step);
    }
    friend Counter operator +(int var,Counter a)
    {
        return Counter(a.Count+var,a.step);
    }
    Counter operator ++()
    {
        Count+=step;
        return Counter(Count,step);
    }

    Counter operator ++(int)
    {
        Count+=step;
        return Counter(Count,step);
    }
    Counter operator +=(Counter a)
    {
        return Counter(Count+a.Count, step);
    }

};

int main()
{
    int c,s;
    Counter c1;
    cout<<"At the beginning:\n";
    cout<<c1.getCount()<<endl;
    c1.setIncrementStep(2);
    c1.increment();
    cout<<"After Increasing:\n";
    cout<<c1.getCount()<<endl;
    c1.resetCount();
    cout<<"After Resetting:\n";
    cout<<c1.getCount()<<endl;

    Counter c2(4,3);
    Counter c3(5,2);
    c1=c2+c3;
    cout<<"After adding c2 and c3 into c1:\n";
    cout<<c1.getCount()<<endl;
    cout<<"After adding c2 and a variable to c1:\n";
    c1=c2+10;
    cout<<c1.getCount()<<endl;
    c1=5+c2;
    cout<<"After adding a variable and c2 to c1:\n";
    cout<<c1.getCount()<<endl;
    cout<<"After c1=c2++:\n";
    c1=c2++;
    cout<<c1.getCount()<<endl;
    cout<<"After c1=++c2:\n";
    c1=++c2;
    cout<<c1.getCount()<<endl;
    cout<<"After c1+=c2:\n";
    c1+=c2;
    cout<<c1.getCount()<<endl;

}
