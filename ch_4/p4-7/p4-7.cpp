#include <iostream>
#include <vector>

double compute_average(const std::vector<double>& vect) {
    double sum = 0.0;
    for (int i = 0; i < vect.size(); i++) {
        sum += vect[i];
    }

    return sum / vect.size();
}

int main() {
    std::vector<double> num_vect;

    std::cout << "Introduce the numbers followed by end of file" << std::endl;
    double number;
    while (std::cin >> number) {
        num_vect.push_back(number);
    }

    std::cout << "The average is: " << compute_average(num_vect) << std::endl;

    return 0;
}
