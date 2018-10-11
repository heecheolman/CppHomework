//
//  main.cpp
//  Homework5
//
//  Created by HeeCheol Kim on 2018. 10. 12..
//  Copyright © 2018년 HeeCheol Kim. All rights reserved.
//

#include <iostream>
#include <string>
#include "Student.h"
#include "Management.h"

int main(void) {
    Management manage;
    Student * student = new Student[MAX];
    manage.setReadFilename("/Users/heecheolkim/XcodeProjects/cpp/Homework6/Homework6/student.data");
    manage.setWriteFilename("/Users/heecheolkim/XcodeProjects/cpp/Homework6/Homework6/student_result.data");
    manage.subjectCount = manage.getSubjectCount();
    manage.initSubject(student, manage.subjectCount);
    manage.applyReadFile(student, manage.subjectCount);
    manage.sortRank(student);
    manage.applyWriteFile();
    manage.initTableFormat(manage.subjectCount);
    manage.writeData(student, manage.subjectCount);
    student->clearData();
    delete[] student;
    student = nullptr;
    return 0;
}
