#include<bits/stdc++.h>
using namespace std;

class Calculator
{
    private:
        int field;
    public:
        Calculator()
        {
            field=0;
        }
        Calculator(int val)
        {
            field=val;
        }
        void geValue()
        {
            cout<<"Enter the value";
            cin>>field;
        }

        void setValue(int Value)
        {
            field=Value;
        }
        void add (int Value)
        {

            field+=Value;
        }
        void subtract (int Value)
        {

            field-=Value;
        }
        void multiply (int Value)
        {

            field*=Value;
        }
        void divideBy(int Value)
        {

            if(Value)  field/=Value;
            else {
                cout<<"Error : divide by 0 is undefined."<<endl;
            }
        }

        void display()
        {

            cout<<"Calculator display: ";
            cout<<field<<endl;
        }


        void clear()
        {

            field=0;
        }
        ~Calculator()
        {
            cout<<"Calculator object is destroyed."<<endl;
        }


};




int main()
{
    Calculator calc1;
    calc1.add(10);
    calc1.display();
    calc1.add(7);
    calc1.display();
    calc1.multiply (31);
    calc1.display();
    calc1.subtract (42);
    calc1.display();
    calc1.divideBy (7);
    calc1.display();
    calc1.divideBy (0);
    calc1.display();
    calc1.add (3);
    calc1.display();
    calc1.subtract (1);
    calc1.display();
    calc1.clear();
    calc1.display();

    return 0;
}
