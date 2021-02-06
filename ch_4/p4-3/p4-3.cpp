#include <iostream>
#include <iomanip>
#include <cmath>

int no_digits(int n) {
    if (n == 0) return 1;
    return int(log10(n) + 1);
}

void print_square_vector(int n) {
    // compute the width of the first column
    int col_1_width = no_digits(n);
    // compute the width of the second column
    int col_2_width = no_digits(n * n);

    for (int i = 0; i <=n; i++) {
        std::cout << std::setw(col_1_width)
        << i << " " << std::setw(col_2_width)
        << i * i << std::endl;
    }
}

int main() {
    int n = 999;

    print_square_vector(n);

    return 0;
}
