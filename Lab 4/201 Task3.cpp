#include<bits/stdc++.h>
using namespace std;


class Rectangle
{
private:
    double length;
    double width;
public:
    Rectangle(double len =1,double wid=1): length(len),width(wid)
    {

    }

    double area()
    {
        return length*width;
    }

    double perimeter()
    {
        return 2*(length+width);
    }

    void set()
    {
        double length_in,width_in;
        cout << "Length: ";
        cin >> length_in;
        cout << "Width: ";
        cin >> width_in;
        if (length_in >= 1.0 and length_in <= 20.0 and width_in >= 1.0 and width_in <= 20.0)
        {
            length=length_in;
            width=width_in;

        }
        else
        {
            cout << "Error!!Parameters are out of bound!"<<endl;
        }
    }
    void get()
    {
        cout << "Length: " << length << endl;
        cout << "Width: " << width << endl;
        cout << "Area: " << area() << endl;
        cout << "Perimeter: " << perimeter() << endl;
    }
};
int main()
{
    Rectangle rec;
    rec.get();
    rec.set();
    rec.get();

}
