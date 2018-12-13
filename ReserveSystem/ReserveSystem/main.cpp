//
//  main.cpp
//  ReserveSystem
//
//  Created by HeeCheol Kim on 13/11/2018.
//  Copyright © 2018 HeeCheol Kim. All rights reserved.
//

#include "main.h"

int main(void) {
    MiddleMan * md = new MiddleMan();
    md->registStoreList();
    int menu;
    cout << endl;
    do {
        MessageSystem().selectStoreMessage();
        md->showStoreList();
        cin >> menu;
        if(0 < menu && menu <= md->storeList.size()) {
            int storeId = menu - 1;
            Store *selectedStore = md->storeList[storeId];
            int selectItem;
            do {
                selectedStore->showItemList();
                MessageSystem().selectMessage(1);
                cin >> selectItem;
                if(0 < selectItem && selectItem <= selectedStore->itemList.size()) {
                    Item *selectedItem = selectedStore->getSelectedItem(selectItem - 1);
                    int itemCount;
                    MessageSystem().selectMessage(2);
                    cin >> itemCount;
                    if(0 < itemCount && itemCount <= selectedItem->getItemCount()) {
                        md->putItemToBasket(storeId, md->storeList[storeId]->getStoreName(), selectedItem->getItemName(), itemCount, selectedItem->getItemPrice());
                        selectedStore->updateStock(selectItem - 1, itemCount);
                        md->shoppingBasket->showBasketItemList();
                    } else {
                        cout << "############### ERROR :: VALID EXCEPTION" << endl;
                    }
                } else if(selectItem != -1){
                    cout << "############### ERROR :: VALID EXCEPTION" << endl;
                }
            } while(selectItem != -1);
        } else if(menu == 0) {
            if(md->shoppingBasket->basketList.size() > 0) {
                md->shoppingBasket->setDeliveryState(MessageSystem().willDelivery());
                md->shoppingBasket->calcTotalItemPrice();
                cout << endl << "TOTAL PRICE __________    " << md->shoppingBasket->getTotalPrice() << endl;
                bool isPayment = MessageSystem().willPayment();
                if(isPayment) {
                    getchar();
                    md->groupingBasket();
                    md->makeOutOrderSheet();
                    md->makeOutReceipt();
                } else {
                    cout << ":::::::::  CANCEL  CHECK  :::::::::" << endl;
                }
            } else {
                cout << "::::::::: NO ITEM IN SHOPPING BASKET  :::::::::" << endl;
            }
            md->clearBasketData();
        }
    } while(menu != -1);
    return 0;
}
