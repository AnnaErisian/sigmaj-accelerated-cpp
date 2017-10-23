#include <vector>
#include <algorithm>
#include <stdexcept>
#include "median.h"

using std::vector;

double median(vector<double> vec) {
  auto sz = vec.size();
  if(sz == 0) {
    throw std::domain_error("Attempted to find median of an empty vector.");
  }
  std::sort(vec.begin(), vec.end());
  
  auto mid = sz/2;
  
  return sz % 2 == 0 ? (vec[mid] + vec[mid-1]) / 2 : vec[mid];
}
