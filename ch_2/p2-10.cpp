#include <iostream>

int main() {
int k = 0;
// add n to compile
int n = 5;
    while (k != n) { // invariant: we have written k astrisks so far
        using std::cout; // using-declaration; it is valid only in the while block
        cout << "*";
        ++k;
    }
    // using-declaration is not valid here anymore
    std::cout << std::endl; // std:: is required here
    return 0;
}
