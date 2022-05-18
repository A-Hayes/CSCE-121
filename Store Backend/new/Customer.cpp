#include "Customer.h"
#include <sstream>
#include <iomanip>
#include <stdexcept> 
using namespace std;

Customer::Customer(int id, string name, bool credit){
	if(name == ""){
		throw runtime_error("Invalid name.");
	}
	if(id < 0){
		throw runtime_error("ID must be positive.");
	}
	this->id = id;
	this->name = name;
	this->credit = credit;
	balance = 0.0;
	productsPurchased = vector<Product>();
} 

int Customer::getID() const{
	return id;
}

std::string Customer::getName() const{
	return name;
}

void Customer::setName(std::string name){
	if(name == ""){
		throw runtime_error("Invalid name.");
	}
	this->name = name;
}

bool Customer::getCredit() const{
	return credit;
}

void Customer::setCredit(bool credit){
	this->credit = credit;
}

double Customer::getBalance() const{
	return balance;
}

void Customer::processPayment(double amount){
	if(amount < 0){
		throw runtime_error("Payment must be positive");
	}
	
	balance += amount;
}

void Customer::processPurchase(double amount, Product product){
	if(amount < 0){
		throw runtime_error("No credit, amount must be positive.");
	}
	
	if(credit){
		balance -= amount;
		
		for (int i = 0; i < productsPurchased.size(); i++){
			if(productsPurchased[i].getName() == product.getName()){    
				return;
			}
		}
		productsPurchased.push_back(product);
		
	}else{
		if(balance - amount < 0){
			throw runtime_error("No credit, balance must be positive.");
		}
		balance -= amount;
		
		for (int i = 0; i < productsPurchased.size(); i++){
			if(productsPurchased[i].getName() == product.getName()){    
				return;
			}
		}
		productsPurchased.push_back(product);
	}
}

std::string Customer::getProductsPurchased() const{
	stringstream outString;
	for(int i = 0; i < productsPurchased.size(); i++){
		outString << productsPurchased[i];
	}
	return outString.str();
}

std::ostream& operator<<(std::ostream& os, const Customer& c){
	os << "Customer Name: " << c.getName() << endl << "Customer ID: " << c.getID() << endl << "Has Credit: " << std::boolalpha << c.getCredit() << endl << "Balance: $" << c.getBalance() << endl << "Products purchased --"  << endl << endl << c.getProductsPurchased() << endl << endl;
	return os;
}