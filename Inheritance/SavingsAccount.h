#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H
#include "Account.h"

/*  FIXME:
    Create a SavingsAccount class inherited from the Account class.

    Add the data member interest_rate
      type should be double
      set default value of 0.001 in constructor

    This file should contain the class definition and the
    declarations of its member functions.
*/

class SavingsAccount : public Account {
	double interest_rate;
	
	public:
		SavingsAccount(double interest_rate=0.001): Account(), 
		interest_rate(interest_rate){};
		
		SavingsAccount(double balance, double interest_rate): Account(balance),
	interest_rate(interest_rate) { };
		
		/* SavingsAccount(): Account(balance), 
		interest_rate(interest_rate) { } */

		double getInterestRate();
		void setInterestRate(double interest_rate);
};

/* //FIXME 1: add class definition for SavingsAccount
class SavingsAccount : public Account {
// FIXME 1A: add data member interest_rate
	double interest_rate;
// FIXME 1B: add default construtor
	public:
		SavingsAccount(double interest_rate=0.001): Account(), interest_rate(interest_rate) { }
// FIXME 1C: add parameterized construtor
		SavingsAccount(double balance = 0, double interest_rate = 0.001): Account(), interest_rate(interest_rate), balance(balance) { }
// FIXME 1D: add getter declaraton for interest_rate
		double getInterestRate();
// FIXME 1E: add setter declaraton for interest_rate
		double setInterestRate(double interest_rate);
}; */
#endif