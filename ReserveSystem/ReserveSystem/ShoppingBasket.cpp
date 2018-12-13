//
//  ShoppingBasket.cpp
//  ReserveSystem
//
//  Created by HeeCheol Kim on 27/11/2018.
//  Copyright © 2018 HeeCheol Kim. All rights reserved.
//

#include "ShoppingBasket.h"

ShoppingBasket::ShoppingBasket() {
    this->totalPrice = 0;
}
// 장바구니에 아이템 추가
void ShoppingBasket::addItemToBasket(int storeId, string storeName, string itemName, int itemCount, int itemPrice) {
    for(int i = 0; i < this->basketList.size(); i++) {
        if(basketList[i]->itemName.compare(itemName) == 0) {
            basketList[i]->itemCount += itemCount;
            return;
        }
    }
    VirtualItem *vItem = new VirtualItem;
    vItem->storeId = storeId;
    vItem->storeName = storeName;
    vItem->itemName = itemName;
    vItem->itemCount = itemCount;
    vItem->itemPrice = itemPrice;
    basketList.push_back(vItem);
}

// 장바구니 초기화
void ShoppingBasket::clearBasket() {
    basketList.erase(basketList.begin(), basketList.end());
    this->totalPrice = 0;
    this->doDelivery = false;
}

// 장바구니 전체 보여주기
void ShoppingBasket::showBasketItemList() {
    for(int i = 0; i < basketList.size(); i++) {
        VirtualItem *vi = basketList[i];
        cout << "@ " << setw(10) << left << vi->itemName << "____" << vi->itemCount << "개" << endl;
    }
}

// 전체 가격을 알려줌
void ShoppingBasket::calcTotalItemPrice() {
    for(int i = 0; i < basketList.size(); i++) {
        VirtualItem *vi = basketList[i];
        this->totalPrice += vi->itemCount * vi->itemPrice;
    }
    if(this->doDelivery) {
        this->totalPrice += 2500;
    }
}
