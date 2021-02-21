#include <iostream>
#include <string>
#include <algorithm>

#include "p4-5.h"

void print_words(const std::vector<input_word>& wv) {
    // Iterate the vector
    auto it = wv.begin();
    while (it != wv.end()) {
        std::cout << (*it).word << " : " << (*it).occ << std::endl;
        it++;
    }
}

bool is_current_word_unique(std::string s, std::vector<input_word>& wv) {
    // Iterate the vector
    auto it = wv.begin();
    while (it != wv.end()) {
        if (s.compare((*it).word) == 0) {
            return false;
        }
        it++;
    }

    return true;
}

void increase_word_occuarrence(std::string s, std::vector<input_word>& wv) {
    // Iterate the vector
    auto it = wv.begin();
    while (it != wv.end()) {
        if (s.compare((*it).word) == 0) {
            (*it).occ++;
            return;
        }
        it++;
    }
}

int get_input(std::istream& in, std::vector<input_word>& wv) {
    int count = 0;
    // Read the input words
    std::string buf;
    while (in >> buf) {
        count++;

        // Verify if the current word exists in our vector
        if (is_current_word_unique(buf, wv)) {
            input_word element;
            element.word = buf;
            element.occ = 1;
            wv.push_back(element);
        }
        else {
            increase_word_occuarrence(buf, wv);
        }
    }

    return count;
}

int main() {
    std::vector<input_word> wv;
    int no_words = get_input(std::cin, wv);

    std::cout << "Total words: " << no_words << std::endl;

    print_words(wv);

    return 0;
}
