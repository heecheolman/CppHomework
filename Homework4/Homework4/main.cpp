//
//  main.cpp
//  TestCpp
//
//  Created by HeeCheol Kim on 2018. 9. 6..
//  Copyright © 2018년 HeeCheol Kim. All rights reserved.
//

#include <iostream>
#include <string>
#include "Student.h"
#include "Management.h"

int main(void) {
    Management manage;
    Student student[MAX];
    
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
    manage.initTableFormat();
    for (int i = 0; i < MAX; i++) {
        manage.writeFile(student[i]);
        student[i].printInfo();
    }
    
    return 0;
}
