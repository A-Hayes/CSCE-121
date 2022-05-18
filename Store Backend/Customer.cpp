#include <algorithm>
#include <stdexcept>
#include <iomanip>
#include "Customer.h"
using namespace std;
	
//initialize Customer with ID, name, and if customer uses credit
//undetermined issues in unit testing, should construct/default properly
Customer::Customer(int id, string name, bool credit) : id(0), name(" "), credit(), balance(0.0){
 if (name == ""){
  throw runtime_error("Invalid name.");
 }
}

int Customer::getID() const{	//minor undetermined issues in unit testing
 return id;
}

string Customer::getName() const{
 return name;
}

void Customer::setName(string name){
 if (name == ""){
  throw runtime_error("Invalid name.");
 }
 this->name = name;
}

bool Customer::getCredit() const{
 return credit;
}

void Customer::setCredit(bool _credit){
 credit = _credit;
}

double Customer::getBalance() const{
 return balance;
}

std::string Customer::getProductsPurchased() const{
	for(int i = 0; i < productsPurchased.size(); i++){
    	cout << productsPurchased[i];
    }
}

void Customer::processPayment(double amount){		//undetermined issues in unit testing
 if(amount < 0){	
  throw runtime_error("Invalid amount.");
 }
 balance -= amount;
}

void Customer::processPurchase(double amount, Product product){		//undetermined issues in unit testing
 if(amount < 0){	
  throw runtime_error("Invalid amount.");
 }
 if (credit == false){
  if(product.getPrice() > balance){
   throw runtime_error("Customer does not have sufficient credit for this purchase."); 
  }
 }
 balance -= (amount * product.getPrice());

 //if not already on list, adds the given product to the user's list of purchased products
 for (int i = 0; i < productsPurchased.size(); i++){
  if(productsPurchased[i].getName() == product.getName()){    
   productsPurchased.push_back(product);
  }
 }
}	

std::ostream& operator<<(std::ostream& os, const Customer& c){		//undetermined issues in unit testing
	os << "Customer Name: " << c.getName() << endl << "Customer ID: " << c.getID() << endl << "Has Credit: " << c.getCredit() << endl << "Balance: $" << fixed << setprecision(2) << c.getBalance() << endl << "Products Purchased: "  << "--" << endl << endl;
	return os;
}