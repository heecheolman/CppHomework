
#include "Universe.h"

Universe::Universe() {
    setStudentData();
}
void Universe::setStudentData() {
    in.open("midtest.txt");
    if(in.is_open()) {
        for(int i = 0; i < 10; i++) {
            Student *st = new Student();
            in >> st->id;
            in >> st->name;
            in >> st->school;
            in >> st->score;
            st->showInfo();
            studentList.push_back(st);
        }
    }
}
