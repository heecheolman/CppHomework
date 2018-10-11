//
//  DataFile.h
//  Homework5
//
//  Created by HeeCheol Kim on 2018. 10. 12..
//  Copyright © 2018년 HeeCheol Kim. All rights reserved.
//
#pragma once
#include <string.h>
using namespace std;

class DataFile {
public:
    DataFile() {
        this->filename = "";
    }
    ~DataFile() {}
    inline void setFile(string filename) { this->filename = filename; }
    inline string getFile() { return this->filename; }
private:
    string filename;
};
