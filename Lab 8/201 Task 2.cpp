#include<bits/stdc++.h>
using namespace std;

class Seat
{

protected:
    string comfortability;
    bool seatWarmer;

public:
    Seat()
    {
        comfortability="unavailable";
        seatWarmer=false;
    }
    Seat(string com, bool warm)
    {
        comfortability=com;
        seatWarmer=warm;
    }
    void setSeatData()
    {
        string com;
        cout<<"Enter seat comfortability: ";
        cin>>com;
        comfortability=com;
        char check;
        cout<<"Enter presence of seat warmer: (y/n)";
        cin>>check;
        check=='y'? seatWarmer=true: seatWarmer=false;
    }
    void getSeatData()
    {
        if(comfortability=="unavailable")
        {
            cout<<"The seat comfortability information is not available"<<endl;
        }
        else cout<<"The seats are "<<comfortability<<endl;

        if(seatWarmer)
        {
            cout<<"It has seat warmer\n";
        }
        else
        {
            cout<<"The seat warmer information is not available"<<endl;
        }
    }
};

class Wheel
{
protected:
    double circumference;

public:
    Wheel()
    {
        circumference=0.0;
    }
    Wheel(double circ)
    {
        circumference=circ;
    }
    void setWheelData()
    {
        double circ;
        cout<<"Enter circumference of wheel: ";
        cin>>circ;
        circumference=circ;
    }
    void getWheelData()
    {
        cout<<"The circumference of the wheel is: "<<circumference<<endl;
    }
};

class Engine
{
protected:
    double MaxFuelConsumption,MaxEnergyProduction, avgRPM;

public:
    Engine()
    {
        MaxFuelConsumption=0;
        MaxEnergyProduction=0;
        avgRPM=0;
    }
    Engine(double FC,double EP,double RPM)
    {
        MaxFuelConsumption=FC;
        MaxEnergyProduction=EP;
        avgRPM=RPM;
    }

    void setEngineData()
    {
        double FC,EP,RPM;
        cout<<"Enter Maximum Fuel Consumption Rate: ";
        cin>>FC;
        cout<<"Enter Maximum Energy Production Rate: ";
        cin>>EP;
        cout<<"Enter Average RPM: ";
        cin>>RPM;
        MaxFuelConsumption=FC;
        MaxEnergyProduction=EP;
        avgRPM=RPM;
    }

    void getEngineData()
    {
        cout<<"Maximum Fuel Consumption Rate: "<<MaxFuelConsumption<<endl;
        cout<<"Maximum Energy Production Rate: "<<MaxEnergyProduction<<endl;
        cout<<"Average RPM: "<<avgRPM<<endl;
    }
};


class Door
{
protected:
    string openingMode;
public:
    Door()
    {
        openingMode="unavailable";
    }
    Door(string open)
    {
        openingMode=open;
    }
    void setDoorData()
    {
        string open;
        cout<<"Enter door opening mode: ";
        cin>>open;
        openingMode=open;
    }
    void getDoorData()
    {
        if(openingMode!="unavailable")
        {
            cout<<"Car opening mode : "<<openingMode<<endl;
        }
        else
        {
            cout<<"Door Information Unavailable\n";
        }
    }
};

class Car: public Seat, public Wheel, public Engine, public Door
{
protected:
    double maximum_acceleration, fuel_capacity;

public:
    Car(double acc, double fuel): maximum_acceleration(acc),fuel_capacity(fuel)
    {

    }
    Car()
    {
        maximum_acceleration=0;
        fuel_capacity=0;
    }
    void setCarData()
    {
        double acc,fuel;
        cout<<"Enter Maximum Acceleration: ";
            cin >> acc ;
        cout<<"Enter Fuel Capacity: ";
            cin>>fuel;
        maximum_acceleration=acc;
        fuel_capacity=fuel;
    }

    void getCarData()
    {
        cout<<"Maximum Acceleration: "<<maximum_acceleration<<endl;
        cout<<"Fuel Capacity: "<<fuel_capacity<<endl;
    }

    void setData()
    {
        setSeatData();
        setWheelData();
        setEngineData();
        setDoorData();
        setCarData();
    }
    void getData()
    {
        getSeatData();
        getWheelData();
        getEngineData();
        getDoorData();
        getCarData();
    }

};


int main()
{
    Car c;
    c.setData();
    c.getData();
    return 0;
}
