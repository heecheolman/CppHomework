//
//  Receipt.cpp
//  ReserveSystem
//
//  Created by HeeCheol Kim on 27/11/2018.
//  Copyright © 2018 HeeCheol Kim. All rights reserved.
//

#include "Receipt.h"


// 영수증 발행 과정
void Receipt::purchase(ofstream *out, vector <OrderGroup> group) {
    int totalPrice = 0;
    string CONSUMER_PATH = DEFAULT_PATH + "/" + CONSUMER_DIR;
    string CURRENT_DATE = t.getCurrentTimeYYMMDD();
    CONSUMER_PATH = CONSUMER_PATH + "/" + CURRENT_DATE;
    const char *CHAR_CONSUMER_PATH = CONSUMER_PATH.c_str();
    int mkdirState = mkdir(CHAR_CONSUMER_PATH, 0777);
    t.setTimeInfo();
    string CURRENT_TIME = (string)t.getCurrentTimeYYMMDDHHMMSS();
    string FORMAT_TIME = (string)t.getCurrentTimeBeautify();
    CONSUMER_PATH = CONSUMER_PATH + "/" + CURRENT_TIME;
    out->open(CONSUMER_PATH);
    if(mkdirState == 0 || errno == EEXIST) {
        *out << "────────────────────────────────────────────────" << endl;
        *out << "RECEIPT                      " << FORMAT_TIME << endl;
        *out << "────────────────────────────────────────────────" << endl;
        if(out->is_open()) {
            for(int i = 0; i < group.size(); i++) {
                OrderGroup og = group[i];
                *out << endl;
                *out << "@ " << og.storeName << " @" << endl;
                for(int j = 0; j < og.groupedItem.size(); j++) {
                    *out << "  └ " << setw(22) << left << og.groupedItem[j]->itemName;
                    *out << setw(9) << left << og.groupedItem[j]->itemPrice;
                    *out << setw(4) << left << og.groupedItem[j]->itemCount;
                    *out << setw(9) <<  right << og.groupedItem[j]->itemPrice * og.groupedItem[j]->itemCount << endl;
                    totalPrice += og.groupedItem[j]->itemPrice * og.groupedItem[j]->itemCount;
                }
                *out << endl;
                *out << "- - - - - - - - - - - - - - - - - - - - - - - - " << endl;
            }
            if(this->doDelivery) {
                totalPrice += 2500;
                *out << setw(40) << left << "DELIVERY CHARGE" << setw(8) << right << "2500" << endl;
            }
            *out << "- - - - - - - - - - - - - - - - - - - - - - - - " << endl;
            *out << setw(40) << left << "TOTAL PRICE" << setw(8) << right << totalPrice << endl;
            *out << "────────────────────────────────────────────────" << endl;
        } else {
            cout << "############### ERROR :: FILE EXPORT" << endl;
        }
    } else {
        cout << "############### ERROR :: MKDIR_ERROR" << endl;
    }
    out->close();
}

