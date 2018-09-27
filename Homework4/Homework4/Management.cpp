#include "Management.h"

string Management::inputName() {
    string name;
    in >> name;
    return name;
}
int Management::inputId() {
    int id;
    in >> id;
    return id;
}
double Management::inputKor() {
    int score;
    in >> score;
    return score;
}
double Management::inputEng() {
    int score;
    in >> score;
    return score;
}
double Management::inputMath() {
    int score;
    in >> score;
    return score;
}
double Management::calcScore(double sub1, double sub2, double sub3) {
    return sub1 + sub2 + sub3;
}
double Management::calcAvrg(double sub1, double sub2, double sub3) {
    return (sub1 + sub2 + sub3) / 3.0;
}
void Management::writeFile(Student student) {
    if (out.is_open()) {
        out << setw(WIDTH) << left << student.rank;
        out << setw(WIDTH) << left << student.name;
        out << setw(WIDTH) << left << student.id;
        out << setw(WIDTH) << left << student.kor;
        out << setw(WIDTH) << left << student.eng;
        out << setw(WIDTH) << left << student.math;
        out << setw(WIDTH) << left << student.sumScore;
        out << setw(WIDTH) << left << student.avrg << "\n";
    }
    else {
        cout << "파일 출력 실패" << endl;
        exit(0);
    }
}
void Management::sortRank(Student student[]) {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX - i - 1; j++) {
            if (student[j].sumScore < student[j + 1].sumScore) {
                Student temp = student[j];
                student[j] = student[j + 1];
                student[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < MAX; i++) {
        student[i].rank = i + 1;
    }
}
void Management::initTableFormat() {
    out.open("student_result.data");
    out << setw(WIDTH) << left << "등수";
    out << setw(WIDTH) << left << "이름";
    out << setw(WIDTH) << left << "학번";
    out << setw(WIDTH) << left << "국어점수";
    out << setw(WIDTH) << left << "영어점수";
    out << setw(WIDTH) << left << "수학점수";
    out << setw(WIDTH) << left << "총점";
    out << setw(WIDTH) << left << "평균" << "\n";
}
