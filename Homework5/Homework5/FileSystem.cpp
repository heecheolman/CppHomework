//
//  FileSystem.cpp
//  Homework5
//
//  Created by HeeCheol Kim on 2018. 10. 4..
//  Copyright © 2018년 HeeCheol Kim. All rights reserved.
//

#include "FileSystem.h"

void FileSystem::writeData(Student student) {
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
void FileSystem::initTableFormat() {
    out << setw(WIDTH) << left << "등수";
    out << setw(WIDTH) << left << "이름";
    out << setw(WIDTH) << left << "학번";
    out << setw(WIDTH) << left << "국어점수";
    out << setw(WIDTH) << left << "영어점수";
    out << setw(WIDTH) << left << "수학점수";
    out << setw(WIDTH) << left << "총점";
    out << setw(WIDTH) << left << "평균" << "\n";
}

void FileSystem::setWriteFilename(string filename) {
    writeFilename.setFile(filename);
}

void FileSystem::setReadFilename(string filename) {
    readFilename.setFile(filename);
}

void FileSystem::applyReadFile() {
    in.open(readFilename.getFile());
    if(in.fail()) {
        cout << "데이터를 읽어들이는데 실패했습니다" << endl;
        exit(0);
    }
}
void FileSystem::applyWriteFile() {
    out.open(writeFilename.getFile());
}
