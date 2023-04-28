#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>
#include <cstdlib>
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
void addToHistory(vector<History>& history, string HistoryID, string itemID, string Date);
void addHistorytoCart(vector<History>& history, string HistoryID, int count);
void readHistory(vector<History>& history, string HistoryID);
void deleteHistory(vector<History>& history, string HistoryID);

//Cart
void displayCart(vector<CartItem>& cart);
void addToCart(vector<CartItem>& cart, string productID); //create cart item
void removeFromCart(vector<CartItem>& cart, string prodcutID);

//Misc
void checkOut();

int main()
{
    vector<Product> inventory;
	vector<Customer> customers;
	vector<History> history;
	vector<CartItem> cart;

	// we probs need to open all the files and update the vectors here

	Customer current;

    cout << "Welcome to _fun name_!" << endl << "Choose your next step." << endl;
	while (true) {
		cout << "1. Exit" << endl;
		cout << "2. Login" << endl;
		cout << "3. Create Account" << endl;
		
		// we could probs just reuse this same num throughout for option 
		// so we don't have to make a new variable every time
		int num;
		cin >> num;

		if (num == 1) { //Exit
			// cout << "Shutting Down..." << endl;
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
					while (true) {
						cout << "1. Add item to cart" << endl;
						cout << "2. Go Back" << endl;

						int num3;
						cin >> num3;

						if (num3 == 1) {
							cout << "Item's ID: ";
							string id;
							cin >> id;

							cout << "How many: ";
							string quanity;
							cin >> quanity;

							addToCart(cart, id); //what other parameters?....
						}
						if (num3 == 2) {
							break;
						}
					}
				}
				else if (num2 == 2) { //view history
					displayHistory(history);
					while (true) {
						cout << "1. Add item to cart" << endl;
						cout << "2. Go Back" << endl;

						int num3;
						cin >> num3;

						if (num3 == 1) {
							cout << "Item's ID: ";
							string id;
							cin >> id;

							cout << "How many: ";
							string quanity;
							cin >> quanity;

							addToCart(cart, id); //what other parameters?....
						}
						if (num3 == 2) {
							break;
						}
					}
				}
				else if (num2 == 3) { //view cart
					displayCart(cart);
					while (true) {
						cout << "1. Remove Item" << endl;
						cout << "2. Check out cart" << endl;
						cout << "3. Go Back" << endl;

						int tmp;
						cin >> tmp;

						if (tmp == 1) { //remove item from cart
							cout << "Item's ID: ";
							string id;
							cin >> id;
							removeFromCart(cart, id);
						} 
						else if (tmp == 2) { //check out
							checkOut();
						}
						else if (tmp == 3) { //go back
							break;
						}
					}
				}
				else if (num2 == 4) { //view account
					displayAccount(customers); //need to fix to display only current customer
					while (true) {
						cout << "1. Edit name" << endl;
						cout << "2. Edit username" << endl;
						cout << "3. Edit password" << endl;
						cout << "4. Edit card information" << endl;
						cout << "5. Exit" << endl;

						int num4;
						cin >> num4;

						if (num4 == 1) {//edit name

						}
						else if (num4 == 2) {//edit username

						}
						else if (num4 == 3) {//edit password

						}
						else if (num4 == 4) {//edit card information

						}
						else if (num4 == 5) {
							break;
						}
					}

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

			// check to make sure its not a duplicate
			int i = 0;
			while(i < customers.size())
			{
				if(username == customers[i].getUserName())
				{
					cout << endl << "This username is taken please choose another one: ";
					cin >> username;
					i = -1;
				}
				i++;
			}

			cout << endl << "Enter password: ";
			string password;
			cin >> password;

			// same here but for password
			i = 0;
			while(i < customers.size())
			{
				if(password == customers[i].getPassword())
				{
					cout << endl << "This password is taken please choose another one: ";
					cin >> password;
					i = -1;
				}
				i++;
			}

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

//Customer functions
//void displayAccount(vector<Customer>& customers, string username);
void createAccount(vector<Customer>& customers, string username, string password)
{
	// get rest on info
	//Customer(string customerID, string name, string userName, string password, string creditCardNum, 
	// string cvc, string expiration, string address, string historyID, string cartID)
	string creditCardnum, cvc, expiration, address, historyID, cartID;

	// card info
	cout << endl << endl << "Please enter your credit card information." ;
	cout << endl << "Credit Car Number: ";
	cin >> creditCardnum;
	cout << endl << "cvc: ";
	cin >> cvc;
	cout << endl << "experation date (mm/yy): ";
	cin >> expiration;

	// address
	cout << endl << endl << "Now please enter your full shipping address.";
	getline(cin >> ws, address);

	// using rand to generate both IDs
	srand(time(0));
	historyID = rand();
	cartID = rand();

	// makes sure they special :D
	int i = 0;
	while(i < customers.size())
	{
		if(historyID == customers[i].getHistoryID())
		{
			historyID = rand();
			i = -1;
		}
		if(cartID == customers[i].getCartID())
		{
			cartID = rand();
			i = -1;
		}
		i++;
	}

	//write to file and vector
	ofstream outfile;

	outfile.open("Account.txt", ios::app);
	outfile << username << ";" << password <<  endl;

	outfile.close();

	customers.push_back(Customer()); //needs to insert information
}

bool logon(vector<Customer>& customers, string username, string password)
{
	for (int i = 0; i < customers.size(); i++)
	{
		if (customers[i].getUserName() == username && customers[i].getPassword() == password)
		{
			return true;
		}
	}
	return false;

}

//History
void addToHistory(vector<History>& history, string HistoryID, string itemID, string Date) {
	ofstream outfile;

	outfile.open("History.txt", ios::app);
	outfile << HistoryID << ";" << itemID << ";" << Date << endl;

	outfile.close();

	history.push_back(History(HistoryID, itemID, Date));
}

void addHistorytoCart(vector<History>& history, string HistoryID, int count)
{
	int counter = 0;

	for (int i = 0; i < history.size(); i++)
	{
		if (history[i].getHistoryID() == HistoryID)
		{
			if (counter == count)
			{
				// add
			}
		}
	}
}

void readHistory(vector<History>& history, string HistoryID)
{
	int count = 0;

	for (int i = 0; i < history.size(); i++)
	{
		if (history[i].getHistoryID() == HistoryID)
		{
			cout << count << "." << endl;
			cout << "  itemID: " << history[i].getItemID() << endl;
			cout << "  Date: " << history[i].getDate() << endl;
			cout << endl;
		}
	}
}

void deleteHistory(vector<History>& history, string HistoryID)
{
	for (int i = 0; i < history.size(); i++) {
		if (history[i].getHistoryID() == HistoryID)
			history.erase(history.begin() + i - 1);
	}

	ofstream out;
	out.open("History.txt");

	for (int i = 0; i < history.size(); i++) {
		out << history[i].getHistoryID() << ";" << history[i].getItemID() << ";" + history[i].getDate() << endl;
	}

	out.close();
}
