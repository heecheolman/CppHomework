//
//  FileSystem.cpp
//  Homework5
//
//  Created by HeeCheol Kim on 2018. 10. 12..
//  Copyright © 2018년 HeeCheol Kim. All rights reserved.
//

#include "FileSystem.h"

void FileSystem::writeData(Student student[], int subjectCount) {
    if (out.is_open()) {
        for(int i = 0; i < MAX; i++) {
            out << setw(WIDTH) << left << student[i].rank;
            out << setw(KORWIDTH) << left << student[i].name;
            out << setw(WIDTH) << left << student[i].id;
            for(int j = 0; j < subjectCount; j++) {
                out << setw(11) << left << student[i].subject[j];
            }
            out << setw(NUMWIDTH) << left << student[i].sumScore;
            out << setw(NUMWIDTH) << left << student[i].avrg << "\n";
            student[i].printInfo(subjectCount);
        }
    }
    else {
        cout << "파일 출력 실패" << endl;
        exit(0);
    }
}
void FileSystem::initTableFormat(int subjectCount) {
    out << setw(KORWIDTH) << left << "등수";
    out << setw(KORWIDTH) << left << "이름";
    out << setw(KORWIDTH) << left << "학번";
    for(int i = 0; i < subjectCount; i++) {
        out << setw(1) << left << i + 1 << setw(13) << left << "과목";
    }
    out << setw(KORWIDTH) << left << "총점";
    out << setw(KORWIDTH) << left << "평균" << "\n";
}

void FileSystem::setWriteFilename(string filename) {
    writeFilename.setFile(filename);
}

void FileSystem::setReadFilename(string filename) {
    readFilename.setFile(filename);
}

void FileSystem::applyReadFile(Student student[], int subjectCount) {
    in.clear();
    in.seekg(0, std::ios::beg);
    for(int i = 0; i < MAX; i++) {
        in >> student[i].name;
        in >> student[i].id;
        for(int j = 0; j < subjectCount; j++) {
            in >> student[i].subject[j];
        }
    }
    for(int i = 0; i < MAX; i++) {
        double sumScore = 0;
        for(int j = 0; j < subjectCount; j++) {
            sumScore += student[i].subject[j];
        }
        student[i].sumScore = sumScore;
        student[i].avrg = sumScore / subjectCount;
    }
    if(in.fail()) {
        cout << "데이터를 읽어들이는데 실패했습니다" << endl;
        exit(0);
    }
}

void FileSystem::applyWriteFile() {
    out.open(writeFilename.getFile());
}

int FileSystem::getSubjectCount() {
    int inputCount = 0;
    int subjectCount = 0;
    string temp;
    in.open(readFilename.getFile());
    while(!in.eof()) {
        in >> temp;
        inputCount++;
    }
    subjectCount = (inputCount - 1) / MAX;
    subjectCount -= 2;
    return subjectCount;
}
