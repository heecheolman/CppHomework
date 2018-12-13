//
//  Store.h
//  ReserveSystem
//
//  Created by HeeCheol Kim on 21/11/2018.
//  Copyright © 2018 HeeCheol Kim. All rights reserved.
//

#pragma once

#include <vector>
#include "Item.h"

class Store {
public:
    Store(string storeDir, string storeName, string robot, int storeId);
    void showStoreInfo();
    void addItemFromList(string itemName, int itemPrice, int itemCount);
    void updateStock(int itemId, int count);
    void showItemList();
    inline string getStoreName() { return this->storeName; }
    inline Item* getSelectedItem(int selectedItem) { return itemList[selectedItem]; }
    inline int getStoreId() { return this->storeId; }
    inline void increaseOrderId() { (this->orderId)++; }
    inline int getOrderId() { return this->orderId; }
private:
    string storeDir;
    string storeName;
    string robot;
    int orderId;
    int storeId;
public:
    vector <Item*> itemList;
};
