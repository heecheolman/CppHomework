//
//  MinistryEducation.h
//  Homework7
//
//  Created by HeeCheol Kim on 01/11/2018.
//  Copyright © 2018 HeeCheol Kim. All rights reserved.
//

#pragma once
#include "Universe.h"

class MinistryEducation : public Universe {
public:
    MinistryEducation() {
        
    }
    virtual ~MinistryEducation() {}
    virtual void writeData() {
        out.open("/Users/heecheolkim/XcodeProjects/cpp/Homework7/Homework7/minisEdu-student.data");
        initTableFormat();
        sort(studentList.begin(), studentList.end(), compareScore);
        if(out.is_open()) {
            for(int i = 0; i < studentList.size(); i++) {
                out << setw(10) << left << studentList[i]->id;
                out << setw(20) << left << studentList[i]->name;
                out << setw(10) << left << studentList[i]->score << std::endl;
            }
        }
        out.close();
        out.open("/Users/heecheolkim/XcodeProjects/cpp/Homework7/Homework7/minisEdu-student-sort.data");
        sort(studentList.begin(), studentList.end(), compareId);
        initTableFormat();
        if(out.is_open()) {
            for(int i = 0; i < studentList.size(); i++) {
                out << setw(10) << left << studentList[i]->id;
                out << setw(20) << left << studentList[i]->name;
                out << setw(10) << left << studentList[i]->score << std::endl;
            }
        }
        out.close();
    }
    virtual void initTableFormat() {
        out << setw(17) << left << "수험번호";
        out << setw(16) << left << "이름";
        out << setw(10) << left << "입학성적" << std::endl;
    }
};
