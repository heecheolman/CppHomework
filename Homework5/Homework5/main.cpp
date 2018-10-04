//
//  main.cpp
//  Homework5
//
//  Created by HeeCheol Kim on 2018. 10. 4..
//  Copyright © 2018년 HeeCheol Kim. All rights reserved.
//

#include <iostream>
#include <string>
#include "Student.h"
#include "Management.h"

int main(void) {
    Management manage;
    Student student[MAX];
    manage.setReadFilename("/Users/heecheolkim/XcodeProjects/cpp/Homework5/Homework5/student.data");
    manage.setWriteFilename("/Users/heecheolkim/XcodeProjects/cpp/Homework5/Homework5/student_result.data");
    manage.applyReadFile();
    
    for (int i = 0; i < sizeof(student) / sizeof(Student); i++) {
        cout << i + 1 << "번째 학생 데이터 입력" << endl;
        student[i].name = manage.inputName();
        student[i].id = manage.inputId();
        student[i].kor = manage.inputKor();
        student[i].eng = manage.inputEng();
        student[i].math = manage.inputMath();
        student[i].sumScore = manage.calcScore(student[i].kor, student[i].eng, student[i].math);
        student[i].avrg = manage.calcAvrg(student[i].kor, student[i].eng, student[i].math);
    }
    manage.sortRank(student);
    manage.applyWriteFile();
    manage.initTableFormat();
    for (int i = 0; i < MAX; i++) {
        manage.writeData(student[i]);
        student[i].printInfo();
    }
    
    return 0;
}
