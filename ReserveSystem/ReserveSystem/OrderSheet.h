//
//  OrderSheet.h
//  ReserveSystem
//
//  Created by HeeCheol Kim on 21/11/2018.
//  Copyright © 2018 HeeCheol Kim. All rights reserved.
//

#pragma once

#include "POS.h"

class OrderSheet : public POS {
public:
    virtual void purchase(ofstream *out, vector <OrderGroup> group);
};
