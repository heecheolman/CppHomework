//
//  Student.cpp
//  Homework7
//
//  Created by HeeCheol Kim on 01/11/2018.
//  Copyright © 2018 HeeCheol Kim. All rights reserved.
//

#include "Student.h"

Student::Student() {
    this->id = 0;
    this->name = "";
    this->school = "";
    this->score = 0;
}
void Student::showInfo() {
    cout << "학번 : " << this->id << endl;
    cout << "이름 : " << this->name << endl;
    cout << "출신학교 : " << this->school << endl;
    cout << "점수 : " << this->score << endl;
}
