#pragma once
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <String>
#include "Product.h"
#include "Customer.h"
#include "CartItem.h"
#include "History.h"

using namespace std;

class Customer
{
private:
	string customerID;
	string name;
	string userName;
	string password;
	string creditCardNum;
	string cvc;
	string expiration;
	string address;
	string historyID;
	string cartID;

public:
	Customer()
	{
		customerID = "";
		name = "";
		userName = "";
		password = "";
		creditCardNum;
		cvc = "";
		expiration = "";
		address = "";
		historyID = ""; //?
		cartID = ""; //? 
	};

	Customer(string customerID, string name, string userName, string password, string creditCardNum, string cvc, string expiration, string address, string historyID, string cartID)
	{
		this->customerID = customerID;
		this->name = name;
		this->userName = userName;
		this->password = password;
		this->creditCardNum = creditCardNum;
		this->cvc = cvc;
		this->expiration = expiration;
		this->address = address;
		this->historyID = historyID;
		this->cartID = cartID;
	}; //ADDED AFTER DESIGN - add history and cart id

	string getName() { return name; };
	string getUserName() { return userName; };
	string getPassword() { return password; };
	string getCreditCardNum() { return creditCardNum; };
	string getCVC() { return cvc; };
	string getExpiration() { return expiration; }
	string getAddress() { return address; };
	string getCustomerID() { return customerID; };

	string getHistoryID() { return historyID; };
	string getCartID() { return cartID; };


	void setName(string name) { this->name = name; };
	void setUserName(string userName) { this->userName = userName; };
	void setPassword(string password) { this->password = password; };
	void setCreditCardNum(string creditCardNum) { this->creditCardNum = creditCardNum; };
	void setCVC(string cvc) { this->cvc = cvc; };
	void setExpiration(string expiration) { this->expiration = expiration; };
	void setAddress(string address) { this->address = address; };

	void setHistoryID(string history) { this->historyID = history; };
	void setCartID(string cartID) { this->cartID = cartID; };

	void edit();
	void viewAccount();
};
