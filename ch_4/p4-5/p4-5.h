#ifndef GUARD_P4_5_h
#define GUARD_P4_5_h

#include <string>
#include <vector>

struct input_word {
    std::string word;
    int occ;
};

int get_input(std::istream&, std::vector<input_word>&);

#endif
