#include <iostream>
#include <string>
#include <stdexcept>
#include <algorithm>
#include <vector>
#include <iomanip>
#include "student_info.h"
#include "grade.h"

using std::cin;
using std::cout;
using std::endl;

using std::string;

using std::vector;

using std::setprecision;


int main() {
  
  vector<Student_info> students;
  Student_info tempRecord;
  string::size_type maxNameLength = 0;
  while(read(cin, tempRecord)) {
    maxNameLength = std::max(maxNameLength, tempRecord.name.size());
    students.push_back(tempRecord);
  }
  
  sort(students.begin(), students.end(), compare);
  
  for(auto i = 0; i < students.size(); ++i) {
    cout << students[i].name << string(maxNameLength - students[i].name.size() + 1, ' ');
    try {
      auto prec = cout.precision();
      double fg = students[i].finalGrade;
      cout << setprecision(3) << fg << setprecision(prec);
    } catch (std::domain_error e) {
      cout << e.what();
    }
    cout << endl;
  }
  return 0;
}
