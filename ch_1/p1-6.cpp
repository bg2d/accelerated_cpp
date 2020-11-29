#include <iostream>
#include <string>

int main() {
    std::cout << "What is your name?";
    std::string name;
    std::cin >> name;
    std::cout << "Hello, " << name
        << std::endl << "And what is yours?";
    std::cin >> name;
    std::cout << "Hello, " << name
        << "; nice to meet you too!" << std::endl;

    return 0;
}

// The program will ask for a name and will save the input in name string and
// will print it. After that will ask for another name and will save the input
// in the name string. The old value is overwritten. 
