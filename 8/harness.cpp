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

static bool test_remove() {
  int a[] = {1, 2, 3, 4, 5, 6, 7};
  int b[] = {1, 2, 4, 1, 2, 3, 4};
  int c[] = {7};
  
  vector<int> alphaProto(a, a+7);
  vector<int> alpha;
  vector<int> betaProto(b, b+7);
  vector<int> beta;
  vector<int> gammaProto(c, c+1);
  vector<int> gamma;
  
  typedef vector<int>::iterator iter;
  
  bool succ = true;
  
  alpha = alphaProto;
  iter r1 = remove(alpha.begin(), alpha.end(), 1);
  succ &= r1 + 1 == alpha.end();
  succ &= alpha[0] == 2;
  succ &= alpha[1] == 3;
  succ &= alpha[2] == 4;
  succ &= alpha[3] == 5;
  succ &= alpha[4] == 6;
  succ &= alpha[5] == 7;
  
  alpha = alphaProto;
  iter r2 = remove(alpha.begin(), alpha.end(), 2);
  succ &= r2 + 1 == alpha.end();
  succ &= alpha[0] == 1;
  succ &= alpha[1] == 3;
  succ &= alpha[2] == 4;
  succ &= alpha[3] == 5;
  succ &= alpha[4] == 6;
  succ &= alpha[5] == 7;
  
  alpha = alphaProto;
  iter r3 = remove(alpha.begin(), alpha.end(), 3);
  succ &= r3 + 1 == alpha.end();
  succ &= alpha[0] == 1;
  succ &= alpha[1] == 2;
  succ &= alpha[2] == 4;
  succ &= alpha[3] == 5;
  succ &= alpha[4] == 6;
  succ &= alpha[5] == 7;
  
  alpha = alphaProto;
  iter r4 = remove(alpha.begin(), alpha.end(), 6);
  succ &= r4 + 1 == alpha.end();
  succ &= alpha[0] == 1;
  succ &= alpha[1] == 2;
  succ &= alpha[2] == 3;
  succ &= alpha[3] == 4;
  succ &= alpha[4] == 5;
  succ &= alpha[5] == 7;
  
  alpha = alphaProto;
  iter r5 = remove(alpha.begin(), alpha.end(), 7);
  succ &= r5 + 1 == alpha.end();
  succ &= alpha[0] == 1;
  succ &= alpha[1] == 2;
  succ &= alpha[2] == 3;
  succ &= alpha[3] == 4;
  succ &= alpha[4] == 5;
  succ &= alpha[5] == 6;
  
  beta = betaProto;
  iter r6 = remove(beta.begin(), beta.end(), 1);
  succ &= r6 + 2 == beta.end();
  succ &= beta[0] == 2;
  succ &= beta[1] == 4;
  succ &= beta[2] == 2;
  succ &= beta[3] == 3;
  succ &= beta[4] == 4;

  beta = betaProto;
  iter r7 = remove(beta.begin(), beta.end(), 2);
  succ &= r7 + 2 == beta.end();
  succ &= beta[0] == 1;
  succ &= beta[1] == 4;
  succ &= beta[2] == 1;
  succ &= beta[3] == 3;
  succ &= beta[4] == 4;

  beta = betaProto;
  iter r8 = remove(beta.begin(), beta.end(), 4);
  succ &= r8 + 2 == beta.end();
  succ &= beta[0] == 1;
  succ &= beta[1] == 2;
  succ &= beta[2] == 1;
  succ &= beta[3] == 2;
  succ &= beta[4] == 3;
  
  gamma = gammaProto;
  iter r9 = remove(gamma.begin(), gamma.end(), 7);
  succ &= r9 + 1 == gamma.end();
  
  gamma = gammaProto;
  iter r0 = remove(gamma.begin(), gamma.end(), 8);
  succ &= r0  == gamma.end();
  succ &= gamma[0] == 7;
  
  return  succ;
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
  bool r3 = equal(gamma.begin(), gamma.end(), alpha.begin());
  
  //false
  bool r4 = equal(alpha.begin(), alpha.end(), beta.begin());
  bool r5 = equal(alpha.begin(), alpha.end(), gamma.begin());
  bool r6 = equal(alpha.begin(), alpha.end(), epsilon.begin());

//  if(r1) std::cout << "1" << std::endl;
//  if(r2) std::cout << "2" << std::endl;
//  if(!r3) std::cout << "3" << std::endl;
//  if(!r4) std::cout << "4" << std::endl;
//  if(!r5) std::cout << "5" << std::endl;
//  if(!r6) std::cout << "6" << std::endl;
    
  return  r1 && r2 && r3 && !r4 && !r5 && !r6;
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
  run_print_results("test_remove", test_remove);
//  run_print_results("test_remove_copy", test_remove_copy);
//  run_print_results("test_remove_copy_if", test_remove_copy_if);
//  run_print_results("test_partition", test_partition);
}
