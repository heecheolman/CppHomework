//
//  MiddleMan.h
//  ReserveSystem
//
//  Created by HeeCheol Kim on 21/11/2018.
//  Copyright © 2018 HeeCheol Kim. All rights reserved.
//

#pragma once

#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <dirent.h>
#include <vector>

#include "PathDef.h"
#include "OrderSheet.h"
#include "Receipt.h"
#include "ShoppingBasket.h"
#include "Store.h"
#include "OrderGroup.h"

class MiddleMan {
public:
    MiddleMan();
    void registStoreList();
    void showStoreList();
    void groupingBasket();
    void makeOutOrderSheet();
    void makeOutReceipt();
    void putItemToBasket(int storeId, string storeName, string itemName, int itemCount, int itemPrice);
    void clearBasketData();
private:
    string defaultPath;
    DIR *dir;
    struct dirent *ent;
    ofstream out;
    ifstream in;
    OrderSheet os;
    Receipt r;
public:
    vector <OrderGroup> group;
    vector <Store*> storeList;
    ShoppingBasket *shoppingBasket;
};
