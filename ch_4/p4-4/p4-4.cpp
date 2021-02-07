#include <iostream>
#include <iomanip>
#include <cmath>

int no_digits(int n) {
    if (n == 0) return 1;
    return int(log10(n) + 1);
}

void print_square_vector(double n) {
    // compute the width of the first column
    int col_1_width = no_digits(n);
    // compute the width of the second column
    int col_2_width = no_digits(n * n);

    std::cout.precision(3);
    int current_precision = std::cout.precision();
    for (double i = 0.0; i <=n; i++) {
        std::cout << std::setw(current_precision + col_1_width) << std::fixed
        << i << " " << std::setw(current_precision + col_2_width)
        << i * i << std::endl;
    }
}

int main() {
    double n = 999.0;

    print_square_vector(n);

    return 0;
}
