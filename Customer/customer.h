#pragma once
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <String>

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
		
		// for historyid and cartid here you'll have to make them both strings not our classes,
		// because for the history and cart classes we will need to make a new entery even time 
		// a new item is added in. And the only why to link all the different entries to each about is 
		// to search through the list with the string id from their respective accounts.
		// So the theory is to so a rand, make sure that no other account already has it, and then
		// set it to historyID and do the same with cartID.
		//History() history;
		//Shopping Cart() cartId;
		
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
			History history; //?
			CartItem cardID; //? 
		};

		Customer(string customerID, string name, string userName, string password, string creditCardNum, string cvc, string expiration, string address, History history, CartItem cartID)
		{
			this->customerID = customerID;
			this->name = name;
			this->userName = userName;
			this->password = password;
			this->creditCardNum = creditCardNum;
			this->cvc = cvc;
			this->expiration = expiration;
			this->address = address;
			this->history = history;
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
		
		void setName(string name) { this->name = name; };
		void setUserName(string userName) { this->userName = userName; };
		void setPassword(string password) { this->password = password; };
		void setCreditCardNum(string creditCardNum) { this->creditCardNum = creditCardNum; };
		void setCVC(string cvc) { this->cvc = cvc; };
		void setExpiration(string experation) { this->expiration = expiration; };
		void setAddress(string address) { this->address = address; };
		
		void setHistory(History history) { this->history = history; };
		void setCartID(CartItem cartID) { this->cartID = cartID; };

		void edit();
		void viewAccount();
};
