#include <iostream>
#include <fstream>
#include <vector>
#include "Product.h"

using namespace std;

//Product functions
void displayInventory(vector<Product>& inventory);
void addToInventory(vector<Product>& inventory, string productID, string name, string price, string amount);
void removeFromInventory(vector<Product>& inventory, string productID);
void searchInventory(vector<Product>& inventory, string produdctID);

int main()
{
    vector<Product> inventory;

    cout << "Welcome to _fun name_!" << endl << "Choose your next step." << endl;


}

//Product functions
void displayInventory(vector<Product>& inventory) {
    for (int i = 0; i < inventory.size(); i++)
    {
        cout << "ID: " << inventory[i].getID() << endl;
        cout << "Name: " << inventory[i].getName() << endl;
        cout << "Amount: " << inventory[i].getAmount() << endl;
        cout << "Price: " << inventory[i].getPrice() << endl;
        cout << endl;
    }
}

void addToInventory(vector<Product>& inventory, string productID, string name, string price, string amount) {
	ofstream outfile;

	outfile.open("Inventory.txt", ios::app);
	outfile << productID << ";" << name << ";" << price << ";" << amount << endl;

	outfile.close();

	inventory.push_back(Product(productID, name, price, amount));
}

void removeFromInventory(vector<Product>& inventory, string productID) {
	for (int i = 0; i < inventory.size(); i++) {
		if (inventory[i].getID() == productID)
			inventory.erase(inventory.begin() + i -1); //bruh what, how does one remove from vector
														// I think this will make it work correctly -J
	}

	ofstream out;
	out.open("Inventory.txt");

	for (int i = 0; i < inventory.size(); i++) {
		out << inventory[i].getID() << ";" << inventory[i].getName() << ";" << inventory[i].getPrice() << ";" + inventory[i].getAmount() << endl;
	}

	out.close();

}

void searchInventory(vector<Product>& inventory, string productID) { //vector????
	ifstream in;
	string line;

	in.open("Inventory.txt");

	string delimiter = ";";

	Product a;
	while (getline(in, line)) {
		a.setID(line.substr(0, line.find(delimiter)));
		line.erase(0, line.find(delimiter) + delimiter.length());
		if (a.getID() == productID)
			return; //break while?
	}
	a.setName(line.substr(0, line.find(delimiter)));
	line.erase(0, line.find(delimiter) + delimiter.length());
	a.setAmount(line.substr(0, line.find(delimiter)));
	line.erase(0, line.find(delimiter) + delimiter.length());
	a.setPrice(line.substr(0, line.find(delimiter)));

	cout << a.displayProduct() << endl; 

	in.close();
}