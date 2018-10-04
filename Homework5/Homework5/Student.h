#pragma once
#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    Student() {}
    ~Student() {}
    void printInfo();
    string name;
    int id;
    double kor;
    double eng;
    double math;
    double sumScore;
    double avrg;
    int rank;
};
