#pragma once
#include <iostream>
#include <string>

using namespace std;

#ifndef HISTORY_H
#define HISTORY_H

class History
{
private:
    string HistoryID, ItemID, Date;

public:
    History()
    {
        HistoryID = " ";
        ItemID = " ";
        Date = " ";
    };

    History(string HistoryID, string ItemID, string Date)
    {
        this->HistoryID = HistoryID;
        this->ItemID = ItemID;
        this->Date = Date;
    };

    //getters
    string getHistoryID() { return HistoryID; };
    string getItemID() { return ItemID; };
    string getDate() { return Date; };

    // setters
    void setHistoryID(string HistoryID) { HistoryID = this->HistoryID; };
    void setItemID(string SetItemID) { ItemID = this->ItemID; };
    void setDate(string Date) { Date = this->Date; };





};

#endif // HISTORY_H