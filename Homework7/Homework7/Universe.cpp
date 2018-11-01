//
//  Universe.cpp
//  Homework7
//
//  Created by HeeCheol Kim on 01/11/2018.
//  Copyright © 2018 HeeCheol Kim. All rights reserved.
//

#include "Universe.h"

Universe::Universe() {
    studentList = new Student[STUDENT_CNT];
    setStudentData();
}
void Universe::setStudentData() {
    in.open("/Users/heecheolkim/XcodeProjects/cpp/Homework7/Homework7/midtest.txt");
    if(in.is_open()) {
        for(int i = 0; i < STUDENT_CNT; i++) {
            in >> studentList[i].id;
            in >> studentList[i].name;
            in >> studentList[i].school;
            in >> studentList[i].score;
            studentList[i].showInfo();
        }
    }
}
