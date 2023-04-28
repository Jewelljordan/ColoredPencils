#pragma once
#include <iostream>
#include <String>

using namespace std;

#ifndef Product_H
#define Product_H

class Product {
private:
	string name;
	string amount;
	string productID;
	string price;
public:
	Product() {
		name = "";
		productID = "";
		price = "";
		amount = "";
	};

	Product(string name, string amount, string productID, string price) {
		this->name = name;
		this->productID = productID;
		this->price = price;
		this->amount = amount;
	};

	//string search(string productID);
	//void viewInventory();
	string displayProduct() {
		string out = "" + productID + ", " + name + ", $" + price + ", " + amount + " left.\n";
		return out;
	};

	//void addItem(string productID, string name, string price, string amount);
	//void removeItem(string productID, string amount);

	// getters
	string getID() { return productID; };
	string getName() { return name; };
	string getAmount() { return amount; };
	string getPrice() { return price; };

	// setters
	void setID(string productID) { this->productID = productID; };
	void setName(string name) { this->name = name; };
	void setAmount(string amount) { this->amount = amount; };
	void setPrice(string price) { this->price = price; };
};

#endif