//
//  Universe.h
//  Homework7
//
//  Created by HeeCheol Kim on 01/11/2018.
//  Copyright © 2018 HeeCheol Kim. All rights reserved.
//

#pragma once

#include <fstream>
#include <iomanip>
#include <string>
#include "Student.h"
#define STUDENT_CNT 10

class Universe {
public:
    Universe();
    virtual ~Universe() {};
    void setStudentData();
    virtual void writeData(){};
    virtual void initTableFormat(){};
    virtual void sortId() = 0;
    virtual void printStudentData() {
        for(int i = 0; i < STUDENT_CNT; i++) {
            studentList[i].showInfo();
        }
    }
    virtual void sortData(){};
    Student * studentList;
    ifstream in;
    ofstream out;
};
