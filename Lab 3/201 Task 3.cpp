#include <iostream>
using namespace std;

class BankAccount
{
	private:
  		string name;
  		int account_number;
  		string account_type;
  		int acc_balance ;

	public:
	    BankAccount():acc_balance(0)
        {

        }
  		void customerDetails(string cus_name, int cus_account_number)
  		{
    		name = cus_name;
    		account_number = cus_account_number;
  		}

  		void accountType(string cus_account_type)
  		{
    		account_type = cus_account_type;
  		}

  		void balance()
  		{
    		cout << "Balance: " << acc_balance << endl;
  		}

  		void deposit(int dep)
  		{
    		acc_balance += dep;
  		}

  		void withdraw(int withdraw)
  		{
    		acc_balance -= withdraw;
  		}

  		void display()
  		{
    		cout << "Name: " <<name << endl;
    		cout << "Account Number: " << account_number << endl;
    		balance();
    		cout << "Type: " << account_type << endl;
  		}
};

int main()
{
	BankAccount account;

	string name,acc_type;
	int acc_num, amount;
	cout<<"Enter customer name:";
	cin >> name;
	cout<<"Enter account Number:" ;
	cin >> acc_num;
	cout<<"Enter account type:" ;
	cin >> acc_type;

	account.customerDetails(name, acc_num);
	account.accountType(acc_type);

	cout << "Initially: " << endl;
	account.display();
	cout<<"Enter deposit amount:" ;
	cin >> amount;

	account.deposit(amount);

	cout << "After depositing : " << endl;
	account.display();
	cout<<"Enter withdraw amount: " ;
	cin >> amount;

	account.withdraw(amount);

	cout << "After withdrawal : " << endl;
	account.display();

	return 0;
}
