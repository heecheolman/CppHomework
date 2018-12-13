//
//  MiddleMan.cpp
//  ReserveSystem
//
//  Created by HeeCheol Kim on 27/11/2018.
//  Copyright © 2018 HeeCheol Kim. All rights reserved.
//

#include "MiddleMan.h"

MiddleMan::MiddleMan () {
    this->defaultPath = DEFAULT_PATH;
    this->shoppingBasket = new ShoppingBasket();
}

// 상품 초기 등록
void MiddleMan::registStoreList() {
    string STORE_LIST_PATH = this->defaultPath + "/" + STORE_LIST_DIR;
    const char *CHAR_STORE_LIST_PATH = STORE_LIST_PATH.c_str();
    dir = opendir(CHAR_STORE_LIST_PATH);
    int storeId = 0;
    if(dir) {
        while((ent = readdir(dir))) {
            string STORE_DIR;
            STORE_DIR = ent->d_name;
            if(STORE_DIR.length() >= 7) {
                string storeDataPath = STORE_LIST_PATH + "/" + STORE_DIR + "/" + STORE_DATA;
                in.open(storeDataPath);
                if(in.is_open()) {
                    string storeName;
                    string storeRobot;
                    getline(in, storeName);
                    getline(in, storeRobot);
                    storeId++;
                    Store *store = new Store(STORE_DIR, storeName, storeRobot, storeId);
                    (this->storeList).push_back(store);
                    ifstream datain;
                    datain.open(STORE_LIST_PATH + "/" + STORE_DIR + "/" + STORE_ITEM_DATA);
                
                    while(!datain.eof()) {
                        string itemName;
                        int itemPrice;
                        int itemCount;
                        datain >> itemName;
                        datain >> itemPrice;
                        datain >> itemCount;
                        if(itemName.length()) {
                            store->addItemFromList(itemName, itemPrice, itemCount);
                        }
                    }
                    datain.close();
                }
                in.close();
            }
        }
        closedir(dir);
    } else {
        cout << "READING FILE FAIL" << endl;
        exit(1);
    }
}

// 상점리스트들을 보여줌
void MiddleMan::showStoreList() {
    
    cout << "┌───┬─────────────────────────────┬──────────────────────────────────────────────────┐" << endl;
    cout << "│" << setw(3) << left << "NUM" << "│          " << setw(15) << left << "STORE NAME" << setw(7) << right << "│" << "                     DESCRIPTION                  │" << endl;
    for(int i = 0; i < storeList.size(); i++) {
        cout << "├───┼─────────────────────────────┼──────────────────────────────────────────────────┤" << endl;
        Store *target = storeList[i];
        target->showStoreInfo();
    }
    cout << "└───┴─────────────────────────────┴──────────────────────────────────────────────────┘" << endl;
}

// 장바구니
void MiddleMan::groupingBasket() {
    bool hasStoreId;
    for(int i = 0; i < this->shoppingBasket->basketList.size(); i++) {
        hasStoreId = false;
        VirtualItem *vi = this->shoppingBasket->basketList[i];
        for(int j = 0; j < group.size(); j++) {
            if(group[j].storeId == vi->storeId) {
                group[j].groupedItem.push_back(vi);
                hasStoreId = true;
                break;
            }
        }
        if(!hasStoreId) {
            OrderGroup og;
            og.storeId = vi->storeId;
            og.storeName = vi->storeName;
            og.groupedItem.push_back(vi);
            group.push_back(og);
        }
    }
}

// 주문서 발행
void MiddleMan::makeOutOrderSheet() {
    os.purchase(&out, group);
}

// 영수증 발행
void MiddleMan::makeOutReceipt() {
    r.setDoDelivery(this->shoppingBasket->getDeliveryState());
    r.purchase(&out, group);
    r.clearDelivery();
}

// 장바구니에 추가
void MiddleMan::putItemToBasket(int storeId, string storeName, string itemName, int itemCount, int itemPrice) {
    shoppingBasket->addItemToBasket(storeId, storeName, itemName, itemCount, itemPrice);
    cout << endl << "@@@ " << itemName << " +" << itemCount << endl << endl;
}

// 장바구니 초기화
void MiddleMan::clearBasketData() {
    this->shoppingBasket->clearBasket();
    this->group.erase(group.begin(), group.end());
}
