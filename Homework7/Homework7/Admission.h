//
//  Admission.h
//  Homework7
//
//  Created by HeeCheol Kim on 01/11/2018.
//  Copyright © 2018 HeeCheol Kim. All rights reserved.
//

#pragma once

#include "Universe.h"

class Admission : public Universe {
public:
    Admission() {}
    virtual ~Admission() {}
    virtual void sortData() {
        for(int i = 0; i < STUDENT_CNT; i++) {
            for(int j = 0; j < STUDENT_CNT - i - 1; j++) {
                if(studentList[j].score < studentList[j + 1].score) {
                    Student temp = studentList[j];
                    studentList[j] = studentList[j + 1];
                    studentList[j + 1] = temp;
                }
            }
        }
    }
    virtual void writeData() {
        out.open("/Users/heecheolkim/XcodeProjects/cpp/Homework7/Homework7/addmission-student.data");
        initTableFormat();
        sortData();
        if(out.is_open()) {
            for(int i = 0; i < STUDENT_CNT; i++) {
                out << setw(10) << left << studentList[i].id;
                out << setw(20) << left << studentList[i].name;
                out << setw(10) << left << studentList[i].score << std::endl;
            }
        }
    }
    virtual void initTableFormat() {
        out << setw(17) << left << "수험번호";
        out << setw(15) << left << "이름";
        out << setw(10) << left << "입학성적" << std::endl;
    }
};
