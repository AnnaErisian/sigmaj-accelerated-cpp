#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

#include "split.h"

using std::string;
using std::vector;

static bool not_space(char c) { return !std::isspace(c); }
static bool space(char c) { return std::isspace(c); }

vector<string> split(const string &in) {
  vector<string> out;
  auto i = in.begin();
  while(i != in.end()) {
    i = std::find_if(i, in.end(), not_space);
    auto j = std::find_if(i, in.end(), space);
    if(i != in.end())
      out.push_back(string(i,j));
    i = j;
  }
  return out;
}