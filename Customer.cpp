#include "Customer.h"

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <String>

using namespace std;


//write to files 
//read from files? 


void Customer::edit()
{
	char option;
	string x;
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
			cout << "Payment Information: ";
			//more options
			break;
		case 5:
			cout << "New Address: ";
			cin >> x;
			setAddress(x);
			break;
	}
}

void Customer::viewAccount()
{

}