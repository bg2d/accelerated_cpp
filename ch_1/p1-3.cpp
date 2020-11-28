#include <iostream>
#include <string>

int main() {
    { const std::string s = "a string";
      std::cout << s << std::endl; }

    { const std::string s = "another string";
      std::cout << s << std::endl; }

    return 0;
}

// The program is valid. It prints "a string" and "another string".
// It is valid because the scopes of s variables are limited to their blocks
// defined by {}
