//
//  OrderGroup.h
//  ReserveSystem
//
//  Created by HeeCheol Kim on 21/11/2018.
//  Copyright © 2018 HeeCheol Kim. All rights reserved.
//

#pragma once

#include <vector>
#include "VirtualItem.h"

using namespace std;

typedef struct OrderGroup {
    vector <VirtualItem*> groupedItem;
    int storeId;
    string storeName;
} OrderGroup;
