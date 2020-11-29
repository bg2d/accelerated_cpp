#include <iostream>
#include <string>

int main() {
    // The program is invalid in its original state because it accesses x
    // outside of its scope. We can move the std::cout << x << std::endl; line
    // in the nested block.
    {   std::string s = "a string";
        {   std::string x = s + ", really";
            std::cout << s << std::endl;
            // Now is valid
            std::cout << x << std::endl;
        }
        // std::cout << x << std::endl;
    }

    return 0;
}
