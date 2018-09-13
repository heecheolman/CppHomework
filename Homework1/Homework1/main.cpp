//
//  main.cpp
//  TestCpp
//
//  Created by HeeCheol Kim on 2018. 9. 6..
//  Copyright © 2018년 HeeCheol Kim. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Management {
public:
    string inputName() {
        string name;
        cout << "이름을 입력하세요 >> ";
        cin >> name;
        return name;
    }
    int inputId() {
        int id;
        cout << "학번을 입력하세요 >> ";
        cin  >> id;
        return id;
    }
    double inputKor() {
        int score;
        cout << "국어점수 입력 >> ";
        cin >> score;
        return score;
    }
    double inputEng() {
        int score;
        cout << "영어점수 입력 >> ";
        cin >> score;
        return score;
    }
    double inputMath() {
        int score;
        cout << "수학점수 입력 >> ";
        cin >> score;
        return score;
    }
    double calcScore(double sub1, double sub2, double sub3) {
        return sub1 + sub2 + sub3;
    }
    double calcAvrg(double sub1, double sub2, double sub3) {
        return (sub1 + sub2 + sub3) / 3.0;
    }
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
    Student student[1];
    
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
