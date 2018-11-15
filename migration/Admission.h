#pragma once

#include "Universe.h"

class Admission : public Universe {
public:
    Admission() {}
    virtual ~Admission() {}
    virtual void writeData() {
        out.open("addmission-student.data");
        initTableFormat();
        sort(studentList.begin(), studentList.end(), compareSchool);
        if(out.is_open()) {
            for(int i = 0; i < studentList.size(); i++) {
                out << setw(10) << left << studentList[i]->id;
                out << setw(20) << left << studentList[i]->name;
                out << setw(10) << left << studentList[i]->school << std::endl;
            }
        }
        out.close();
        out.open("addmission-student-sort.data");
        initTableFormat();
        sort(studentList.begin(), studentList.end(), compareId);
        if(out.is_open()) {
            for(int i = 0; i < studentList.size(); i++) {
                out << setw(10) << left << studentList[i]->id;
                out << setw(20) << left << studentList[i]->name;
                out << setw(10) << left << studentList[i]->school << std::endl;
            }
        }
        out.close();
    }
    virtual void initTableFormat() {
        out << setw(17) << left << "수험번호";
        out << setw(20) << left << "이름";
        out << setw(10) << left << "출신학교" << std::endl;
    }
};
