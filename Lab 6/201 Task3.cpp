#include<bits/stdc++.h>
using namespace std;

class Coordinate
{
private:
    float abscissa, ordinate;

public:
    Coordinate():abscissa(0.0),ordinate(0.0)
    {

    }
    Coordinate(float a, float o):abscissa(a),ordinate(o)
    {

    }
    void display()
    {
        cout<<"Abscissa: "<<abscissa<<endl;
        cout<<"Ordinate: "<<ordinate<<endl;
    }
    float getDistance()
    {
        return sqrt(abscissa*abscissa+ordinate*ordinate);
    }
    float getDistance(Coordinate c)
    {
        float a=abs(abscissa-c.abscissa);
        float b=abs(ordinate-c.ordinate);
        return sqrt(a*a+b*b);
    }
    void move_x(float val)
    {
        abscissa+=val;
    }
    void move_y(float val)
    {
        ordinate+=val;
    }
    void move(float val)
    {
        move_x(val);
        move_y(val);
    }
    Coordinate operator++ ()
    {
        abscissa++;
        ordinate++;
        return Coordinate(abscissa,ordinate);
    }
    Coordinate operator--(int)
    {
        abscissa--;
        ordinate--;
        return Coordinate(abscissa,ordinate);
    }
    Coordinate operator-- ()
    {
        abscissa--;
        ordinate--;
        return Coordinate(abscissa,ordinate);
    }
    Coordinate operator++(int)
    {
        abscissa++;
        ordinate++;
        return Coordinate(abscissa,ordinate);
    }

    bool operator ==(Coordinate c)
    {
        float a= getDistance();
        float b= c.getDistance();
        return a==b;
    }

    bool operator !=(Coordinate c)
    {
        float a= getDistance();
        float b= c.getDistance();
        return a!=b;
    }

    bool operator >=(Coordinate c)
    {
        float a= getDistance();
        float b= c.getDistance();
        return a>=b;
    }

    bool operator <=(Coordinate c)
    {
        float a= getDistance();
        float b= c.getDistance();
        return a<=b;
    }

    bool operator <(Coordinate c)
    {
        float a= getDistance();
        float b= c.getDistance();
        return a<b;
    }

    bool operator >(Coordinate c)
    {
        float a= getDistance();
        float b= c.getDistance();
        return a>b;
    }

    ~Coordinate()
    {

    }
};

int main()
{
    Coordinate c;
    c.display();
    ++c;
    c.display();
    c--;
    c--;
    c.display();
    c.move(5);
    c.display();
    Coordinate c2(100,200);
    cout<< (c>c2);

}
