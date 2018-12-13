//
//  OrderSheet.cpp
//  ReserveSystem
//
//  Created by HeeCheol Kim on 27/11/2018.
//  Copyright © 2018 HeeCheol Kim. All rights reserved.
//

#include "OrderSheet.h"

// 주문서 발행
void OrderSheet::purchase(ofstream *out, vector <OrderGroup> group) {
    string CURRENT_DATE = t.getCurrentTimeYYMMDD();
    for(int i = 0; i < group.size(); i++) {
        int storeTotalRevenue = 0;
        OrderGroup groupEle = group[i];
        string STORE_ID = to_string(groupEle.storeId + 1);
        STORE_ID = STORE_ID.length() == 1 ? "0" + STORE_ID : STORE_ID;
        string ORDER_SHEET_PATH = DEFAULT_PATH + "/" + STORE_LIST_DIR + "/" + "store" + STORE_ID + "/" + ORDER_LIST_DIR + "/" + CURRENT_DATE;
        string REVENUE_PATH = DEFAULT_PATH + "/" + STORE_LIST_DIR + "/" + "store" + STORE_ID + "/" + REVENUE_DIR + "/" + CURRENT_DATE;
        
        const char *CHAR_ORDER_SHEET_PATH = ORDER_SHEET_PATH.c_str();
        const char *CHAR_REVENUE_PATH = REVENUE_PATH.c_str();
        
        int mkdirOrderState = mkdir(CHAR_ORDER_SHEET_PATH, 0777);
        
        // 주문서생성
        if(mkdirOrderState == 0 || errno == EEXIST) {
            t.setTimeInfo();
            string ORDER_FILE = (string)t.getCurrentTimeYYMMDDHHMMSS();
            string FORMAT_TIME = (string)t.getCurrentTimeBeautify();
            
            out->open(ORDER_SHEET_PATH + "/" + ORDER_FILE);
            if(out->is_open()) {
                *out << "────────────────────────────────────────────────" << endl;
                *out << "ORDER SHEET                  " << FORMAT_TIME << endl;
                *out << "────────────────────────────────────────────────" << endl;
                *out << endl;
                *out << "@ " << groupEle.storeName << " @" << endl;
            } else {
                cout << "############### ERROR :: FILE EXPORT" << endl;
            }
            out->close();
            for(int j = 0; j < groupEle.groupedItem.size(); j++) {
                string FULLPATH = ORDER_SHEET_PATH + "/" + ORDER_FILE;
                out->open(FULLPATH, ios_base::app);
                if(out->is_open()) {
                    *out << "  └ " << setw(22) << left << groupEle.groupedItem[j]->itemName;
                    *out << setw(9) << left << groupEle.groupedItem[j]->itemPrice;
                    *out << setw(4) << left << groupEle.groupedItem[j]->itemCount;
                    *out << setw(9) <<  right << groupEle.groupedItem[j]->itemPrice * groupEle.groupedItem[j]->itemCount << endl;
                    storeTotalRevenue += groupEle.groupedItem[j]->itemPrice * groupEle.groupedItem[j]->itemCount;
                } else {
                    cout << "############### ERROR :: FILE EXPORT" << endl;
                }
                out->close();
            }
            out->open(ORDER_SHEET_PATH + "/" + ORDER_FILE, ios_base::app);
            if(out->is_open()) {
                *out << endl << "- - - - - - - - - - - - - - - - - - - - - - - - " << endl;
                *out << setw(40) << left << "TOTAL PRICE" << setw(8) << right << storeTotalRevenue << endl;
                *out << "────────────────────────────────────────────────" << endl;
            }
            out->close();
        } else {
            cout << "############### ERROR :: MKDIR_ERROR" << endl;
        }
        
        int mkdirRevenueState = mkdir(CHAR_REVENUE_PATH, 0777);
        
        if(mkdirRevenueState == 0) {
            string REVENUE_FILE = CURRENT_DATE + ".data";
            string FULLPATH = REVENUE_PATH + "/" + REVENUE_FILE;
            out->open(FULLPATH);
            if(out->is_open()) {
                *out << storeTotalRevenue;
            } else {
                cout << "############### ERROR :: FILE EXPORT" << endl;
            }
            out->close();
        } else if(errno == EEXIST) {
            int readedRevenue = 0;
            string REVENUE_FILE = CURRENT_DATE + ".data";
            string FULLPATH = REVENUE_PATH + "/" + REVENUE_FILE;
            ifstream in;
            in.open(FULLPATH);
            if(in.is_open()) {
                in >> readedRevenue;
            } else {
                cout << "############### ERROR :: FILE IMPORT" << endl;
            }
            in.close();
            storeTotalRevenue += readedRevenue;
            out->open(FULLPATH);
            if(out->is_open()) {
                *out << storeTotalRevenue;
            }
            out->close();
        }
        
        usleep(1000000);
    }
    }
