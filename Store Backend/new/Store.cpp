#include "Store.h"
#include <stdexcept>

using namespace std;

Store::Store(string name){
 	this->name = name;
	products = vector<Product>();
 	customers = vector<Customer>();
}

string Store::getName() const{
	return name;
}
void Store::setName(string name){
	this->name = name;
}

void Store::addProduct(int productID, string productName){
	for(int i = 0; i < products.size(); i++){
		if(products[i].getName() == productName){
			throw runtime_error("Preexisting product with same name.");
		}
	}
	
	Product newProduct(productID, productName);
	products.push_back(newProduct);
}

Product& Store::getProduct(int productID){
	for(int i = 0; i < products.size(); i++){
		if(products[i].getID() == productID){
			return products[i];
		}
	}
	throw runtime_error("Product not found.");
}

void Store::addCustomer(int customerID, string customerName, bool credit){
	for(int i = 0; i < customers.size(); i++){
		if(customers[i].getID() == customerID){
			throw runtime_error("Preexisting customer with same name.");
		}
	}
	
	Customer newCustomer(customerID, customerName, credit);
	customers.push_back(newCustomer);
}

Customer& Store::getCustomer(int customerID){
	for(int i = 0; i < customers.size(); i++){
		if(customers[i].getID() == customerID){
			return customers[i];
		}
	}
	throw runtime_error("Customer not found.");
}

void Store::takeShipment(int productID, int quantity, double cost){			// Issue with some cases, MAKE DRIVER
	for(int i = 0; i < products.size(); i++){
		if(products[i].getID() == productID){
			products[i].addShipment(quantity, cost);
		}
	}
	throw runtime_error("Product not found.");
}

void Store::sellProduct(int customerID, int productID, int quantity){		// Issue with some cases, MAKE DRIVER
	try{
		Customer& cust = getCustomer(customerID);
		Product& prod = getProduct(productID);
		double amount = quantity * prod.getPrice();
		cust.processPurchase(amount, prod);
	}catch(runtime_error &e){
		cout << "Invalid input" << endl;
	}
}
/*
Make the sale if it is allowed, otherwise throw an runtime_error or let an runtime_error propagate. In this context allowed means that the product's reduceInventory() and the customer's processPurchase() functions would not throw an runtime_error and the product and customer must exist. Warning: Do not change the product or customer if both cannot be done successfully.
*/

void Store::takePayment(int customerID, double amount){
	try{
		Customer &cust = this->getCustomer(customerID);
		cust.processPayment(amount);
	}catch(runtime_error &e){
		cout << e.what() << endl;
	}
}
/*
Find matching customer and process the payment. If the customer does not exist, you should throw an runtime_error or let an runtime_error propagate that is thrown when you call another function to get the customer.
*/

void Store::listProducts() const{
	cout << "Printing Products-----------" << endl;
 	for(int i = 0; i < products.size(); i++){
		cout << products[i] <<  endl;
	}
}
/*
Output information about each product. (Use overloaded output operator for Product.)
*/

void Store::listCustomers() const{
 	cout << "Printing Customer------------" << endl;
	for(int i = 0; i < customers.size(); i++){
		cout << customers[i] << endl;
	}
}
/*
Output information about each customer. (Use overloaded output operator for Customer.)
*/