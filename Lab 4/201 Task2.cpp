#include<bits/stdc++.h>
using namespace std;

class Jet
{
private:
    int flightMember;
    string destination;
    double distance;
    double MaxFuelCapacity;
    int CalFuel()
    {
        if(distance<=1000)
        {
            return 500;
        }
        else if(distance<=2000)
        {
            return 1100;
        }

        return 2200;
    }

public:
    void FeedInfo()
    {
        int flightMember_in;
        string destination_in;
        double distance_in;
        double MaxFuelCapacity_in;

        cout<<"ENTER NUMBER OF FLIGHT MEMBER: ";
        cin>>flightMember_in;
        cout<<"ENTER DESTINATION: ";
        cin>>destination_in;
        cout<<"ENTER DISTANCE: ";
        cin>>distance_in;
        cout<<"ENTER MAXIMUM FUEL CAPACITY: ";
        cin>>MaxFuelCapacity_in;

        flightMember=flightMember_in;
        destination=destination_in;
        distance=distance_in;
        MaxFuelCapacity=MaxFuelCapacity_in;
    }

    void ShowInfo()
    {
        cout<< flightMember <<endl;
        cout<< destination <<endl;
        cout<< distance <<endl;
        cout<< MaxFuelCapacity <<endl;
        if(MaxFuelCapacity>=CalFuel())
        {
            cout<<"Fuel Capacity is fit for this flight"<<endl;
        }
        else cout<<"Not sufficient Fuel Capacity for this flight"<<endl;
    }
};

int main()
{

    Jet plane1;
    plane1.FeedInfo();
    plane1.ShowInfo();
    return 0;
}
