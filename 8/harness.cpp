#include "functions.h"
#include <vector>
#include <iostream>

using std::vector;

static bool test_search() {
  int a[] = {1, 2, 3, 4, 5, 6, 7};
  int b[] = {1, 2, 4, 1, 2, 3, 4};
  int c[] = {1, 2, 3};
  int d[] = {4, 5};
  int e[] = {7};
  
  vector<int> alpha(a, a+7);
  vector<int> beta(b, b+7);
  vector<int> gamma(c, c+3);
  vector<int> delta(d, d+2);
  vector<int> epsilon(e, e+1);
  
  typedef vector<int>::const_iterator iter;
  
  iter r1 = search(alpha.begin(), alpha.end(), beta.begin(),    beta.end());
  iter r2 = search(alpha.begin(), alpha.end(), gamma.begin(),   gamma.end());
  iter r3 = search(alpha.begin(), alpha.end(), delta.begin(),   delta.end());
  iter r4 = search(alpha.begin(), alpha.end(), epsilon.begin(), epsilon.end());
  iter r5 = search(beta.begin(),  beta.end(),  gamma.begin(),   gamma.end());
  
//  if(r1 == alpha.end()) std::cout << "1" << std::endl;
//  if(r2 == alpha.begin()) std::cout << "2" << std::endl;
//  if(r3 == alpha.begin() + 3) std::cout << "3" << std::endl;
//  if(r4 == alpha.end() - 1) std::cout << "4" << std::endl;
//  if(r5 == beta.begin() + 3) std::cout << "5" << std::endl;

  return  r1 == alpha.end() &&
          r2 == alpha.begin() &&
          r3 == alpha.begin() + 3 &&
          r4 == alpha.end() - 1 &&
          r5 == beta.begin() + 3;
}

static bool test_equal() {
  int a[] = {1, 2, 3, 4, 5, 6, 7};
  int b[] = {1, 2, 4, 1, 2, 3, 4};
  int c[] = {1, 2, 3};
  int d[] = {4, 5};
  
  vector<int> alpha(a, a+7);
  vector<int> beta(b, b+7);
  vector<int> gamma(c, c+3);
  vector<int> delta(c, c+3);
  vector<int> epsilon(d, d+2);
  
  //true
  bool r1 = equal(alpha.begin(), alpha.end(), alpha.begin());
  bool r2 = equal(gamma.begin(), gamma.end(), delta.begin());
  
  //false
  bool r3 = equal(alpha.begin(), alpha.end(), beta.begin());
  bool r4 = equal(alpha.begin(), alpha.end(), gamma.begin());
  bool r5 = equal(alpha.begin(), alpha.end(), epsilon.begin());
  bool r6 = equal(gamma.begin(), gamma.end(), alpha.begin());
  
//  if(r1) std::cout << "1" << std::endl;
//  if(r2) std::cout << "2" << std::endl;
//  if(!r3) std::cout << "3" << std::endl;
//  if(!r4) std::cout << "4" << std::endl;
//  if(!r5) std::cout << "5" << std::endl;
//  if(!r6) std::cout << "6" << std::endl;
    
  return  r1 && r2 && !r3 && !r4 && !r5 && !r6;
}

static void run_print_results(std::string name, bool b()) {
  if(b()) {
    std::cout << "[O]" << name << " passed!" << std::endl;
  } else {
    std::cout << "[ ]" << name << " failed!" << std::endl;
  }
}

int main() {
  run_print_results("test_equal", test_equal);
  run_print_results("test_search", test_search);
//  run_print_results("test_find", test_find);
//  run_print_results("test_find_if", test_find_if);
//  run_print_results("test_transform", test_transform);
//  run_print_results("test_accumulate", test_accumulate);
//  run_print_results("test_copy", test_copy);
//  run_print_results("test_remove", test_remove);
//  run_print_results("test_remove_copy", test_remove_copy);
//  run_print_results("test_remove_copy_if", test_remove_copy_if);
//  run_print_results("test_partition", test_partition);
}
