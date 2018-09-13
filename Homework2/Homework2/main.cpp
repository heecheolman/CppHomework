//
//  main.cpp
//  TestCpp
//
//  Created by HeeCheol Kim on 2018. 9. 6..
//  Copyright © 2018년 HeeCheol Kim. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Management {
public:
    Management() {
        cout << "학생정보 데이터를 읽어들입니다" << endl;
        in.open("/Users/heecheolkim/XcodeProjects/cpp/Homework2/Homework2/student.data");
        if(in.fail()) {
            cout << "데이터를 읽어들이는데 실패했습니다" << endl;
        }
    }
    ~Management() {
        in.close();
    }
    string inputName() {
        string name;
        in >> name;
        return name;
    }
    int inputId() {
        int id;
        in  >> id;
        return id;
    }
    double inputKor() {
        int score;
        in >> score;
        return score;
    }
    double inputEng() {
        int score;
        in >> score;
        return score;
    }
    double inputMath() {
        int score;
        in >> score;
        return score;
    }
    double calcScore(double sub1, double sub2, double sub3) {
        return sub1 + sub2 + sub3;
    }
    double calcAvrg(double sub1, double sub2, double sub3) {
        return (sub1 + sub2 + sub3) / 3.0;
    }
    ifstream in;
};

class Student {
public:
    void printInfo() {
        cout << "----------학생정보----------" << endl;
        cout << "이름 : " << name << endl;
        cout << "학번 : " << id << endl;
        cout << "국어점수 : " << kor << endl;
        cout << "영어점수 : " << eng << endl;
        cout << "수학점수 : " << math << endl;
        cout << "총점 : " << sumScore << endl;
        cout << "평균 : " << avrg << endl;
        cout << "-------------------------" << endl;
    }
    
    string name;
    int id;
    double kor;
    double eng;
    double math;
    double sumScore;
    double avrg;
};

int main(void) {
    Management manage;
    Student student[20];
    
    for(int i = 0; i < sizeof(student) / sizeof(Student); i++) {
        cout << i + 1 << "번째 학생 정보와 점수 입력" << endl;
        student[i].name = manage.inputName();
        student[i].id = manage.inputId();
        student[i].kor = manage.inputKor();
        student[i].eng = manage.inputEng();
        student[i].math = manage.inputMath();
        student[i].sumScore = manage.calcScore(student[i].kor, student[i].eng, student[i].math);
        student[i].avrg = manage.calcAvrg(student[i].kor, student[i].eng, student[i].math);
        student[i].printInfo();
    }
    cout << "-------------------------" << endl;
    cout << "학생정보를 전부 출력합니다" << endl;
    cout << "-------------------------" << endl;
    for(int i = 0; i < sizeof(student) / sizeof(Student); i++) {
        student[i].printInfo();
    }
    cout << "-------------------------" << endl;
    cout << "출력이 완료되었습니다. 프로그램을 종료합니다" << endl;
    cout << "-------------------------" << endl;
    
    return 0;
}
