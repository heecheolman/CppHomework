//
//  Store.cpp
//  ReserveSystem
//
//  Created by HeeCheol Kim on 27/11/2018.
//  Copyright © 2018 HeeCheol Kim. All rights reserved.
//

#include "Store.h"

Store::Store(string storeDir, string storeName, string robot, int storeId) {
    this->storeDir = storeDir;
    this->storeName = storeName;
    this->robot = robot;
    this->storeId = storeId;
    this->orderId = 0;
}
// 상점의 정보를 보여주는 함수
void Store::showStoreInfo() {
    cout << "│" << setw(3) << left << this->storeId << "│          " << setw(15) << left << this->storeName << setw(7) << right << "│" << setw(50) << left << this->robot << "│" << endl;
    
}
// 프로그램 초기에  아이템리스트에 아이템을 등록하는 함수
void Store::addItemFromList(string itemName, int itemPrice, int itemCount) {
    Item *item = new Item(itemName, itemPrice, itemCount);
    (this->itemList).push_back(item);
}
// 재고 업데이트
void Store::updateStock(int itemId, int count) {
    itemList[itemId]->setItemCount(count);
}
// 사용자가 선택한 아이템의 정보를 주는 함수
void Store::showItemList() {
    cout << "┌──────────────────────────────────────────────────────────────────────────┐" << endl;
    cout << "│" << setw(30) << " " << setw(44) << left << this->storeName << "│" << endl;
    cout << "├───┬────────────────────────────────────┬────────────────────┬────────────┤" << endl;
    cout << "│" << setw(3) << left << "NUM" << "│              " << setw(15) << left << "ITEM NAME" << setw(10) << right << "│" << "       " << setw(13) << left << "PRICE" << "│" << setw(4) << left << " " << setw(8) << left << "COUNT" << "│" << endl;
    for(int i = 0; i < (this->itemList).size(); i++) {
        cout << "├───┼────────────────────────────────────┼────────────────────┼────────────┤" << endl;
        cout << "│" << setw(3) << left << i + 1;
        (this->itemList[i])->showItemInfo();
    }
    cout << "└───┴────────────────────────────────────┴────────────────────┴────────────┘" << endl;
}
