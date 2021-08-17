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

    int discounted()
    {
        return discountedPrice;
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

void order(Furniture** f1, Furniture** f2)
{
    if ((*f1)->discounted() < (*f2)->discounted())
    {
        Furniture* temp = *f1;
        *f1 = *f2;
        *f2 = temp;
    }
}

void sort_furniture_price(Furniture** f, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            order(f + i, f + j);
        }
    }
}


int main()
{

    cout<<"Enter number of Furnitures:";
    int n;
    cin>>n;

    Furniture* f[n];
    for (int i = 0; i < n; ++i)
    {
        f[i] = new Furniture;
        f[i]->setFurnitureData();
        cout << "\n";
    }
    sort_furniture_price(f, n);

//    vector<Furniture* >v(n);
//    for(int i=0;i<n;i++)
//    {
//        v[i]->setFurnitureData();
//    }
//
//    std::sort(v.begin(),v.end(),[](const Furniture& lhs, const Furniture& rhs)
//    {
//        return lhs.discounted() < rhs.discounted();
//    });

    for(int i=0; i<n; i++)
    {
        f[i]->getFurnitureData();
    }

    return 0;
}
