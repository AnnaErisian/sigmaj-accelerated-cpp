#include <iostream>
#include <string> 

int main() {
  bool tri = false;
  int width = 25;
  int height = 8;

  using std::cout;
  using std::endl;
  using std::string;

  for(int i = 0; i < height; i++) {
    if(tri) {
      int pad = (width - i * (width * 1.0 / height)) / 2;
      cout << string(pad, ' ') << string(width-2*pad, '*') << string(pad, ' ') << endl;
    } else {
      cout << string(width, '*') << endl;
    }
  }
}
