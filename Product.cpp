#include <iostream>
#include <fstream>

#include "Product.h"

using namespace std;

Product::Product(string name, int amount, int productID, int price) {
	this->name = name;
	this->productID = productID;
	this->price = price;
	this->amount = amount;
}

bool Product::search(int productID){
	ifstream in;
	string line;

	in.open("Inventory.txt");




}
void Product::viewProduct() {


}

void Product::addItem(string name, int price, int productID) {

}
void Product::removeItem(int productID, int amount) {

}

int Product::getAmount(int productID) {

}
void Product::setAmount(int productID, int amoount) {

}

int Product::getPrice(int produdctID) {

}
void Product::setPrice(int productID, int price) {

}

string Product::getName(int productID) {

}
void Product::setName(int productID, string name) {

}