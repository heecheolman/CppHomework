#pragma once
#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    Student() {}
    ~Student() {}
    void printInfo(int subjectCount);
    void initSubjectList(int subjectCount);
    void clearData();
    string name;
    int id;
    double * subject;
    double sumScore;
    double avrg;
    int rank;
};
