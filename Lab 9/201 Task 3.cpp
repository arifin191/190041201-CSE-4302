#include<bits/stdc++.h>
using namespace std;

class Furniture
{
protected:
    int regularPrice, discountedPrice;
    string productName, material;

public:
    Furniture(int reg = 0, int dis = 0,string pro = "", string mat = "") : regularPrice(reg), discountedPrice(dis), productName(pro), material(mat)
    {

    }

    void setFurnitureData()
    {
        cout << "Enter Regular Price :";
        cin >> regularPrice;
        cout << "Enter Discounted Price :";
        cin >> discountedPrice;
        cout << "Enter Product Name :";
        cin >> productName;
        cout << "Enter Material :";
        cin >> material;
    }

    void getFurnitureData()
    {
        cout << "Regular Price :" << regularPrice << endl;
        cout << "Discounted Price :" << discountedPrice << endl;
        cout << "Product Name :" << productName << endl;
        cout << "Material :" << material << endl;
    }
};

class Bed : public Furniture
{
private:
    string bedSize;
public:
    Bed(string size = "") : bedSize(size)
    {

    }

    void setBedData()
    {
        setFurnitureData();
        cout << "Enter Bed Size: ";
        cin >> bedSize;
    }

    void productDetails()
    {
        for(int i=0; i<40; i++) cout<<"-";
        cout<<endl;
        getFurnitureData();
        cout << "Bed Size :" << bedSize << endl;
        for(int i=0; i<40; i++) cout<<"#";
        cout<<endl;
    }
};

class Sofa : public Furniture
{
private:
    int seatNumber;
public:
    Sofa(int sn = 0) : seatNumber(sn) {}

    void setSofaData()
    {
        setFurnitureData();
        cout << "Enter Seat Number: ";
        cin >> seatNumber;
    }

    void productDetails()
    {
        for(int i=0; i<40; i++) cout<<"-";
        cout<<endl;
        getFurnitureData();
        cout << "Seat Number :" << seatNumber << endl;
        for(int i=0; i<40; i++) cout<<"#";
        cout<<endl;
    }
};

class DiningTable : public Furniture
{
private:
    int chairCount;
public:
    DiningTable(int cc = 0) : chairCount(cc) {}

    void setDiningTableData()
    {
        setFurnitureData();
        cout << "Chair Count: ";
        cin >> chairCount;
    }

    void productDetails()
    {
        for(int i=0; i<40; i++) cout<<"-";
        cout<<endl;
        getFurnitureData();
        cout << "Chair Count: " << chairCount << endl;
        for(int i=0; i<40; i++) cout<<"#";
        cout<<endl;
    }
};

int main()
{
    Bed b;
    b.setBedData();
    b.productDetails();

    Sofa s;
    s.setSofaData();
    s.productDetails();

    DiningTable d;
    d.setDiningTableData();
    d.productDetails();

    return 0;
}
