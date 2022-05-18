/*
    This file should contain the member function
    implementations for the SavingsAccount class
*/

#include "SavingsAccount.h"

// FIXME: add definition for getInterestRate()
double SavingsAccount::getInterestRate(){
	return interest_rate;
}

// FIXME: add definition for setInterestRate(double newinterestrate)
void SavingsAccount::setInterestRate(double interest_rate){
	this->interest_rate = interest_rate;
}