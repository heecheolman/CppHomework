//
//  Student.h
//  Homework7
//
//  Created by HeeCheol Kim on 01/11/2018.
//  Copyright © 2018 HeeCheol Kim. All rights reserved.
//

#pragma once

#include <iostream>
using namespace std;

class Student {
public:
    Student();
    void showInfo();    
    int id;
    string name;
    string school;
    double score;
};
