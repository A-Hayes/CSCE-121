#include <string>
#include <stdexcept>
#include <iomanip>
#include <iostream>
#include <stdexcept> 
#include "Product.h"

using namespace std;

Product::Product(int id, string name) {
	if(name == ""){
		throw runtime_error("Invalid name.");
	}
	
	this->name = name;
	this->id = id;
	inventory = 0;
	totalPaid = 0.0;
	description = "";
	numSold = 0;
}

int Product::getID() const{
	return id;
}

string Product::getName()  const{
	return name;
}

string Product::setName(string name) {
	if(name == ""){
		throw runtime_error("Invalid name.");
	}
	this->name = name;
    return "";
}

string Product::getDescription() const{
	return description; 
	// have to return something in stub so it will compile
	// will change later
}

void Product::setDescription(string description){
	this->description = description;
}

int Product::getNumberSold() const{
	return numSold;
	// have to return something in stub so it will compile
	// will change later
}

double Product::getTotalPaid() const{
	return totalPaid;
	// have to return something in stub so it will compile
	// will change later
}

int Product::getInventoryCount() const{
	return inventory;
	// have to return something in stub so it will compile
	// will change later
}

double Product::getPrice() const{
	return (totalPaid / (double)(inventory + numSold)) * 1.25;
	// have to return something in stub so it will compile
	// will change later
}

void Product::addShipment(int quantity, double amount) {
	if(quantity < 0){
		throw runtime_error("Quantity must be positive.");
	}
	if(amount < 0){
		throw runtime_error("Payment must be positive");
	}
	
	inventory += quantity;
	totalPaid += amount;
}

void Product::reduceInventory(int purchaseQuantity) {
	if(inventory - purchaseQuantity < 0){
		throw runtime_error("Inventory cannot be negative.");
	}
	if(purchaseQuantity < 0){
		throw runtime_error("Quantity cannot be negative.");
	}
	inventory -= purchaseQuantity;
	numSold += purchaseQuantity;
}

std::ostream& operator<<(std::ostream& os, const Product& p){		
	os << "Product Name: " << p.getName() << endl << "Product ID: " << p.getID() << endl << "Description: " << p.getDescription() << endl << "Inventory: " << p.getInventoryCount() << endl << "Total Paid: " << fixed << setprecision(2) << p.getTotalPaid() << endl << endl;
	return os;
}