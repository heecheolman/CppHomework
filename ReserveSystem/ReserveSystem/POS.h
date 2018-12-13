//
//  POS.h
//  ReserveSystem
//
//  Created by HeeCheol Kim on 21/11/2018.
//  Copyright © 2018 HeeCheol Kim. All rights reserved.
//

#pragma once

#include <fstream>
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <iostream>
#include <vector>
#include <iomanip>

#include "OrderGroup.h"
#include "Time.h"
#include "PathDef.h"

using namespace std;

class POS {
public:
    virtual void purchase(ofstream *out, vector <OrderGroup> group) = 0;
protected:
    Time t;
    ofstream fileout;
};
