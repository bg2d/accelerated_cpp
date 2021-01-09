#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int number;
    const std::vector<int> vect = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    // Suppose that our vector is {1, 2, 3, 4, 5, 6, 7, 8, 9}
    // but we discarded 5
    const std::vector<int> vect_disc = {1, 2, 3, 4, 6, 7, 8, 9};

    // compute the median for the vect_disc
    // how many numbers do we have?
    int n_disc = vect_disc.size();
    std::vector<int>::size_type vect_disc_mid = n_disc / 2;
    int median_disc = n_disc % 2 == 0 ? (vect_disc[vect_disc_mid] + vect_disc[vect_disc_mid - 1]) / 2 : vect_disc[vect_disc_mid];

    std::cout << "The median value of the discarded vector is " << median_disc << std::endl;

    // compute the median for the vect
    // how many numbers do we have?
    int n = vect.size();
    std::vector<int>::size_type vect_mid = n / 2;
    int median = n % 2 == 0 ? (vect[vect_mid] + vect[vect_mid - 1]) / 2 : vect[vect_mid];

    std::cout << "The median value of the original vector is " << median << std::endl;

    return 0;
}
