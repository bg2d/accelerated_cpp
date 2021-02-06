#include <iostream>
#include <iomanip>

int main() {
    for (int i = 0; i <= 100; i++) {
        std::cout << i;
        std::cout << std::setw(7);
        std::cout << i * i << std::endl;
    }

    return 0;
}
