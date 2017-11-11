#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <stdexcept>
#include <cstdlib>
#include <cmath>
#include <climits>

#include "split.h"

using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::string;
using std::map;
using std::vector;
using std::rand;

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

static unsigned int nrand_aux(){
  const unsigned int num_bits_needed = ((int)std::log2(UINT_MAX))+1;
  const unsigned int num_bits_rand = 6;//((int)std::log2(RAND_MAX))+1;
  unsigned int i = 0;
  unsigned int r = 0;
  while(i < num_bits_needed) {
    unsigned int rng = rand() & 63;
    r |= rng << i;
    i += num_bits_rand;
  }
  return r;
}

unsigned int nrand(unsigned int bound) {
  if(bound <= 0)
    throw std::domain_error("Argument bound out of range for function nrand");
  
  unsigned int bucket_size = UINT_MAX / bound;
  unsigned int maxRand = bucket_size * bound;
  unsigned int rn;
  do
    rn = nrand_aux() / bucket_size;
  while(rn >= bound);
  
  return rn;
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

void test_rand() {
  cout << RAND_MAX << endl;
  cout << INT_MAX << endl;
  unsigned int x;
  cin >> x;
  for(int i = 0; i != 10000; i++) {
    unsigned int y = nrand(x);
    cout << y << ", ";
    if(y >= x)
      cout << "PROBLEM" << x;
  }
}

void test_rand_normal() {
  cout << RAND_MAX << endl;
  cout << INT_MAX << endl;
  for(int i = 0; i != 10000; i++) {
    cout << rand() << ", ";
  }
}

int main() {
  Grammar g = read_grammar(cin);
  
  vector<string> s = gen_sentence(g);
  for(string t : s)
    cout << t << " ";
  cout << endl;
}