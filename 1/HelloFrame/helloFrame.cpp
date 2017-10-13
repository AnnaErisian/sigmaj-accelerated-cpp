#include <iostream>
#include <string>

int main() {
    std::string name;
    std::cout << "Enter your name: ";
    std::cin >> name;
    std::string greeting = "Hello, " + name;
    std::string greetRow = "* " + greeting + " *";
    std::string openRow = "*" + std::string(greeting.length() + 2, ' ') + "*";
    std::string edgeRow = std::string(openRow.length(), '*');
    std::cout << edgeRow << std::endl << openRow << std::endl << greetRow << std::endl << openRow << std::endl << edgeRow << std::endl;
    return 0;
}
