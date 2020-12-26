#include <iostream>

int main() {
    std::cout << "Please enter two numbers." << std::endl;

    int f_n;
    std::cout << "The first number: ";
    std::cin >> f_n;
    std::cout << std::endl;

    int s_n;
    std::cout << "The second number: ";
    std::cin >> s_n;
    std::cout << std::endl;

    if (f_n < s_n) {
        std::cout << s_n << " is larger than " << f_n << std::endl;
    }
    else {
        if (f_n > s_n) {
            std::cout << f_n << " is larger than " << s_n << std::endl;
        }
        else {
            std::cout << "The numbers are equal." << std::endl;
        }
    }

    return 0;
}
