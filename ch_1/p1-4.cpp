#include <iostream>
#include <string>

int main() {
    { const std::string s = "a string";
      std::cout << s << std::endl;
      { const std::string s = "another string";
        std::cout << s << std::endl;};}

    return 0;
}

// Both variants are valid. The first s string is an outer variable for the
// nested block, but is hidden for the second block by the s string defined in
// it.
