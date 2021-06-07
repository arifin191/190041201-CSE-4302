#include <iostream>
using namespace std;

class Counter
{
	private:
  		int count ;
  		int step;

	public:
	    Counter(): count(0),step(0)
	    {

	    }
  		void setIncrementStep(int step_val)
  		{
    		step = step_val;
  		}

  		int getCount()
  		{
    		return count;
  		}

  		void increment()
  		{
    		count += step;
  		}

  		void resetCount()
  		{
    		count = 0;
  		}
};

int main()
{
	Counter cnt;

	cout << "At the beginning : " << cnt.getCount() << endl;
	cout<<"Enter increment step:"<<endl;
	int step;
	cin>> step;
	cnt.setIncrementStep(step);
	cnt.increment();
	cout << "After Incrementing Once: " << cnt.getCount() << endl;
	cnt.increment();
	cout << "After Incrementing Twice: " << cnt.getCount() << endl;
	cnt.resetCount();
	cout<<"After resetting :"<<cnt.getCount() << endl;

	return 0;
}
