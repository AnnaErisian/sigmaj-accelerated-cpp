#include <iostream>
#include <string>
#include <iomanip>
#include <ios>
#include <vector>
#include <algorithm>

//from iostream
using std::cin;
using std::cout;
using std::endl;
//from string
using std::string;
//from iomanip
using std::setprecision;
//from ios
using std::streamsize;
//from vector
using std::vector;
//from algorithm
using std::sort;

int main() {
    //get name
    cout << "Name: " << endl;
    string name;
    cin >> name;
    cout << "Hello, " << name << "!" << endl;
    
    double midt, fin;
    cout << "Midterm, Final: " << endl;
    cin >> midt >> fin;
    
    cout << "Homeworks: " << endl;
    vector<double> hws; // default initialization for vector is empty vector
    double x;
    while(cin >> x) { //cin as bool returns false after read failure or EOF
        hws.push_back(x);
    }
    
    typedef vector<double>::size_type vec_d_sz;
    vec_d_sz size = hws.size();
    if(size == 0) {
        cout << endl << "You must enter some homeworks."
                        "Please try again." << endl;
        return 1;
    }
    sort(hws.begin(), hws.end());
    vec_d_sz mid = size / 2;
    double median = size % 2 == 0 ? (hws[mid] + hws[mid-1])/2 :
                                    hws[mid];
    
    streamsize prec = cout.precision();
    cout << "Grade: " << setprecision(3) << 0.2*midt + 0.4*fin + 0.4*median
            << setprecision(prec) << endl;
    
    return 0;
}
