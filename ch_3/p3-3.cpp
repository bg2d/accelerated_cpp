#include <iostream>
#include <string>
#include <vector>

int main() {
    std::cout << "Please enter some words followed by end-of-file: ";

    // read the user's input
    std::string word;
    std::vector<std::string> vect_string;
    std::vector<int> counts;

    while (std::cin >> word) {
        // verify if the current word was introduced before
        bool found = false;

        if (vect_string.size() > 0) {
            for (int i = 0; i < vect_string.size(); i++) {
                if (word == vect_string[i]) {
                    counts[i]++;
                    found = true;
                }
            }
        }

        if (!found) {
            // add the word in a vector
            vect_string.push_back(word);
            counts.push_back(1);
        }
    }

    // display the result
    for (int i = 0; i < vect_string.size(); i++) {
        std::cout << vect_string[i] << " appears " << counts[i] << " times." << std::endl;
    }

    return 0;
}
