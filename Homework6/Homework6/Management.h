#pragma once
#include <iostream>
#include <string>

#include "Student.h"
#include "FileSystem.h"

#define MAX 20

using namespace std;
class Management : public FileSystem {
public:
    Management() {}
    ~Management() {}
    double calcScore(double subject[], int subjectCount);
    double calcAvrg(double subject[], int subjectCount);
    void sortRank(Student student[]);
    void initSubject(Student student[], int subjectCount);
    int subjectCount;
};
