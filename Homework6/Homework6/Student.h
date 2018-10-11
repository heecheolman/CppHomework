//
//  Student.h
//  Homework6
//
//  Created by HeeCheol Kim on 2018. 10. 12..
//  Copyright © 2018년 HeeCheol Kim. All rights reserved.
//
#pragma once
#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    Student() {}
    ~Student() {}
    void printInfo(int subjectCount);
    void initSubjectList(int subjectCount);
    void clearData();
    string name;
    int id;
    double * subject;
    double sumScore;
    double avrg;
    int rank;
};
