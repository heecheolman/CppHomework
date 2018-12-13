//
//  Time.cpp
//  ReserveSystem
//
//  Created by HeeCheol Kim on 27/11/2018.
//  Copyright © 2018 HeeCheol Kim. All rights reserved.
//

#include "Time.h"

char* Time::getCurrentTimeYYMMDD() {
    time(&(this->rawtime));
    this->timeInfo = localtime(&(this->rawtime));
    strftime(this->buffer, 80, "%Y%m%d", this->timeInfo);
    return buffer;
}
char* Time::getCurrentTimeYYMMDDHHMMSS() {
    strftime(this->buffer, 80, "%Y%m%d%H%M%S", this->timeInfo);
    return buffer;
}
char* Time::getCurrentTimeBeautify() {
    strftime(this->buffer, 80, "%Y-%m-%d %H:%M:%S", this->timeInfo);
    return buffer;
}
void Time::setTimeInfo() {
    time(&(this->rawtime));
    this->timeInfo = localtime(&(this->rawtime));
}
