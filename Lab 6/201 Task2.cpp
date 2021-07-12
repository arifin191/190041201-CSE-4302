#include<iostream>
using namespace std;


class Matrix3D
{
private:
    double arr[3][3];

public:
    Matrix3D()
    {
        for (int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                arr[i][j]=0;
            }
        }
    }

    void display()
    {
        for (int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    ~Matrix3D()
    {

    }

    void setMatrix()
    {
        cout<<"Enter the values"<<endl;
        for (int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                cin>>arr[i][j];
            }
        }
    }

    Matrix3D operator + (Matrix3D m)
    {
        Matrix3D temp;

        for (int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                temp.arr[i][j]=arr[i][j]+m.arr[i][j];
            }
        }
        return temp;
    }
    Matrix3D operator - (Matrix3D m)
    {
        Matrix3D temp;

        for (int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                temp.arr[i][j]=arr[i][j]-m.arr[i][j];
            }
        }
        return temp;
    }

    Matrix3D operator * (Matrix3D m)
    {
        Matrix3D temp;
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                temp.arr[i][j]=0;
                for(int k=0; k<3; k++)
                {
                    temp.arr[i][j]+=arr[i][k]*m.arr[k][j];
                }
            }
        }
        return temp;
    }
    double det()
    {
        double a= arr[0][0]*(arr[1][1]*arr[2][2]-arr[1][2]*arr[2][1]);
        double b= arr[0][1]*(arr[1][2]*arr[2][0]-arr[1][0]*arr[2][2]);
        double c= arr[0][2]*(arr[1][0]*arr[2][1]-arr[2][0]*arr[1][1]);
        return a+b+c;
    }
    Matrix3D inverse()
    {
        if(det()==0)
        {
            cout<<"Inverse doesn't exist"<<endl;
            exit(1);
        }
        else{
            Matrix3D temp;
            temp.arr[0][0]= (arr[1][1]*arr[2][2]-arr[1][2]*arr[2][1])/det();
            temp.arr[0][1]= -(arr[0][1]*arr[2][2]-arr[0][2]*arr[2][1])/det();
            temp.arr[0][2]= (arr[0][1]*arr[1][2]-arr[0][2]*arr[1][1])/det();

            temp.arr[1][2]= -(arr[1][0]*arr[2][2]-arr[1][2]*arr[2][0])/det();
            temp.arr[1][1]= (arr[0][0]*arr[2][2]-arr[0][2]*arr[2][0])/det();
            temp.arr[1][2]= -(arr[0][0]*arr[1][2]-arr[0][2]*arr[1][0])/det();

            temp.arr[2][0]= (arr[1][0]*arr[2][1]-arr[1][1]*arr[2][0])/det();
            temp.arr[2][1]= -(arr[0][0]*arr[2][1]-arr[0][1]*arr[2][0])/det();
            temp.arr[2][2]= (arr[0][0]*arr[1][1]-arr[0][1]*arr[1][0])/det();
            return temp;
        }
    }
};


int main()
{
    Matrix3D mat;
    mat.display();
    Matrix3D m2,m3;
    m2.setMatrix();
    cout<<m2.det()<<endl;
    m3.setMatrix();
    cout<<"Addition"<<endl;
    mat=m2+m3;
    mat.display();
    cout<<"Subtraction"<<endl;
    mat=m2-m3;
    mat.display();
    cout<<"Multiplication"<<endl;
    mat=m2*m3;
    mat.display();
    Matrix3D inv = m2.inverse();
    inv.display();


}
