//
//  Time.h
//  ReserveSystem
//
//  Created by HeeCheol Kim on 21/11/2018.
//  Copyright © 2018 HeeCheol Kim. All rights reserved.
//

#pragma once

#include <ctime>

class Time {
public:
    char* getCurrentTimeYYMMDD();
    char* getCurrentTimeYYMMDDHHMMSS();
    char* getCurrentTimeBeautify();
    void setTimeInfo();
    
private:
    time_t rawtime;
    tm* timeInfo;
    char buffer[80];
};
