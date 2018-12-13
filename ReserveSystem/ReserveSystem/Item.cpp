//
//  Item.cpp
//  ReserveSystem
//
//  Created by HeeCheol Kim on 27/11/2018.
//  Copyright © 2018 HeeCheol Kim. All rights reserved.
//

#include "Item.h"

Item::Item(string itemName, int itemPrice, int itemCount) {
    this->itemName = itemName;
    this->itemPrice = itemPrice;
    this->itemCount = itemCount;
}

void Item::showItemInfo() {
    cout << "│              " << setw(15) << left << itemName << setw(10) << right << "│" << "       " << setw(13) << left << itemPrice << "│" << setw(4) << left << " " << setw(8) << left << itemCount << "│" << endl;
}
