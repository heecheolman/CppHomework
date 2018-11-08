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
                if(studentList[j].school > studentList[j + 1].school) {
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
                out << setw(10) << left << studentList[i].school << std::endl;
            }
        }
        out.close();
        out.open("/Users/heecheolkim/XcodeProjects/cpp/Homework7/Homework7/addmission-student-sort.data");
        initTableFormat();
        sortId();
        if(out.is_open()) {
            for(int i = 0; i < STUDENT_CNT; i++) {
                out << setw(10) << left << studentList[i].id;
                out << setw(20) << left << studentList[i].name;
                out << setw(10) << left << studentList[i].school << std::endl;
            }
        }
        out.close();
    }
    virtual void sortId() {
        for(int i = 0; i < STUDENT_CNT; i++) {
            for(int j = 0; j < STUDENT_CNT - i - 1; j++) {
                if(studentList[j].id > studentList[j + 1].id) {
                    Student temp = studentList[j];
                    studentList[j] = studentList[j + 1];
                    studentList[j + 1] = temp;
                }
            }
        }
    }
    virtual void initTableFormat() {
        out << setw(17) << left << "수험번호";
        out << setw(20) << left << "이름";
        out << setw(10) << left << "출신학교" << std::endl;
    }
};
