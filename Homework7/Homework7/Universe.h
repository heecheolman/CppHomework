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
#include <vector>
#include "Student.h"

class Universe {
public:
    Universe();
    virtual ~Universe() {};
    void setStudentData();
    virtual void writeData(){};
    virtual void initTableFormat() = 0;
    virtual void printStudentData() {
        for(int i = 0; i < studentList.size(); i++) {
            studentList[i]->showInfo();
        }
    }
    static bool compareSchool(Student *s1, Student *s2) {
        return s1->school < s2->school;
    }
    static bool compareId(Student *s1, Student *s2) {
        return s1->id < s2->id;
    }
    static bool compareScore(Student *s1, Student *s2) {
        return s1->score > s2->score;
    }
    vector <Student*> studentList;
    ifstream in;
    ofstream out;
};
