#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <stdexcept>

#include "split.h"

using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::string;
using std::map;
using std::vector;

typedef vector<string> Rule;
typedef vector<Rule> Rule_collection;
typedef map<string, Rule_collection> Grammar;

Grammar read_grammar(istream& in) {
  Grammar ret;
  string line;
  
  while(getline(in, line)) {
    vector<string> entry = split(line);
    if(! entry.empty()) {
      ret[entry[0]].push_back(
          Rule(entry.begin()+1, entry.end())
          );
    }
  }
  return ret;
}

bool bracketed(const string& str) {
  if(str.empty()) return false;
  return str[0] == '<' && str[str.length()-1] == '>';
}

int nrand(int bound) {
  return 0;
}

static void gen_aux(const Grammar& g, const string& word, vector<string>& output) {
  if(!bracketed(word)) {
    output.push_back(word);
    return;
  } else {
    Grammar::const_iterator it = g.find(word);
    
    if(it == g.end()) {
      cout << "|" << word << "|" << endl;
      throw std::logic_error("Empty rule");
    }
    
    const Rule words = it->second[nrand(it->second.size())];
    for(string s : words) {
      gen_aux(g, s, output);
    }
  }
}

vector<string> gen_sentence(const Grammar& g) {
  vector<string> ret;
  gen_aux(g, "<sentence>", ret);
  return ret;
}

int main() {
  Grammar g = read_grammar(cin);
  
  for(Grammar::const_iterator i = g.begin(); i != g.end(); i++)
    cout << i->first << ", " << i->second[0][0] << endl;
  
  vector<string> s = gen_sentence(g);
  for(string t : s)
    cout << t << " ";
  cout << endl;
}