#include <vector>
#include <iostream>
#include "student_info.h"
#include "grade.h"

using std::vector;

std::istream& read_hw(std::istream& in, vector<double>& hw) {
  if(in) { //if we can continue
    //ensure empty vector
    hw.clear();
    
    //read in
    double x;
    while(in >> x) {
      hw.push_back(x);
    }
    
    //clear stream status so the input can be used if it is not empty
    in.clear();
  }
  return in;
}

std::istream& read(std::istream& is, Student_info& s) {
  vector<double> hws;
  double midterm, final;
  is >> s.name;
  is >> midterm;
  is >> final;
  read_hw(is, hws);
  if(!is) return is;
  s.finalGrade = grade(midterm, final, hws);
  return is;
}

bool compare(const Student_info & x, const Student_info& y) {
  return x.name < y.name;
}
