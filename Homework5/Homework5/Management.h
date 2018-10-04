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
    string inputName();
    int inputId();
    double inputKor();
    double inputEng();
    double inputMath();
    double calcScore(double sub1, double sub2, double sub3);
    double calcAvrg(double sub1, double sub2, double sub3);
    void sortRank(Student student[]);
};
