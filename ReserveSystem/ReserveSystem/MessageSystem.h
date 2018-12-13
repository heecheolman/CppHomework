//
//  MessageSystem.h
//  ReserveSystem
//
//  Created by HeeCheol Kim on 27/11/2018.
//  Copyright © 2018 HeeCheol Kim. All rights reserved.
//

#pragma once

#include <iostream>
using namespace std;

class MessageSystem {
public:
    static void selectStoreMessage() {
        cout << "@ SELECT STORE @" << endl;
        cout << "   └ ORDER - 0" << endl;
    }
    static void selectMessage(int type) {
        switch(type) {
            case 1:
                cout << "@@@   SELECT ITEM   @@@" << endl;
                break;
            case 2:
                cout << "@@@   SELECT COUNT   @@@" << endl;
                break;
        }
    }
    static bool willDelivery() {
        int select = 0;
        cout << "USE DELIVERY SERVICE ? _______ + 2500won" << endl;
        do {
            cout << "1. OK" << endl;
            cout << "2. NO" << endl;
            cin >> select;
        } while(!(select == 1 || select == 2));
        return select == 1;
    }
    static bool willPayment() {
        int select = 0;
        cout << "WOULD YOU LIKE TO PAY ?" << endl;
        do {
            cout << "1. OK" << endl;
            cout << "2. NO" << endl;
            cin >> select;
        } while(!(select == 1|| select == 2));
        return select == 1;
    }
};
