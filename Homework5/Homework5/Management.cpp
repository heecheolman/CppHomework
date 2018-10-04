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
