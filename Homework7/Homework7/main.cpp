//
//  main.cpp
//  Homework7
//
//  Created by HeeCheol Kim on 2018. 11. 01..
//  Copyright © 2018년 HeeCheol Kim. All rights reserved.
//

#include "Universe.h"
#include "Admission.h"
#include "MinistryEducation.h"

int main(void) {
    Universe * admission = new Admission();
    Universe * minisEdu = new MinistryEducation();
    admission->writeData();
    minisEdu->writeData();
}
