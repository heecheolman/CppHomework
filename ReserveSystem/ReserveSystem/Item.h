//
//  Item.h
//  ReserveSystem
//
//  Created by HeeCheol Kim on 21/11/2018.
//  Copyright © 2018 HeeCheol Kim. All rights reserved.
//

#pragma once

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Item {
public:
    Item(string itemName, int itemPrice, int itemCount);
    void showItemInfo();
    inline void setItemCount(int count) { this->itemCount -= count; }
    inline string getItemName() { return this->itemName; }
    inline int getItemCount() { return this->itemCount; }
    inline int getItemPrice() { return this->itemPrice; }
private:
    string itemName;
    int itemPrice;
    int itemCount;
};
