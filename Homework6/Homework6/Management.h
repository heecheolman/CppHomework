//
//  Management.h
//  Homework6
//
//  Created by HeeCheol Kim on 2018. 10. 12..
//  Copyright © 2018년 HeeCheol Kim. All rights reserved.
//
#pragma once
#include <iostream>
#include <string>

#include "FileSystem.h"

#define MAX 20

using namespace std;
class Management : public FileSystem {
public:
    Management() {}
    ~Management() {}
    double calcScore(double subject[], int subjectCount);
    double calcAvrg(double subject[], int subjectCount);
    void sortRank(Student student[]);
    void initSubject(Student student[], int subjectCount);
    int subjectCount;
};
