//
//  ShoppingBasket.h
//  ReserveSystem
//
//  Created by HeeCheol Kim on 21/11/2018.
//  Copyright © 2018 HeeCheol Kim. All rights reserved.
//

#pragma once

#include <iostream>
#include <vector>
#include <iomanip>
#include "VirtualItem.h"

class ShoppingBasket {
public:
    ShoppingBasket();
    void addItemToBasket(int storeId, string stroeName, string itemName, int itemCount, int itemPrice);
    void clearBasket();
    void showBasketItemList();
    void calcTotalItemPrice();
    inline void setDeliveryState(bool state) { this->doDelivery = state; }
    inline bool getDeliveryState() { return this->doDelivery; }
    inline int getTotalPrice() { return this->totalPrice; }
    vector <VirtualItem*> basketList;
private:
    int totalPrice;
    bool doDelivery;
};
