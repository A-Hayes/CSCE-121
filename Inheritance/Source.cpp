#include <iostream>
#include "Account.h"
#include "SavingsAccount.h"
using namespace std;

/*
    Test creating and using our objects of
    our defined class types
*/

int main()
{

    Account a1;
    Account a2(100.0);

    cout << "Account a1 has balance: " << a1.getBalance() << endl;
    cout << "Account a2 has balance: " << a2.getBalance() << endl << endl;

    // FIXME: Uncomment below after finishing SavingsAccount.h and SavingsAccount.cpp
    
    SavingsAccount s1;
    SavingsAccount s2(300.0, 0.005);

    cout << "Savings account s1 has balance: " << s1.getBalance() << endl;
    cout << "Savings account s1 has an interest rate of " << s1.getInterestRate() << endl;
    cout << "Savings account s2 has balance: " << s2.getBalance() << endl;
    cout << "Savings account s2 has an interest rate of " << s2.getInterestRate() << endl << endl;

    
    // system("pause");  // uncomment for VS

}

/*
1. No. For inheritance, a private field is only able to be used by immediate member functions and not any child classes. If we wanted to make it available to the child class, we would have to change it to a protected variable, which would change the implementation. You might be able to use getBalance, but I'm not fully clear as to whether that would be changing the inplementation.

	?? acct.getBalance(); ??

2. If we are able tp change the implementation of balance, changing it to a protected access type would allow SavingsAccount to natively use it.
	Change:
		private:
			double balance;
			
	To:
		protected:
			double balance;
			
*/