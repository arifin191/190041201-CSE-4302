#include<bits/stdc++.h>
using namespace std;

class Person
{
protected:
    string name;
    int salary;
public:
    Person(string in_name="", int in_salary=0): name(in_name), salary(in_salary)
    {

    }
    void setData()
    {
        cout<<"Enter the person's name:"<<endl;
        cin>>name;
        cout<<"Enter the person's salary:"<<endl;
        cin>>salary;
    }

    ///Using  a pure virtual function will make this base class abstract
    //virtual void getData()=0;

    ///Virtual function
    virtual void getData()
    {
        cout<<"Name :"<< name <<endl ;
        cout<<"Salary :"<< salary <<endl ;
    }

};


class Teacher : public Person
{
protected:
    string institution;

public:
    Teacher(string in_inst=""): institution(in_inst)
    {

    }

    void setData()
    {
        Person::setData();
        cout<<"Enter the person's institution:"<<endl;
        cin>>institution;
    }

    ///In case of pure virtual function, the function must be overloaded in
    /// derived class. For virtual function it's recommended but not mandatory.

    void getData()
    {
        cout<<"Name :"<< name <<endl ;
        cout<<"Salary :"<< salary <<endl ;
        cout<<"Institution :"<< institution <<endl ;
    }


};


int main()
{
    Person p1("John", 1000); ///Declaration of pure virtual function will not allow this
    p1.getData();


    Teacher t1;
    t1.setData();
    t1.getData();
    return 0;
}
