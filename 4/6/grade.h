#ifndef GRADE_H
#define GRADE_H

#include <vector>
#include "student_info.h"

double grade(double mid, double fin, double hw);
double grade(double mid, double fin, const std::vector<double>& hw);

#endif
