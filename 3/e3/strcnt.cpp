#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;

using std::string;

using std::vector;

using std::sort;

int main() {
    //read all into vector
    vector<string> words;
    string inputString;
    while(cin >> inputString)
        words.push_back(inputString);
    
    //sort
    sort(words.begin(), words.end());
    
    if(words.size() == 0) {
        cout << "Please enter some words" << endl;
        return 1;
    }
    
    //loop through
    int count = 1;
    string lastWord = words[0];
    for(string &s : words) {
        if(s != lastWord) {
            cout << lastWord << ": " << count << endl;
            count = 1;
            lastWord = s;
        } else {
            ++count;
        }
    }
}
