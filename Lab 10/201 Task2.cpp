#include<bits/stdc++.h>
using namespace std;

class A
{
private:
    int data;
public:
    A(int in_data=0): data(in_data)
    {

    }
    void setData()
    {
        cin>>data;
    }
    int getData()
    {
        return data;
    }

    A& operator = (const A& a)
    {
        data=(a.data)/2;
        return *this;
    }
    A (A& a)
    {
        data = a.data;
    }

    void showData()
    {
        cout<<"Data: "<< data << " address: "<< this <<endl;
    }

};

class B
{
private:
    int _data;
    ///copy constructor and assignment operator is kept private for data hiding.
    ///Thus the objects of this class can't be copied

    B operator = (B& b)
    {  }
    B (B& b): _data(b._data)
    {

    }
public:
    B(int data=0): _data(data)
    {

    }
    void setData()
    {
        cin>>_data;
    }
    int getData()
    {
        return _data;
    }
};

int main()
{

    A a1,a2(10);

    A *aptr = &a1;


    a1.showData();
    a2.showData();
    a1 = a2;
    a1.showData();
    A a3 = a2; /// copy initialization
    a3.showData();

    A a4(a3); ///assignment
    a4.showData();

    cout<<"POINTER"<<endl;

    aptr= &a4;
    aptr->showData();
    aptr=&a3;
    aptr->showData();

    B b1;
    cout<<b1.getData();

   // B b2=b1; ///compiler does not allow it for constructor being private;
    return 0;
}
