#include <iostream>
#include <string>
#include <map>

using std::string;
using std::map;
using std::cin;
using std::cout;
using std::endl;

int main() {
  string s;
  map<string, int> counts;
  
  while(cin >> s) {
    counts[s]++;
  }
  
  for(auto i = counts.begin(); i != counts.end(); i++) {
    cout << i->first << ": " << i->second << endl;
  }
  
  return 0;
}