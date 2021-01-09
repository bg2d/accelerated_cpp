#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int number;
    std::vector<int> vect;

    std::cout << "Enter integer numbers or end-of-file to exit: ";

    while (std::cin >> number) {
        // save the number
        vect.push_back(number);
    }

    // put the numbers in order
    std::sort(vect.begin(), vect.end());

    // how many numbers do we have?
    int n = vect.size();

    // compute q1, q2 and q3
    int q1 = (n + 1) * 1/4;
    int q2 = (n + 1) * 2/4;
    int q3 = (n + 1) * 3/4;

    // print the results
    std::cout << "The lower quartile is on position " << q1 << " and its value is " << vect[q1 - 1] << std::endl;
    std::cout << "The middle quartile is on position " << q2 << " and its value is " << vect[q2 - 1] << std::endl;
    std::cout << "The upper quartile is on position " << q3 << " and its value is " << vect[q3 - 1] << std::endl;

    return 0;
}
