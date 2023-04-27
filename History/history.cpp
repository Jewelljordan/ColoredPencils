#include <iostream>
#include <fstream>
#include <vector>
#include "History.h"

using namespace std;

void addToHistory(vector<History>& history, string HistoryID, string itemID, string Date);
void addHistorytoCart(vector<History>& history, string HistoryID, int count);
void readHistory(vector<History>& history, string HistoryID);
void deleteHistory(vector<History>& history, string HistoryID);

int main()
{
    vector<History> history;
    
}

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
        if(history[i].getHistoryID() == HistoryID)
        {
            if(counter == count)
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
        if(history[i].getHistoryID() == HistoryID)
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
			history.erase(history.begin() + i -1);
	}

	ofstream out;
	out.open("History.txt");

	for (int i = 0; i < history.size(); i++) {
		out << history[i].getHistoryID() << ";" << history[i].getItemID() << ";" + history[i].getDate() << endl;
	}

	out.close();
}
