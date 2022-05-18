#include "Product.h"
#include "Customer.h"
#include <iostream>
#include <stdexcept> 
#include <iostream>

#include <stdexcept>
using namespace std;

void test_customer(){
	Customer c = Customer(1, "Tom", false);
	
	cout << c.getID() << endl;
	cout << c.getName() << endl;
	cout << c.getCredit() << endl;
	cout << c.getBalance() << endl;
	cout << c.getProductsPurchased() << endl;
	
	c.setName("George");
	cout << c.getName() << endl;
	c.setCredit(true);
	cout << c.getCredit() << endl;
	
	try{
	c.setName("");
	cout << c.getName() << endl;
	}catch(exception &e){
		cout << e.what() << endl;
	}
	
	try{
	c.processPayment(28.75);
	cout << c.getBalance() << endl;
	c.processPayment(-8.4);
	cout << c.getBalance() << endl;
	}catch(exception &e){
		cout << e.what() << endl;
	}
	
	Product p = Product(17, "Jill");
	try{
	//credit = true
	c.processPurchase(4.6, p);
	cout << c.getBalance() << endl;
	c.processPurchase(30, p);
	cout << c.getBalance() << endl;
	}catch(exception &e){
		cout << e.what() << endl;
	}
	cout << endl << c << endl;	// 1 item (1 original + 1 duplicate = 1 overall)
	
	try{
	//credot = false
	c.processPayment(28.75 + 5.85);
	c.setCredit(false);
	c.processPurchase(4.6, p);
	cout << c.getBalance() << endl;
	c.processPurchase(30, p);
	cout << c.getBalance() << endl;
	}catch(exception &e){
		cout << e.what() << endl;
	}
	cout << endl << c << endl;	// 1 item (1 original + 1 failed = 1 overall)
}

void test_product(){
	Product p = Product(17, "Jill");
	cout << p.getName() << endl;
	cout << p.getID() << endl;
	
	try{
		Product q(5, "");
	}catch(exception &e){
		cout << e.what() << endl;
	}
	
	p.setName("John");
	cout << p.getName() << endl;
	cout << p.getID() << endl;
	
	p.addShipment(5, 3.81);
	cout << p.getInventoryCount() << endl;
	cout << p.getTotalPaid() << endl;
	
	cout << p.getDescription() << endl;
	cout << p.getNumberSold() << endl;
	
	p.setDescription("A thing.");
	cout << p.getDescription() << endl;
	
	try{
	p.addShipment(-5, 3.7);
	}catch(exception &e){
		cout << e.what() << endl;
	}
	
	try{
	p.addShipment(5, -3.7);
	}catch(exception &e){
		cout << e.what() << endl;
	}
	
	try{
	p.reduceInventory(3);
	}catch(exception &e){
		cout << e.what() << endl;
	}
	cout << p.getInventoryCount() << endl;
	
	try{
	p.reduceInventory(3);
	}catch(exception &e){
		cout << e.what() << endl;
	}
	cout << p.getInventoryCount() << endl;
	
	try{
	p.reduceInventory(-3);
	}catch(exception &e){
		cout << e.what() << endl;
	}
	cout << p.getInventoryCount() << endl;
	
}

void test_store(){
	Store s = Store("test store");
	
	//Test takeShipment() and sellProduct(), all else works properly
}

int main() {
	//test_product();
	//test_customer();
	test_store();
}