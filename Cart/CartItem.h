#pragma once
#include <iostream>
#include <string>

using namespace std;

#ifndef CartItem_H
#define CartItem_H

class CartItem
{
private:
	string cartID;
	string productID;
	string displayName;
	string totalItemAmount;
	string totalIemCost;

public:
	CartItem();
	CartItem(string cartID, string productID, string displayName, string totalItemAmount, string totalItemCost);

	//string search(string productID);
	//void viewCart();
	//string displayCartItem(CartItem item);

	//void addItem(string productID, string displayName, string totalItemAmount, string totalItemCost);
	//void removeItem(string productID, string totalItemAmount);

	// getters
	string getCartID() { return cartID; };
	string getProductID() { return productID; };
	string getDisplayName() { return displayName; };
	string getTotalItemAmount() { return totalItemAmount; };
	string getTotalItemCost() { return totalItemCost; };

	// setters
	void setCartID(string cartID) { this->cartID = cartID; };
	void setProductID(string productID) { this->productID = productID; };
	void setDisplayName(string displayName) { this->displayName = displayName; };
	void setTotalItemAmount(string totalItemAmount) { this->totalItemAmount = totalItemAmount; };
	void setTotalItemCost(string totalItemCost) { this->totalItemCost = totalItemCost; };
};


#endif // CartItem_H