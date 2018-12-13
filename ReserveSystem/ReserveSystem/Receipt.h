//
//  Receipt.h
//  ReserveSystem
//
//  Created by HeeCheol Kim on 21/11/2018.
//  Copyright © 2018 HeeCheol Kim. All rights reserved.
//

#pragma once

#include "POS.h"

using namespace std;

class Receipt : public POS {
public:
    virtual void purchase(ofstream *out, vector <OrderGroup> group);
    inline void setDoDelivery(bool state) { this->doDelivery = state; }
    inline void clearDelivery() { this->doDelivery = false; }
private:
    bool doDelivery;
};

