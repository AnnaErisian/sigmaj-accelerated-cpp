#include <iostream>
#include <string>

int main() {
    using std::string;
    using std::cout;
    using std::cin;
    using std::endl;
    
    string name;
    cout << "Enter your name: ";
    cin >> name;
    
    int hpad, vpad;
    cout << "Horizontal padding: ";
    cin >> hpad;
    cout << "Vertical padding: ";
    cin >> vpad ;
    
    string greeting = "Hello, " + name;
    
    int row, col;
    row = 0;
    int height = 2*vpad + 3;
    int width = 2*hpad + greeting.length() + 2;
    //li: we have printed row rows
    while(row != height) {
        col = 0;
        //li: we have printed col characters
        while(col != width) {
            if(row == 0 || row == height-1) {
                cout << string(greeting.length() + 2 + hpad*2, '*');
                col += greeting.length() + 2 + hpad*2;
            } else if(col == 0 || col == width-1) {
                cout << "*";
                ++col;
                //inner li true
            } else if(row == height / 2) {
                cout << string(hpad, ' ');
                col += hpad;
                cout << greeting;
                col += greeting.length();
                cout << string(hpad, ' ');
                col += hpad;
                //inner li true
            } else {
                cout << string(hpad*2 + greeting.length(), ' ');
                col += hpad*2 + greeting.length();
                //inner li true
            }
        }
        cout << endl;
        ++row;
        //outer li true here
    }
    
    return 0;
}
