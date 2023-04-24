#include <iostream>
#include <fstream>

#include "Product.h"

using namespace std;

Product::Product() {
	name = "";
	productID = "";
	price = "";
	amount = "";
}

Product::Product(string name, string amount, string productID, string price) {
	this->name = name;
	this->productID = productID;
	this->price = price;
	this->amount = amount;
}


string Product::search(string productID){
	ifstream in;
	string line;

	in.open("Inventory.txt");

	string delimiter = ";";

	Product a;
	while (getline(in, line)) {
		a.setID(line.substr(0, line.find(delimiter)));
		line.erase(0, line.find(delimiter) + delimiter.length());
		if (a.getID() == productID)
			return 0;
	}
	a.setName(line.substr(0, line.find(delimiter)));
	line.erase(0, line.find(delimiter) + delimiter.length());
	a.setAmount(line.substr(0, line.find(delimiter)));
	line.erase(0, line.find(delimiter) + delimiter.length());
	a.setPrice(line.substr(0, line.find(delimiter)));
	
	return displayProduct(a); //should be cout????


	in.close();
	return "";
}
void Product::viewInventory() {
	ifstream in;
	string line;

	in.open("Inventory.txt");

	string delimiter = ";";

	Product a;
	while (getline(in, line)) {
		a.setID(line.substr(0, line.find(delimiter)));
		line.erase(0, line.find(delimiter) + delimiter.length());
		a.setName(line.substr(0, line.find(delimiter)));
		line.erase(0, line.find(delimiter) + delimiter.length());
		a.setAmount(line.substr(0, line.find(delimiter)));
		line.erase(0, line.find(delimiter) + delimiter.length());
		a.setPrice(line.substr(0, line.find(delimiter)));

		cout << displayProduct(a);
	}

	in.close();
}

string Product::displayProduct(Product a) {
	string out = "" + a.getID() + ", " + a.getName() + ", $" + a.getPrice() + ", " + a.getAmount() + " left.\n";
	return out;
}


void Product::addItem(string name, string price, string productID) {

}
void Product::removeItem(string productID, string amount) {

}
