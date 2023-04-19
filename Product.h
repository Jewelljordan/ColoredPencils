#pragma once
#include <iostream>
#include <String>

using namespace std;

#ifndef Product_H
#define Product_H

class Product {
private:
	string name;
	int amount;
	int productID;
	int price;
public:
	Product(string name, int amount, int productID, int price);

	bool search(int productID);
	void viewProduct();

	void addItem(string name, int price, int productID);
	void removeItem(int productID, int amount);

	int getAmount(int productID);
	void setAmount(int productID, int amoount);

	int getPrice(int produdctID);
	void setPrice(int productID, int price);

	string getName(int productID);
	void setName(int productID, string name);
};

#endif