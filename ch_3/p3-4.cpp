#include <iostream>
#include <string>
#include <vector>

int main() {
    std::cout << "Please enter some words followed by end-of-file: ";

    // read the user's input
    std::string word;
    std::string::size_type min_size, max_size;
    bool first_run = true;

    while (std::cin >> word) {
        std::string::size_type str_size = word.length();
        if (first_run) {
            min_size = str_size;
            max_size = str_size;
            first_run = false;
        }
        else {
            if (str_size < min_size) {
                min_size = str_size;
            }
            if (str_size > max_size) {
                max_size = str_size;
            }
        }
    }

    std::cout << "The length of the shortest string is: " << min_size << std::endl;
    std::cout << "The length of the logest string is: " << max_size << std::endl;

    return 0;
}
