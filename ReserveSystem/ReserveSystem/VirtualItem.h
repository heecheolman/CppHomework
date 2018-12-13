//
//  VirtualItem.h
//  ReserveSystem
//
//  Created by HeeCheol Kim on 21/11/2018.
//  Copyright © 2018 HeeCheol Kim. All rights reserved.
//

#pragma once

#include <string>

using namespace std;

// 가상아이템 구조체
typedef struct VirtualItem {
    int storeId;
    string storeName;
    string itemName;
    int itemPrice;
    int itemCount;
} VirtualItem;
