#ifndef STORE_H
#define STORE_H

#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include "Customer.h"
#include "Product.h"

class Store{
	std::vector<Product> products;
	std::vector<Customer> customers;
	std::string name;
	
public:
	Store();
	Store(std::string name);
	std::string getName() const;
	void setName(std::string name);
	

	void addProduct(int productID, std::string productName); 
	/*
	Create a new Product and add it to products. If this productID already belongs to another product, throw an exception.
	*/
	
	Product& getProduct(int productID); 
	/*
	Find the matching product and return it. Be sure that the product can be modified so that the changes persist in the store's vector. If the product does not exist throw an exception.
	*/
	
	void addCustomer(int customerID, std::string customerName, bool credit = false);
	/*
	Create a new Customer and add it to customers. If this customerID already belongs to another customer, throw an exception.
	*/
	
	Customer& getCustomer(int customerID); 
	/*
	Find the matching customer and return it. Be sure that the customer can be modified so that the changes persist in the store's vector. If the customer does not exist throw an exception.
	*/
	
	void takeShipment(int productID, int quantity, double cost); 
	/*
	Find matching Product. If product is not in list of products throw an exception. Otherwise, update product with the shipment quantity and cost.
	*/
	
	void sellProduct(int customerID, int productID, int quantity);
	/*
	Make the sale if it is allowed, otherwise throw an exception or let an exception propagate. In this context allowed means that the product's reduceInventory() and the customer's processPurchase() functions would not throw an exception and the product and customer must exist. Warning: Do not change the product or customer if both cannot be done successfully.
	*/
	
	void takePayment(int customerID, double amount);
	/*
	Find matching customer and process the payment. If the customer does not exist, you should throw an exception or let an exception propagate that is thrown when you call another function to get the customer.
	*/
	
	void listProducts() const;
	/*
	Output information about each product. (Use overloaded output operator for Product.)
	*/
	
	void listCustomers() const;
	/*
	Output information about each customer. (Use overloaded output operator for Customer.)
	*/


};
 
#endif
