#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <vector>
#include <string>
#include <iostream>
#include "Product.h"

class Customer{
		int id;
		std::string name;
		bool credit;		//credit denotes if they are able to make a purchase with insufficient funds in balance
		double balance;
		std::vector<Product> productsPurchased;
 
 public:
		Customer(int, string, bool);  //initialize Customer with ID, name, and if customer uses credit
		int getID() const;
		std::string getName() const;
		void setName(std::string);
		bool getCredit() const;
		void setCredit(bool);
		double getBalance() const;
		void processPayment(double);
		void processPurchase(double, Product);
 		std::string getProductsPurchased() const;
	
};

std::ostream& operator<<(std::ostream& os, const Customer& c);

#endif