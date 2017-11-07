#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cctype>
#include <algorithm>

using std::string;
using std::map;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

bool not_space(char c) { return !std::isspace(c); }
bool space(char c) { return std::isspace(c); }

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