#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "Student.h"

#define WIDTH 14
#define MAX 20

using namespace std;
class Management {
public:
    Management() {
        cout << "학생정보 데이터를 읽어들입니다" << endl;
        in.open("student.data");
        if (in.fail()) {
            cout << "데이터를 읽어들이는데 실패했습니다" << endl;
            exit(0);
        }
    }
    ~Management() {
        cout << "-------------------------" << endl;
        cout << "파일출력이 완료되었습니다. 프로그램을 종료합니다" << endl;
        cout << "-------------------------" << endl;
        in.close();
    }
    string inputName();
    int inputId();
    double inputKor();
    double inputEng();
    double inputMath();
    double calcScore(double sub1, double sub2, double sub3);
    double calcAvrg(double sub1, double sub2, double sub3);
    void writeFile(Student student);
    void sortRank(Student student[]);
    void initTableFormat();
    ifstream in;
    ofstream out;
};
