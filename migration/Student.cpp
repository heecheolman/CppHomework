#include "Student.h"

Student::Student() {
    this->id = 0;
    this->name = "";
    this->school = "";
    this->score = 0;
}
void Student::showInfo() {
    cout << "�й� : " << this->id << endl;
    cout << "�̸� : " << this->name << endl;
    cout << "����б� : " << this->school << endl;
    cout << "���� : " << this->score << endl;
}
