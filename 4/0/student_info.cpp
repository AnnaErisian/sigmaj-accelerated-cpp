#include <vector>
#include <iostream>
#include "student_info.h"

using std::vector;
using std::cin;

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
  cin >> s.name >> s.midterm >> s.final;
  read_hw(is, s.homework);
}

bool compare(const Student_info & x, const Student_info& y) {
  return x.name < y.name;
}
