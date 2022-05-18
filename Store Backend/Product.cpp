#include "Product.h"
#include <stdexcept>
#include <sstream>
#include <iomanip>
using namespace std;

Product::Product(int id, string name) : id(id), name(name),
	inventory(0), numSold(0), totalPaid(0.0){
	if (name.length()==0) {
		throw runtime_error("Product name cannot be empty.");
	}
}

int Product::getID() const{
	return id;
}

std::string Product::getName() const{
	return name;
}

std::string Product::setName(string name){
	if (name == ""){
		throw runtime_error("Invalid name.");
	} 
	this->name = name;
 	return "";
}

string Product::getDescription() const{
	return description;
}

void Product::setDescription(string newDecription){
	description = newDecription;
}

int Product::getNumberSold() const{
	return numSold;
}

double Product::getTotalPaid() const{
	return totalPaid;
}

int Product::getInventoryCount() const{
	return inventory;
}

double Product::getPrice() const{
	return (totalPaid / (static_cast<double>(inventory) + static_cast<double>(numSold))) * 1.25;
	//converted to only show dollars and cents during output
}

void Product::addShipment(int quantity, double shipmentCost){
	if (quantity < 0)
		throw runtime_error("Shipment quantity must be positive.");
	if (shipmentCost < 0)
		throw runtime_error("Shipment cost must be positive.");
	inventory += quantity; 
	totalPaid += shipmentCost;
}

void Product::reduceInventory(int quantity){
	if (quantity > inventory || quantity < 0){	
		throw runtime_error("Invalid quantity.");
	}
	inventory -= quantity;
	numSold += quantity;
}

std::ostream& operator<<(std::ostream& os, const Product& p){		//minor undetermined issues in unit testing
	os << "Product Name: " << p.getName() << endl << "Product ID: " << p.getID() << endl << "Description: " << p.getDescription() << endl << "Inventory: " << p.getInventoryCount() << endl << "Total Paid: " << fixed << setprecision(2) << p.getTotalPaid() << endl << endl;
	return os;
}