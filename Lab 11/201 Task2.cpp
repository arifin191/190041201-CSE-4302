#include<bits/stdc++.h>
#include<fstream>
using namespace std;

class Shape
{
private:
    int area;
    string name;
    static int n;
    static Shape* arrap[];


public:
    virtual void setData()
    {
        cout << " Enter Shape Name: ";
        cin >> name ;
        cout << " Enter Shape Area: ";
        cin >> area;

    }
    virtual void getData()
    {
        cout<<"I am "<<name<<" and my area is: "<<area<<endl;
    }
    virtual string type()
    {
        return name;
    }
    static void add();
    static void display();
    static void read();
    static void write();
};

int Shape::n; //current number of employees
Shape* Shape::arrap[100];


class Circle: public Shape
{
private:
    double radius;
public:
    void setData()
    {
        Shape::setData();
        cout << " Enter radius: ";
        cin >> radius;
    }
    void getData()
    {
        Shape::getData();
        cout << "\n Radius: " << radius;
    }
};

class Square: public Shape
{
private:
    int length;
public:
    void setData()
    {
        Shape::setData();
        cout << " Enter Length: ";
        cin >> length;
    }
    void getData()
    {
        Shape::getData();
        cout << "\n Length: " << length;
    }
};

void Shape::add()
{
    char ch;
    cout << "'c' to add a circle"
         "\n's' to add a square"
         "\nEnter selection: ";
    cin >> ch;
    if(ch=='c')
    {
        arrap[n] = new Circle;
    }
    else if(ch=='s')
    {
        arrap[n] = new Square;
    }
    else
    {
        cout << "\nUnknown shape type\n";
        return;
    }
    arrap[n++]->setData();
}

void Shape::display()
{
    for(int j=0; j<n; j++)
    {
        cout << (j+1);

        arrap[j]->getData();
        cout << endl;
    }
}

void Shape::write()
{
    int size;
    cout << "Writing " << n << " Shapes.\n";
    ofstream ouf;
    ouf.open("Shapes.DAT", ios::trunc | ios::binary);
    if(!ouf)
    {
        cout << "\nCan't open file\n";
        return;
    }
    for(int j=0; j<n; j++)
    {
        string temp= arrap[j]->type();

        if(temp=="Circle")
            size=sizeof(Circle);

        else if (temp=="Square")
            size=sizeof(Square);

    ouf.write( (char*)(arrap[j]), size );
    if(!ouf)
    {
        cout << "\nCan't write to file\n";
        return;
    }

    }

}


void Shape::read()
{
    int size;
    ifstream inf; //open ifstream in binary
    inf.open("EMPLOY.DAT", ios::binary);
    if(!inf)
    {
        cout << "\nCan't open file\n";
        return;
    }
    n = 0;
    while(true)
    {
        if( inf.eof() )
            break;
        if(!inf) //error reading type
        {
            cout << "\nCan't read type from file\n";
            return;
        }
        string temp= arrap[n]->type();
            if(temp=="Circle")
            {
                arrap[n]=new Circle;
                size=sizeof(Circle);
            }
            else if (temp=="Square")
            {
                arrap[n]=new Square;
                size=sizeof(Square);
            }
            else
            {
                cout << "\nUnknown type in file\n";
                return;
            }



    inf.read( (char*)arrap[n], size );
    if(!inf) //error but not eof
    {
        cout << "\nCan't read data from file\n";
        return;
    }
    n++;
}
cout << "Reading " << n << " Shapes\n";
}



int main()
{
    char ch;
    while(true)
    {
        cout << "'a' -- add data "
             "\n'd' -- display data"
             "\n'w' -- write all data to file"
             "\n'r' -- read all  data from file"
             "\n'x' -- exit"
             "\nEnter selection: ";
        cin >> ch;
        if(ch=='a')
        {
            Shape::add();
        }
        else if(ch=='d')
        {
            Shape::display();
        }else if(ch=='r')
        {
            Shape::read();
        }else if(ch=='w')
        {
            Shape::write();
        }
        else if(ch=='x')
        {
            exit(0);
        }
        else{
            cout<<"Unknown Command"<<endl;
        }

    }
    return 0;
}
