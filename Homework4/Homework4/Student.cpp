#include "Student.h"

void Student::printInfo() {
    cout << "----------학생정보----------" << endl;
    cout << "이름 : " << name << endl;
    cout << "학번 : " << id << endl;
    cout << "국어점수 : " << kor << endl;
    cout << "영어점수 : " << eng << endl;
    cout << "수학점수 : " << math << endl;
    cout << "총점 : " << sumScore << endl;
    cout << "평균 : " << avrg << endl;
    cout << "등수 : " << rank << endl;
    cout << "-------------------------" << endl;
}
