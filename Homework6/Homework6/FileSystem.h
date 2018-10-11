//
//  FileSystem.h
//  Homework6
//
//  Created by HeeCheol Kim on 2018. 10. 12..
//  Copyright © 2018년 HeeCheol Kim. All rights reserved.
//

#pragma once

#include <iomanip>
#include <fstream>
#include "Student.h"
#include "DataFile.h"
#include <string.h>

#define MAX 20
#define WIDTH 14
#define KORWIDTH WIDTH + 2
#define NUMWIDTH WIDTH - 4
using namespace std;

class FileSystem {
public:
    FileSystem() {}
    ~FileSystem() {}
    void writeData(Student student[], int subjectCount);
    void initTableFormat(int subjectCount);
    void setReadFilename(string filename);
    void setWriteFilename(string filename);
    void applyReadFile(Student student[], int subjectCount);
    void applyWriteFile();
    int getSubjectCount();

    ifstream in;
    ofstream out;
    DataFile readFilename;
    DataFile writeFilename;
};
