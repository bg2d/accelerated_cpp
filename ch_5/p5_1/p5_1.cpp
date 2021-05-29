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

void generate_all_rotations(vector<string>& line, vector<vector<string>>& permutations) {
    vector<string>::size_type no_rotations = 0;

    // Insert the initial string
    permutations.push_back(line);

    while (no_rotations < line.size()-1) {
        std::rotate(line.begin(), line.begin()+1, line.end());
        //print_line(line);
        permutations.push_back(line);
        ++no_rotations;
    }
}


int main() {
    vector<vector<string>> permutations;
    vector<string> line;

    read_line(cin, line);

    generate_all_rotations(line, permutations);

    std::sort(permutations.begin(), permutations.end());

    // Just for debugging
    cout << "===========================" << endl;
    auto iter = permutations.begin();
    while (iter != permutations.end()) {
        print_line(*iter);
        ++iter;
    }
    
    return 0;
}
