#include <iostream>

int main() {
    int p = 1;

    for (int i = 1; i < 10; i++) {
        p = p * i;
    }

    std::cout << "The product is: " << p << std::endl;

    return 0;
}
