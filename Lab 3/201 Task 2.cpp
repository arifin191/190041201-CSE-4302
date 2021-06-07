#include <iostream>
using namespace std;

class RationalNumber
{
	private:
  		int numerator;
  		int denominator;


	public:
  		void assign(int inp_numerator, int inp_denominator)
  		{
    		if (inp_denominator == 0)
    		{
      			cout << "Error!! Denominator can not be equal to zero." << endl;
      			return;
    		}

    		 numerator = inp_numerator;
    		 denominator = inp_denominator;
  		}

  		double convert()
  		{
    		double dec= (double) numerator /  denominator;
    		return dec;
  		}

 		void invert()
  		{
    		swap( numerator,  denominator);
  		}

  		void print()
  		{
			cout << "The Rational Number is " <<  numerator << "/" <<  denominator << endl;
  		}
};

int main()
{
	RationalNumber data;

	int numerator, denominator;
	cout<<"Enter the numerator:"<<endl;
	cin>>numerator;
	cout<<"Enter the denominator:"<<endl;
	cin>>denominator;

	data.assign(numerator, denominator);
	cout << "Before inversion : ";
	data.print();

	cout << "Converted value : " << data.convert() << endl;

	data.invert();
	cout << "After inversion : ";
	data.print();

	cout << "Converted value : " << data.convert() << endl;

	return 0;
}
