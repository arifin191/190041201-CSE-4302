#include<bits/stdc++.h>
using namespace std;
#define pi acos(-1.0)

//2 dim: circle, rectangle,triangle,,square,
//3 dim: sphere, cuboid,cylinder,cube

class Shape
{

protected: ///protected so that the derived classes can access base class members
    string shapeName;
    int dimension;

public:

    Shape() ///Constructor
    {
        shapeName="Circle";
        dimension=2;
    }

    void setData() ///To set the information about shape
    {
        string inputShape;
        cout<<"Enter the name of the shape: ";
        cin>>inputShape;
        shapeName=inputShape;

        int inputDim;
        cout<<"Enter the dimension of the shape: ";
        cin>>inputDim;
    }

    void whoAmI() ///To show shape data;
    {
        cout<<"I am "<<shapeName<<endl;
        string tempShape;
        dimension ==2 ? tempShape="two-dimensional" : tempShape="three-dimensional";
        cout<<"I am a "<<tempShape<<" shape"<<endl;
    }

    ~Shape() {}
};


class TwoDimensionalShape: public Shape ///derived from shape
{
protected:
    double area, perimeter;
public:
    TwoDimensionalShape()
    {
        area=0.0;
        perimeter=0.0;
        dimension=2;
    }
    TwoDimensionalShape(double a,double p): area(a),perimeter(p)
    {
        dimension=2;
    }

    void setData()
    {
        string inputShape;
        cout<<"Enter the name of the shape: ";
        cin>>inputShape;
        shapeName=inputShape;
        //dimension=2;
        double a, p;
        cout<<"Enter the area: ";
        cin>>a;
        cout<<"Enter the perimeter: ";
        cin>>p;
        area=a;
        perimeter=p;
    }


    void display()
    {
        cout<<"Area: "<<area<<endl;
        cout<<"Perimeter: "<<perimeter<<endl;
    }

    double getArea()
    {
        return area;
    }
    double getPerimeter()
    {
        return perimeter;
    }


};

class ThreeDimensionalShape: public Shape
{
protected:
    double surfaceArea, volume;
public:
    ThreeDimensionalShape()
    {
        surfaceArea=0.0;
        volume=0.0;
        dimension=3;
    }
    ThreeDimensionalShape(double s,double v): surfaceArea(s),volume(v)
    {
        dimension=3;
    }
    void setData()
    {
        string inputShape;
        cout<<"Enter the name of the shape: ";
        cin>>inputShape;
        shapeName=inputShape;
        double s, v;
        cout<<"Enter the surface area: ";
        cin>>s;
        cout<<"Enter the volume: ";
        cin>>v;
        surfaceArea=s;
        volume=v;
    }


    void display()
    {
        cout<<"Surface Area: "<<surfaceArea<<endl;
        cout<<"Volume: "<<volume<<endl;
    }

    double getSurfaceArea()
    {
        return surfaceArea;
    }
    double getVolume()
    {
        return volume;
    }

};

/// 2D shapes goes here
class Rectangle: public TwoDimensionalShape
{
protected:
    double height,width;

public:
    Rectangle()
    {
        shapeName="Rectangle";
        height=0;
        width=0;
    }
    Rectangle(double h,double w)
    {
        shapeName="Rectangle";
        height=h;
        width=w;
        area=h*w;
        perimeter=2*(h+w);
    }
    void setData()
    {
        double h, w;
        cout<<"Enter the height of the rectangle: ";
        cin>>h;
        cout<<"Enter the width of the rectangle: ";
        cin>>w;
        height=h;
        width=w;
        area=h*w;
        perimeter=2*(h+w);
    }

};

class Triangle: public TwoDimensionalShape
{
protected:
    double a,b,c;

public:
    Triangle()
    {
        shapeName="Triangle";
        a=0;
        b=0;
        c=0;
    }
    Triangle(double h,double w,double l)
    {
        shapeName="Triangle";
        a=h;
        b=w;
        c=l;
        double s=(a+b+c)/2.0;
        area = sqrt(s*(s-a)*(s-b)*(s-c));
        perimeter=2*s;
    }
    void setData()
    {
        double a1,b1,c1;
        cout<<"Enter the length of the first side of the Triangle: ";
        cin>>a1;
        cout<<"Enter the length of the second side of the Triangle: ";
        cin>>b1;
        cout<<"Enter the length of the third side of the Triangle: ";
        cin>>c1;
        a=a1;
        b=b1;
        c=c1;
        double s=(a+b+c)/2.0;
        area = sqrt(s*(s-a)*(s-b)*(s-c));
        perimeter=2*s;
    }

};

class Square: public TwoDimensionalShape
{
protected:
    double length;

public:
    Square()
    {
        shapeName="Square";
        length=0;
    }
    Square(double l)
    {
        shapeName="Square";
        length=l;
        area=l*l;
        perimeter=2*(l+l);
    }
    void setData()
    {
        double l;
        cout<<"Enter the length of the Square: ";
        cin>>l;
        length=l;
        area=l*l;
        perimeter=2*(l+l);
    }

};

class Circle: public TwoDimensionalShape
{
protected:
    double radius;
public:
    Circle()
    {
        shapeName="Circle";
        radius=0;

    }
    Circle(double r)
    {
        shapeName="Circle";
        radius=r;
        area=pi*r*r;
        perimeter=2*pi*r;
    }
    void setData()
    {
        double r;
        cout<<"Enter the radius of the Circle: ";
        cin>>r;
        radius=r;
        area=pi*r*r;
        perimeter=2*pi*r;
    }
};


/// 3D shapes goes here
class Cube: public ThreeDimensionalShape
{
protected:
    int length;
    //string shapeName="Cube";
public:
    Cube()
    {
        shapeName="Cube";
        length=0;
    }
    Cube(double l)
    {
        shapeName="Cube";
        length=l;
        volume=l*l*l;
        surfaceArea=6*l*l;
    }
    void setData()
    {
        double l;
        cout<<"Enter the length of the cube: ";
        cin>>l;
        length=l;
        volume=l*l*l;
        surfaceArea=6*l*l;
    }
};

class Sphere: public ThreeDimensionalShape
{
protected:
    double radius;
public:
    Sphere()
    {
        shapeName="Sphere";
        radius=0;

    }
    Cylinder(double r)
    {
        shapeName="Sphere";
        radius=r;
        volume=(4/3.0)*pi*r*r*r;
        surfaceArea=4*pi*r*r;
    }
    void setData()
    {
        double r;
        cout<<"Enter the radius of the sphere: ";
        cin>>r;
        radius=r;
        volume=(4/3.0)*pi*r*r*r;
        surfaceArea=4*pi*r*r;
    }
};


class Cylinder: public ThreeDimensionalShape
{
protected:
    double radius,height;
public:
    Cylinder()
    {
        shapeName="Cylinder";
        radius=0;
        height=0;
    }
    Cylinder(double r,double h)
    {
        shapeName="Cylinder";
        radius=r;
        height=h;
        volume=pi*r*r*h;
        surfaceArea=2*pi*r*(r+h);
    }
    void setData()
    {
        double r,h;
        cout<<"Enter the height of the cylinder: ";
        cin>>h;
        cout<<"Enter the radius of the cylinder: ";
        cin>>r;
        radius=r;
        height=h;
        volume=pi*r*r*h;
        surfaceArea=2*pi*r*(r+h);
    }
};

class Cuboid: public ThreeDimensionalShape
{
protected:
    double height,width,length;

public:
    Cuboid()
    {
        shapeName="Cuboid";
        height=0;
        width=0;
        length=0;
    }
    Cuboid(double h,double w,double l)
    {
        shapeName="Cuboid";
        height=h;
        width=w;
        length=l;
        volume=h*w*l;
        surfaceArea=2*(h*w+w*l+l*h);
    }
    void setData()
    {
        double h, w, l;
        cout<<"Enter the length of the cuboid: ";
        cin>>l;
        cout<<"Enter the height of the cuboid: ";
        cin>>h;
        cout<<"Enter the width of the cuboid: ";
        cin>>w;
        height=h;
        width=w;
        length=l;
        volume=h*w*l;
        surfaceArea=2*(h*w+w*l+l*h);
    }
};

int main()
{

    cout<<fixed<<setprecision(3);
    Shape circle; ///using base class Shape
    circle.setData();
    circle.whoAmI();

    TwoDimensionalShape shape2D; ///using derived class of Shape for 2D
    shape2D.setData();
    shape2D.whoAmI();
    shape2D.display();

    ThreeDimensionalShape shape3D;///using derived class of Shape for 3D
    shape3D.setData();
    shape3D.whoAmI();
    shape3D.display();

    Cube cb; ///Example of 3D derived class
    cb.whoAmI();
    cb.setData();
    cb.display();

    Cuboid cbd;
    cbd.whoAmI();
    cbd.setData();
    cbd.display();

    Cylinder cld;
    cld.whoAmI();
    cld.setData();
    cld.display();

    Sphere sp;
    sp.whoAmI();
    sp.setData();
    sp.display();

    Rectangle rect; ///Example of 2D derived class
    rect.whoAmI();
    rect.setData();
    rect.display();

    Square sqr;
    sqr.whoAmI();
    sqr.setData();
    sqr.display();

    Circle cir;
    cir.whoAmI();
    cir.setData();
    cir.display();

    Triangle tri;
    tri.whoAmI();
    tri.setData();
    tri.display();

    return 0;
}
