

#include "Universe.h"
#include "Admission.h"
#include "MinistryEducation.h"

int main(void) {
    Universe * admission = new Admission();
    Universe * minisEdu = new MinistryEducation();
    admission->writeData();
    minisEdu->writeData();
}
