#include <iostream>
#include <fstream>
#include <vector>
#include "Product.h"
#include "Customer.h"
#include "CartItem.h"
#include "History.h"


using namespace std;

//Product functions
void displayInventory(vector<Product>& inventory);
void addToInventory(vector<Product>& inventory, string productID, string name, string price, string amount);
void removeFromInventory(vector<Product>& inventory, string productID);
void searchInventory(vector<Product>& inventory, string produdctID);

//Customer
void displayAccount(vector<Customer>& customers, string username);
void createAccount(vector<Customer>& customers, string username, string password);
bool logon(vector<Customer>& customers, string username, string password);

//History
void displayHistory(vector<History>& history);

//Cart
void displayCart(vector<CartItem>& cart);


int main()
{
    vector<Product> inventory;
	vector<Customer> customers;
	vector<History> history;
	vector<CartItem> cart;

    cout << "Welcome to _fun name_!" << endl << "Choose your next step." << endl;
	while (true) {
		cout << "1. Exit" << endl;
		cout << "2. Login" << endl;
		cout << "3. Create Account" << endl;
		
		int num;
		cin >> num;

		if (num == 1) { //Exit
			break;
		}
		else if (num == 2) { // MAIN MENU
			while (true) { //Log on
				cout << "Enter username: ";
				string username;
				cin >> username;

				cout << endl << "Enter password: ";
				string password;
				cin >> username;
				cout << endl;

				if (logon(customers, username, password)) {
					cout << "Logging in..." << endl;
					break;
				}

				cout << "Username or Password was incorrect" << endl;
			}
			//LOGGED ON
			while (true) {
				cout << "1. View Inventory" << endl;
				cout << "2. View Your History" << endl;
				cout << "3. View Cart" << endl;
				cout << "4. View Account" << endl;
				cout << "5. Exit" << endl;

				int num2;
				cin >> num2;

				if (num2 == 1) { //view inventory
					displayInventory(inventory);
				}
				else if (num2 == 2) { //view history
					displayHistory(history);
				}
				else if (num2 == 3) { //view cart
					displayCart(cart);
				}
				else if (num2 == 4) { //view account
					displayAccount(customers);
				}
				else if (num2 == 5) {
					break;
				}
			}

		}

		else if (num == 3) { //
			cout << "Enter username: ";
			string username;
			cin >> username;

			cout << endl << "Enter password: ";
			string password;
			cin >> password;

			createAccount(customers, username, password); //make function
		}
	}


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
			inventory.erase(inventory.begin() + i - 1); 
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
