//
//  Management.cpp
//  Homework6
//
//  Created by HeeCheol Kim on 2018. 10. 12..
//  Copyright © 2018년 HeeCheol Kim. All rights reserved.
//
#include "Management.h"

double Management::calcScore(double subject[], int subjectCount) {
    double sumScore = 0;
    for(int i = 0; i < subjectCount; i++) {
        sumScore += subject[i];
    }
    return sumScore;
}
double Management::calcAvrg(double subject[], int subjectCount) {
    double sumScore = 0;
    for(int i = 0; i < subjectCount; i++) {
        sumScore += subject[i];
    }
    return sumScore / this->subjectCount;
}
void Management::sortRank(Student student[]) {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX - i - 1; j++) {
            if (student[j].sumScore < student[j + 1].sumScore) {
                Student temp = student[j];
                student[j] = student[j + 1];
                student[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < MAX; i++) {
        student[i].rank = i + 1;
    }
}
void Management::initSubject(Student student[], int subjectCount) {
    for(int i = 0; i < MAX; i++) {
        student[i].initSubjectList(subjectCount);
    }
}
