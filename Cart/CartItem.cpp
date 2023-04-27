#include <iostream>
#include <fstream>
#include <vector>
#include "CartItem.h"

using namespace std;

int main()
{
	vector<CartItem> cart;
}

    //string search(string productID);
	//void viewCart();
	//string displayCartItem(CartItem item);

	//void addItem(string productID, string displayName, string totalItemAmount, string totalItemCost);
	//void removeItem(string productID, string totalItemAmount);

	//+addItem(productID: int)
	//+removeItem(productID: int)
	//+updateQuanity(productID: int)
	//+updateTotal(productID: int)
	//+readShoppingCart(): void

	void addCartItem(vector<CartItem>& cart, string cartID, string productID)
	{
		//Use productID to pull Name, ItemAmount, and ItemCost.
		//Increment search for item amount. 
		CartItem(cartID, productID)
	}
	void removeCartItem(vector<CartItem>& cart, string cartID, string productID)
	{
		for(int i = 0; i < Cart.size(); i++)
		{
			if(cart[i].getCartID() == cartID)
			{
				if(cart[i].getProductID() == productID)
				{
					cart.erase(cart.begin() + i -1);
				}
			}
		}
		ofstream out;
		out.open("CartItem.txt");

		for (int i = 0; i < cart.size(); i++) {
			out << cart[i].getCartID() << ";" << cart[i].getProductID() << ";" + cart[i].getDisplayName() << ";" + cart[i].getTotalItemAmount() << ";" + cart[i].getTotalItemAmount() << endl;
		}

		out.close();
	}

	void updateQuanity(vector<CartItem>& cart, string cartID, string productID, string quanity)
	{
		for(int i = 0; i < Cart.size(); i++)
		{
			if(cart[i].getCartID() == cartID)
			{
				if(cart[i].getProductID() == productID)
				{
					cart[i].setTotalItemAmount(quanity); 
					//Int total = Get price from inventory with stoi
					cart[i].setTotalItemCost(total);
				}
			}
		}
		ofstream out;
		out.open("CartItem.txt");

		for (int i = 0; i < cart.size(); i++) {
			out << cart[i].getCartID() << ";" << cart[i].getProductID() << ";" + cart[i].getDisplayName() << ";" + cart[i].getTotalItemAmount() << ";" + cart[i].getTotalItemAmount() << endl;
		}

		out.close();	
	}

	void readCartItems(vector<CartItem>& cart, string cartID)
	{
		for(int i = 0; i < Cart.size(); i++)
		{
			if(cart[i].getCartID() == cartID)
			{
				cout << "Item: " << getDisplayName << endl;
				cout << "Amount: " << getTotalItemAmount << endl;
				cout << "Cost: " << getTotalItemCost << endl;
				cout << endl;
			}
		}
	}
