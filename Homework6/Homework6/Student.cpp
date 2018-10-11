#include "Student.h"

void Student::initSubjectList(int subjectCount) {
    this->subject = new double[subjectCount];
    for(int i = 0; i < subjectCount; i++) {
        this->subject[i] = 0;
    }
}
void Student::printInfo(int subjectCount) {
    cout << "----------학생정보----------" << endl;
    cout << "이름 : " << name << endl;
    cout << "학번 : " << id << endl;
    for(int i = 0; i < subjectCount; i++) {
        std::cout << "과목" << i + 1 << " : " << subject[i] << std::endl;
    }
    cout << "총점 : " << sumScore << endl;
    cout << "평균 : " << avrg << endl;
    cout << "등수 : " << rank << endl;
    cout << "-------------------------" << endl;
}
void Student::clearData() {
    delete[] subject;
    subject = nullptr;
}
