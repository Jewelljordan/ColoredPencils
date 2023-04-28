#include <iostream>
#include <fstream>

#include "Product.h"

using namespace std;

/*
string Product::displayProduct() {
	string out = "" + productID + ", " + name + ", $" + price + ", " + amount + " left.\n";
	return out;
}


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


void Product::addItem(string productID, string name, string price, string amount) {
	ofstream outfile;

	outfile.open("Inventory.txt", ios::app);

	outfile << productID << ";" << name << ";" << price << ";" << amount << endl;

}
void Product::removeItem(string productID, string amount) {


}
*/