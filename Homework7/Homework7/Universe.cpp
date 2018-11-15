//
//  Universe.cpp
//  Homework7
//
//  Created by HeeCheol Kim on 01/11/2018.
//  Copyright © 2018 HeeCheol Kim. All rights reserved.
//

#include "Universe.h"

Universe::Universe() {
    setStudentData();
}
void Universe::setStudentData() {
    in.open("/Users/heecheolkim/XcodeProjects/cpp/Homework7/Homework7/midtest.txt");
    if(in.is_open()) {
        for(int i = 0; i < 10; i++) {
            Student *st = new Student();
            in >> st->id;
            in >> st->name;
            in >> st->school;
            in >> st->score;
            st->showInfo();
            studentList.push_back(st);
        }
    }
}
