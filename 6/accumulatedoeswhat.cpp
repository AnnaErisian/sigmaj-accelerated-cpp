#include <iostream>
#include <numeric>
#include <vector>
#include <string>

using std::vector;
using std::cout;
using std::endl;
using std::accumulate;
using std::string;

int main() {
  vector<string> strs;
  strs.push_back("Hi ");
  strs.push_back("I ");
  strs.push_back("am ");
  strs.push_back("some ");
  strs.push_back("text.");
  string s = accumulate(strs.begin(), strs.end(), string());
  cout << s << endl;
}
