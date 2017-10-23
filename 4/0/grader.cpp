#include <iostream>
#include <string>
#include <stdexcept>
#include <algorithm>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

using std::string;

using std::vector;

double grade(double mid, double fin, double hw) {
  return 0.2* mid + 0.4 * fin + 0.4 * hw;
}

double grade(double mid, double fin, const vector<double>& hw) {
  if(hw.size() == 0)
    throw std::domain_error("Student has done no homework");
  return grade(mid, fin, median(hw));
}

iostream& read_hw(istream& in, vector<double> hw) {
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

double median(vector<double> vec) {
  auto sz = vec.size()'
  if(sz == 0) {
    throw std::domain_error("Attempted to find median of an empty vector.")
  }
  std::sort(vec.begin(), vec.end());
  
  auto mid = sz/2;
  
  return size % 2 == 0 ? (vec[mid] + vec[mid-1]) / 2 : vec[mid];
}