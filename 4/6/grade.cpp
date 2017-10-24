#include <vector>
#include <stdexcept>
#include "student_info.h"
#include "grade.h"
#include "median.h"

using std::vector;

double grade(double mid, double fin, double hw) {
  return 0.2* mid + 0.4 * fin + 0.4 * hw;
}

double grade(double mid, double fin, const vector<double>& hw) {
  if(hw.size() == 0)
    throw std::domain_error("Student has done no homework");
  return grade(mid, fin, median(hw));
}
