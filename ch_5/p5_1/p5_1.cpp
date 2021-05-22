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

void generate_all_rotations(vector<string>& line) {
    vector<string>::size_type no_rotations = 0;

    while (no_rotations < line.size()-1) {
        std::rotate(line.begin(), line.begin()+1, line.end());
        print_line(line);
        ++no_rotations;
    }
}


int main() {
    vector<string> line;

    read_line(cin, line);

    generate_all_rotations(line);
    
    return 0;
}
