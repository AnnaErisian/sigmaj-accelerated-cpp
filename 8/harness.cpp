#include "functions.h"
#include <vector>
#include <iostream>

using std::vector;


static bool aux_is_seven_or_two(int i) {
  return i==2 || i==7;
}

static bool aux_never_ever(int i) {
  return false;
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

static bool test_find() {
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

  bool succ = true;
  
  //find
  iter r1 = find(alpha.begin(), alpha.end(), 1);
  succ &= r1 == alpha.begin();
  iter r2 = find(alpha.begin(), alpha.end(), 5);
  succ &= r2 == alpha.begin()+4;
  iter r3 = find(alpha.begin(), alpha.end(), 7);
  succ &= r3 == alpha.begin()+6;
  iter r4 = find(epsilon.begin(), epsilon.end(), 7);
  succ &= r4 == epsilon.begin();
  iter r5 = find(beta.begin()+3, beta.end(), 2);
  succ &= r5 == beta.begin()+4;
  iter r6 = find(beta.begin()+3, beta.end(), 4);
  succ &= r6 == beta.begin()+6;
  
  //find first
  iter r7 = find(beta.begin(), beta.end(), 1);
  succ &= r7 == beta.begin()+0;
  iter r8 = find(beta.begin(), beta.end(), 2);
  succ &= r8 == beta.begin()+1;
  iter r9 = find(beta.begin(), beta.end(), 4);
  succ &= r9 == beta.begin()+2;

  //fail to find
  iter r0 = find(beta.begin(), beta.end(), 7);
  succ &= r0 == beta.end();
  iter rA = find(epsilon.begin(), epsilon.end(), 8);
  succ &= rA == epsilon.end();
  
  return  succ;
}

static bool test_find_if() {
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

  bool succ = true;
  
  //find
  iter r1 = find_if(alpha.begin(), alpha.end(), aux_is_seven_or_two);
  succ &= r1 == alpha.begin()+1;
  iter r2 = find_if(alpha.begin()+4, alpha.end(), aux_is_seven_or_two);
  succ &= r2 == alpha.begin()+6;
  iter r4 = find_if(epsilon.begin(), epsilon.end(), aux_is_seven_or_two);
  succ &= r4 == epsilon.begin();
  iter r5 = find_if(beta.begin()+3, beta.end(), aux_is_seven_or_two);
  succ &= r5 == beta.begin()+4;
  
  //find first
  iter r8 = find_if(beta.begin(), beta.end(), aux_is_seven_or_two);
  succ &= r8 == beta.begin()+1;

  //fail to find
  iter rA = find_if(epsilon.begin(), epsilon.end(), aux_never_ever);
  succ &= rA == epsilon.end();
  
  return  succ;
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

static bool test_remove_copy() {
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
  vector<int> o1;
  iter r1 = remove_copy(alpha.begin(), alpha.end(), back_inserter(o1), 1);
  succ &= r1 + 1 == alpha.end();
  succ &= alpha[0] == 2;
  succ &= alpha[1] == 3;
  succ &= alpha[2] == 4;
  succ &= alpha[3] == 5;
  succ &= alpha[4] == 6;
  succ &= alpha[5] == 7;
  succ &= o1[0] == 1;
  succ &= o1.size() == 1;
  
  beta = betaProto;
  vector<int> o2;
  iter r7 = remove_copy(beta.begin(), beta.end(), back_inserter(o2), 2);
  succ &= r7 + 2 == beta.end();
  succ &= beta[0] == 1;
  succ &= beta[1] == 4;
  succ &= beta[2] == 1;
  succ &= beta[3] == 3;
  succ &= beta[4] == 4;
  succ &= o2[0] == 2;
  succ &= o2[1] == 2;
  succ &= o2.size() == 2;
  
  gamma = gammaProto;
  vector<int> o3;
  iter r9 = remove_copy(gamma.begin(), gamma.end(), back_inserter(o3), 7);
  succ &= r9 + 1 == gamma.end();
  succ &= o3.size() == 1;
  succ &= o3[0] == 7;
  
  gamma = gammaProto;
  vector<int> o4;
  iter r0 = remove_copy(gamma.begin(), gamma.end(), back_inserter(o4), 8);
  succ &= r0  == gamma.end();
  succ &= gamma[0] == 7;
  succ &= o4.size() == 0;
  
  return succ;
}

static bool test_remove_copy_if() {
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
  vector<int> o1;
  iter r1 = remove_copy_if(alpha.begin(), alpha.end(), back_inserter(o1), aux_is_seven_or_two);
  succ &= r1 + 2 == alpha.end();
  succ &= alpha[0] == 1;
  succ &= alpha[1] == 3;
  succ &= alpha[2] == 4;
  succ &= alpha[3] == 5;
  succ &= alpha[4] == 6;
  succ &= o1[0] == 2;
  succ &= o1[1] == 7;
  succ &= o1.size() == 2;
  
  beta = betaProto;
  vector<int> o2;
  iter r7 = remove_copy_if(beta.begin(), beta.end(), back_inserter(o2), aux_is_seven_or_two);
  succ &= r7 + 2 == beta.end();
  succ &= beta[0] == 1;
  succ &= beta[1] == 4;
  succ &= beta[2] == 1;
  succ &= beta[3] == 3;
  succ &= beta[4] == 4;
  succ &= o2[0] == 2;
  succ &= o2[1] == 2;
  succ &= o2.size() == 2;
  
  gamma = gammaProto;
  vector<int> o3;
  iter r9 = remove_copy_if(gamma.begin(), gamma.end(), back_inserter(o3), aux_is_seven_or_two);
  succ &= r9 + 1 == gamma.end();
  succ &= o3.size() == 1;
  succ &= o3[0] == 7;
  
  gamma = gammaProto;
  vector<int> o4;
  iter r0 = remove_copy_if(gamma.begin(), gamma.end(), back_inserter(o4), aux_never_ever);
  succ &= r0  == gamma.end();
  succ &= gamma[0] == 7;
  succ &= o4.size() == 0;
  
  return succ;
}

static bool test_partition() {
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
  vector<int> o1;
  iter r1 = partition(alpha.begin(), alpha.end(), aux_is_seven_or_two);
  succ &= r1 + 2 == alpha.end();
  succ &= alpha[0] == 1;
  succ &= alpha[1] == 3;
  succ &= alpha[2] == 4;
  succ &= alpha[3] == 5;
  succ &= alpha[4] == 6;
  succ &= alpha[5] == 2;
  succ &= alpha[6] == 7;
  
  beta = betaProto;
  vector<int> o2;
  iter r7 = partition(beta.begin(), beta.end(), aux_is_seven_or_two);
  succ &= r7 + 2 == beta.end();
  succ &= beta[0] == 1;
  succ &= beta[1] == 4;
  succ &= beta[2] == 1;
  succ &= beta[3] == 3;
  succ &= beta[4] == 4;
  succ &= beta[5] == 2;
  succ &= beta[6] == 2;
  
  gamma = gammaProto;
  vector<int> o3;
  iter r9 = partition(gamma.begin(), gamma.end(), aux_is_seven_or_two);
  succ &= r9 + 1 == gamma.end();
  succ &= gamma[0] == 7;
  
  gamma = gammaProto;
  vector<int> o4;
  iter r0 = partition(gamma.begin(), gamma.end(), aux_never_ever);
  succ &= r0  == gamma.end();
  succ &= gamma[0] == 7;
  
  return succ;
}

static bool test_accumulate() {
  int a[] = {1, 2, 3, 4, 5, 6, 7};
  int b[] = {1, 2, 4, 1, 2, 3, 4};
  int c[] = {7};
  int d[] = {};
  
  vector<int> alpha(a, a+7);
  vector<int> beta(b, b+7);
  vector<int> gamma(c, c+1);
  vector<int> delta(d, d);
  
  int x[] = {accumulate(alpha.begin(), alpha.end(), 0),
             accumulate(beta.begin(),  beta.end(),  0),
             accumulate(gamma.begin(), gamma.end(), 0),
             accumulate(delta.begin(), delta.end(), 0)};

  return x[0] == 28 &&
         x[1] == 17 &&
         x[2] == 7 &&
         x[3] == 0;
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
  run_print_results("test_find", test_find);
  run_print_results("test_find_if", test_find_if);
//  run_print_results("test_transform", test_transform);
  run_print_results("test_accumulate", test_accumulate);
//  run_print_results("test_copy", test_copy);
  run_print_results("test_remove", test_remove);
  run_print_results("test_remove_copy", test_remove_copy);
  run_print_results("test_remove_copy_if", test_remove_copy_if);
  run_print_results("test_partition", test_partition);
}
