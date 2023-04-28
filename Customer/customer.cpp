#include "Customer.h"

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <String>
#include "History.h"
#include "CartItem.h"

using namespace std;

//write to files 
//read from files? 

void Customer::edit()
{
	char option, option2;
	string x, y;
	cout << "What do you want to edit? (Enter the number)" << endl;
	cout << "1. Name" << endl << "2. Username" << endl << "3. Password" << endl << "4. Payment Information" << endl << "5. Address" << endl;

	switch (option)
	{
		case 1:
			cout << "New Name: ";
			cin >> x;
			setName(x);
			break;
		case 2:
			cout << "New Username: ";
			cin >> x;
			setUserName(x);
			break;
		case 3:
			cout << "New Password: ";
			cin >> x; 
			setPassword(x);
			break;
		case 4:
			cout << "Payment Information: " << endl;
			//more options
			cout << "1. Credit Card Number" << endl << "2. CVC Number" << endl << "3. Expiration Date" << endl;
			cin >> option2;
			switch (option2)
			{
				case 1:
					cout << "New Credit Card Number: ";
					cin >> y;
					setCreditCardNum(y);
					break;
				case 2:
					cout << "New CVC Number: ";
					cin >> y;
					setCVC(y);
					break;
				case 3:
					cout << "New Expiration Date: ";
					cin >> y;
					setExpiration(y);
					break;
			}
			break;
		case 5:
			// will probrably need to use getline instead here because address are not 1 word
			cout << "New Address: ";
			cin >> x;
			setAddress(x);
			break;
		default:
			cout << "Invalid Input" << endl;
	}
}

void Customer::viewAccount()
{
	cout << "Name: " << getName() << endl;
	cout << "Username: " << getUserName() << endl;
	cout << "Password: " << getPassword() << endl;
	cout << "Address: " << getAddress() << endl;
}
