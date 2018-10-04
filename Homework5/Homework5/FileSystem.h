//
//  FileSystem.h
//  Homework5
//
//  Created by HeeCheol Kim on 2018. 10. 4..
//  Copyright © 2018년 HeeCheol Kim. All rights reserved.
//

#pragma once

#include <iomanip>
#include <fstream>
#include "Student.h"
#include "DataFile.h"
#include <string.h>

#define WIDTH 14
using namespace std;

class FileSystem {
public:
    FileSystem() {}
    ~FileSystem() {}
    void writeData(Student student);
    void initTableFormat();
    void setReadFilename(string filename);
    void setWriteFilename(string filename);
    void applyReadFile();
    void applyWriteFile();

    ifstream in;
    ofstream out;
    DataFile readFilename;
    DataFile writeFilename;
};
