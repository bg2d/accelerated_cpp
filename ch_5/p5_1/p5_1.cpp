#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::istream;
using std::vector;

typedef struct {
    vector<string> line;
    int no_rotations;
} line_t;

istream& read_line(istream& is, vector<string>& line) {
    if (is) {
        line.clear();

        string s;
        while(is >> s) {
            line.push_back(s);
        }

        is.clear();
    }

    return is;
}

void print_line(const vector<string>& line) {
    auto iter = line.begin();

    while (iter != line.end()) {
        cout << *iter << " ";
        ++iter;
    }
    cout << endl;
}

void generate_all_rotations(vector<string>& line, vector<line_t>& permutations) {
    vector<string>::size_type no_rotations = 0;

    line_t one_permutation;

    // Insert the initial string
    one_permutation.line = line;
    one_permutation.no_rotations = 0;
    permutations.push_back(one_permutation);

    while (no_rotations < line.size()-1) {
        std::rotate(line.begin(), line.begin()+1, line.end());
        ++no_rotations;
        one_permutation.line = line;
        one_permutation.no_rotations = no_rotations;
        permutations.push_back(one_permutation);
    }
}

void display_permuted_index(vector<line_t>& permutations) {
    cout << "===========================" << endl;
    auto iter = permutations.begin();
    while (iter != permutations.end()) {
        print_line(iter->line);
        cout << iter->no_rotations << endl;

        ++iter;
    }
    cout << "===========================" << endl;
}


int main() {
    vector<line_t> permutations;
    vector<string> line;

    read_line(cin, line);

    generate_all_rotations(line, permutations);

    // TODO: reimplement this
    //std::sort(permutations.begin(), permutations.end());

    display_permuted_index(permutations);
    
    return 0;
}
