#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cctype>
#include <algorithm>

#include "split.h"

using std::string;
using std::map;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

map<string, vector<int> > xref(std::istream& in, vector<string> find_words(const string&) = split) {
  string line;
  map<string, vector<int> > table;
  int linenum = 0;
  
  while(getline(in, line)) {
    linenum++;
    vector<string> words = split(line);
    for(string &word : words) {
      if(!word.empty())
        cout << "|||" << word << endl;
        table[word].push_back(linenum);
    }
  }
  
  return table;
}

int main() {
  auto table = xref(cin);
  
  for(auto &it : table) {
    cout << it.first << " occurs on line(s): ";
    
    auto lineIter = it.second.begin();
    cout << *lineIter++;
    while(lineIter != it.second.end()) {
      cout << ", " << *lineIter++;
    }
    cout << endl;
    
  }
}