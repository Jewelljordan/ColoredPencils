#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
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
//void displayAccounts(vector<Customer>& customers, string username); //displays all accounts
void createAccount(vector<Customer>& customers, string name, string username, string password, string creditCardNum, string cvc, string expiration, string address);
bool login(vector<Customer>& customers, string username, string password, Customer& current);

//History
void displayHistory(vector<History>& history, string HistoryID);
void addToHistory(vector<History>& history, vector<Product> inventory, string HistoryID, string name, string Date);
//void addHistorytoCart(vector<History>& history, string HistoryID, int count);
void deleteHistory(vector<History>& history, string HistoryID);
string getDate();

//Cart
void displayCart(vector<CartItem>& cart, string cartID);
void addToCart(vector<CartItem>& cart, vector<Product> inventory, string cartID, string name); //create cart item
void removeFromCart(vector<CartItem>& cart, string cartID, string productID);

//Misc
//void checkOut();
void readInProduct(vector<Product>& inventory);
void readInAccount(vector<Customer>& customers);
void readInHistory(vector<History>& history);
void readInCart(vector<CartItem>& cart);

int main()
{
    vector<Product> inventory;
	vector<Customer> customers;
	vector<History> history;
	vector<CartItem> cart;

	readInProduct(inventory);
	readInAccount(customers);
	readInHistory(history);
	readInCart(cart);

	Customer current;

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

				cout <<"Enter password: ";
				string password;
				cin >> password;

				if (login(customers, username, password, current) == true) {
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
					while (true) {
						displayInventory(inventory);
						cout << "1. Add item to cart" << endl;
						cout << "2. Search Inventory" << endl;
						cout << "3. Add to Inventory" << endl;
						cout << "4. Go Back" << endl;

						int num3;
						cin >> num3;

						if (num3 == 1) {
							cout << "Item's name: ";
							string name;
							cin >> name;

							addToCart(cart, inventory, current.getCartID(), name);
							addToHistory(history, inventory, current.getHistoryID(), name, getDate());
						}

						else if (num3 == 2) {
							cout << "What is the name of the item you would like to search for?" << endl;
							string name;
							cin >> name;

							searchInventory(inventory, name);
						}

						else if (num3 == 3) {
							cout << "Please provide the below information for the item to add." << endl;
							cout << "Item's ID: ";
							string id;
							cin >> id;

							cout << "Item's Name: ";
							string name;
							cin >> name;

							cout << "Item's Price: $";
							string price;
							cin >> price;

							cout << "Item's Amount: ";
							string amt;
							cin >> amt;

							addToInventory(inventory, id, name, price, amt);
							cout << name << " is added." << endl;

						}

						else if (num3 == 4) { //go back
							break;
						}
					}
				}
				else if (num2 == 2) { //view history
					displayHistory(history, current.getHistoryID());
					while (true) {
						cout << "1. Add item to cart" << endl;
						cout << "2. Go Back" << endl;

						int num3;
						cin >> num3;

						if (num3 == 1) {
							cout << "Item's name: ";
							string name;
							cin >> name;


							addToCart(cart, inventory, current.getCartID(), name);
							addToHistory(history, inventory, current.getHistoryID(), name, getDate());
						}
						if (num3 == 2) {
							break;
						}
					}
				}
				else if (num2 == 3) { //view cart
					displayCart(cart, current.getCartID());
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
							removeFromCart(cart, current.getCartID(), id);
						} 
						else if (tmp == 2) { //check out
							//checkOut();
						}
						else if (tmp == 3) { //go back
							break;
						}
					}
				}
				else if (num2 == 4) { //view account
					current.viewAccount(); //did pass by refernce upated in logon?
					while (true) {
						cout << "1. Edit accout" << endl;
						cout << "2. Go Back" << endl;

						int num4;
						cin >> num4;

						if (num4 == 1) {//edit name
							current.edit();
						}
						else if (num4 == 2) { //go back
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
			cin.ignore();
			cout << "Enter Name: ";
			string name;
			//cin >> name;
			getline(cin, name);

			cout << "Enter username: ";
			string username;
			cin >> username;

			cout << "Enter password: ";
			string password;
			cin >> password;

			cout << "Enter your credit card information." << endl << "Card Number: ";
			string cardNumber;
			cin >> cardNumber;

			cout << "CVC: ";
			string cvc;
			cin >> cvc;

			cout << "Expiration Date: ";
			string expDate;
			cin >> expDate;

			cin.ignore();
			cout << "Enter your Address: ";
			string address;
			getline(cin, address);
			
			cout << endl;

			createAccount(customers, name, username, password, cardNumber, cvc, expDate, address); //make function
		}
	}


}

//Product functions
void displayInventory(vector<Product>& inventory) {
    for (int i = 0; i < inventory.size(); i++)
    {
        cout << "ID: " << inventory[i].getID() << endl;
        cout << "Name: " << inventory[i].getName() << endl;
        cout << "Amount: " << inventory[i].getAmount() << " left" << endl;
        cout << "Price: $" << inventory[i].getPrice() << endl;
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

void searchInventory(vector<Product>& inventory, string name) { 
	ifstream in;
	string line;

	bool pres = false;

	in.open("Inventory.txt");

	string delimiter = ";";

	Product a;
	while (getline(in, line)) {
		a.setID(line.substr(0, line.find(delimiter)));
		line.erase(0, line.find(delimiter) + delimiter.length());
		a.setName(line.substr(0, line.find(delimiter)));
		line.erase(0, line.find(delimiter) + delimiter.length());
		if (a.getName() == name) {
			pres = true;
			break;
		}

	}
	
	a.setAmount(line.substr(0, line.find(delimiter)));
	line.erase(0, line.find(delimiter) + delimiter.length());
	a.setPrice(line.substr(0, line.find(delimiter)));

	if (pres) {
		cout << a.displayProduct() << endl;
	}
	else {
		cout << name << " is not available." << endl;
	}

	in.close();
}

//History
void addToHistory(vector<History>& history, vector<Product> inventory, string HistoryID, string name, string Date) {
	ofstream outfile;

	string itemID;

	cout << "MF" << endl;

	for (int i = 0; i < inventory.size(); i++) {
		if (inventory[i].getName() == name) {
			itemID = inventory[i].getID();
		}
	}


	outfile.open("History.txt", ios::app);
	outfile << HistoryID << ";" << itemID << ";" << Date << endl;

	outfile.close();

	history.push_back(History(HistoryID, itemID, Date));
}

/*
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
*/

void displayHistory(vector<History>& history, string HistoryID)
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

string getDate() {/*
	time_t now = time(0);
	struct tm newtime;
	tm* ltm = localtime_s(&newtime, &now);
	int year = 1900 + ltm->tm_year;
	int month = 1 + ltm->tm_mon;
	int day = ltm->tm_mday;
	int hour = 5 + ltm->tm_hour;
	int min = 30 + ltm->tm_min;
	int sec = ltm->tm_sec;

	return "" + to_string(month) + "\/" + to_string(day) + "\/" + to_string(year) + " " + to_string(hour) + ":" + to_string(min) + ":" + to_string(sec);
	*/

	return "Placeholder";
}

//customer
void createAccount(vector<Customer>& customers, string name, string username, string password, string creditCardNum, string cvc, string expiration, string address)
{
	srand(time(nullptr));
	string customerID = to_string(rand() % 10000000 +1000000);
	string cartID = to_string(rand() % 10000000 + 1000000);
	string historyID = to_string(rand() % 10000000 + 1000000);


	//write to file and vector
	ofstream outfile;

	outfile.open("Account.txt", ios::app);
	outfile << customerID << ";" << name << ";" << username << ";" << password << ";" << creditCardNum << ";" << cvc << ";" << expiration << ";" << address << ";" << historyID << ";" << cartID << endl;

	outfile.close();

	customers.push_back(Customer(customerID, name, username, password, creditCardNum, cvc, expiration, address, historyID, cartID)); //needs to insert information

	cout << "Account Created!" << endl;
	//customers[customers.size()-1].viewAccount();
}

bool login(vector<Customer>& customers, string username, string password, Customer& current)
{
	for (int i = 0; i < customers.size(); i++)
	{
		//cout << customers[i].getUserName() << " " << customers[i].getPassword() << endl;
		if (customers[i].getUserName() == username && customers[i].getPassword() == password)
		{
			current = customers[i];
			return true;
		}
	}
	return false;
}



//cart
void addToCart(vector<CartItem>& cart, vector<Product> inventory, string cartID, string name)
{
	ofstream outfile;
	string productID;
	string price;

	outfile.open("CartItem.txt", ios::app);

	for (int i = 0; i < inventory.size(); i++) {
		if (inventory[i].getName() == name) {
			productID = inventory[i].getID();
			price = inventory[i].getPrice();
		}
	}

	outfile << cartID << ";" << productID << ";" << name << ";" << price << endl;

	outfile.close();

	cart.push_back(CartItem(cartID, productID, name, price));
}

void removeFromCart(vector<CartItem>& cart, string cartID, string productID)
{
	for (int i = 0; i < cart.size(); i++)
	{
		if (cart[i].getCartID() == cartID)
		{
			if (cart[i].getProductID() == productID)
			{
				cart.erase(cart.begin() + i - 1);
			}
		}
	}
	ofstream out;
	out.open("CartItem.txt");

	for (int i = 0; i < cart.size(); i++) {
		out << cart[i].getCartID() << ";" << cart[i].getProductID() << ";" + cart[i].getDisplayName() << ";" + cart[i].getTotalItemCost() << endl;
	}

	out.close();
}

void displayCart(vector<CartItem>& cart, string cartID)
{
	for (int i = 0; i < cart.size(); i++)
	{
		if (cart[i].getCartID() == cartID)
		{
			cout << "ID: " << cart[i].getProductID() << endl;
			cout << "Item: " << cart[i].getDisplayName() << endl;
			cout << "Cost: " << cart[i].getTotalItemCost() << endl;
			cout << endl;
		}
	}
}

//READ IN FILES
void readInProduct(vector<Product>& inventory) {

	ifstream infile;
	infile.open("Inventory.txt");

	string line;

	// loops through file
	while (getline(infile, line))
	{
		// initial variables
		string productID, name, amount, price;

		string delimiter = ";";

		productID = line.substr(0, line.find(delimiter));
		line.erase(0, line.find(delimiter) + delimiter.length());
		name = line.substr(0, line.find(delimiter));
		line.erase(0, line.find(delimiter) + delimiter.length());
		price = line.substr(0, line.find(delimiter));
		line.erase(0, line.find(delimiter) + delimiter.length());
		amount = line.substr(0, line.find(delimiter));

		Product temp(name, amount, productID, price);

		inventory.push_back(temp);
	}

	infile.close();
}

void readInAccount(vector<Customer>& customers) {
	ifstream infile;
	infile.open("Account.txt");

	string line;

	// loops through file
	while (getline(infile, line))
	{
		// initial variables
		string customerID, name, userName, password, creditCardNum, cvc, expiration, address, historyID, cartID;

		string delimiter = ";";

		customerID = line.substr(0, line.find(delimiter));
		line.erase(0, line.find(delimiter) + delimiter.length());
		name = line.substr(0, line.find(delimiter));
		line.erase(0, line.find(delimiter) + delimiter.length());
		userName = line.substr(0, line.find(delimiter));
		line.erase(0, line.find(delimiter) + delimiter.length());
		password = line.substr(0, line.find(delimiter));
		line.erase(0, line.find(delimiter) + delimiter.length());
		creditCardNum = line.substr(0, line.find(delimiter));
		line.erase(0, line.find(delimiter) + delimiter.length());
		cvc = line.substr(0, line.find(delimiter));
		line.erase(0, line.find(delimiter) + delimiter.length());
		expiration = line.substr(0, line.find(delimiter));
		line.erase(0, line.find(delimiter) + delimiter.length());
		address = line.substr(0, line.find(delimiter));
		line.erase(0, line.find(delimiter) + delimiter.length());
		historyID = line.substr(0, line.find(delimiter));
		line.erase(0, line.find(delimiter) + delimiter.length());
		cartID = line.substr(0, line.find(delimiter));

		Customer temp(customerID, name, userName, password, creditCardNum, cvc, expiration, address, historyID, cartID);

		customers.push_back(temp);
	}

	infile.close();
}

void readInHistory(vector<History>& history) {
	ifstream infile;
	infile.open("Account.txt");

	string line;

	// loops through file
	while (getline(infile, line))
	{
		// initial variables
		string historyID, productID, date;

		string delimiter = ";";

		historyID = line.substr(0, line.find(delimiter));
		line.erase(0, line.find(delimiter) + delimiter.length());
		productID = line.substr(0, line.find(delimiter));
		line.erase(0, line.find(delimiter) + delimiter.length());
		date = line.substr(0, line.find(delimiter));

		History temp(historyID, productID, date);

		history.push_back(temp);
	}

	infile.close();
}

void readInCart(vector<CartItem>& cart) {
	ifstream infile;
	infile.open("Account.txt");

	string line;

	// loops through file
	while (getline(infile, line))
	{
		// initial variables
		string cartID, productID, name, price;

		string delimiter = ";";

		cartID = line.substr(0, line.find(delimiter));
		line.erase(0, line.find(delimiter) + delimiter.length());
		productID = line.substr(0, line.find(delimiter));
		line.erase(0, line.find(delimiter) + delimiter.length());
		name = line.substr(0, line.find(delimiter));
		line.erase(0, line.find(delimiter) + delimiter.length());
		price = line.substr(0, line.find(delimiter));

		CartItem temp(cartID, productID, name, price);

		cart.push_back(temp);
	}

	infile.close();
}
