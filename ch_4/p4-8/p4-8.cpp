#include <iostream>

double *f() {
    static double numbers[] = {1, 2, 3, 4};
    return numbers;
}

int main() {
    int n = 2;
    double d = f()[n];

    std::cout << "d value is: " << d << std::endl;
    return 0;
}
