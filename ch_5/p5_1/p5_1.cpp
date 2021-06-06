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

vector<string> rotate_back(const line_t& l) {
    line_t local_line = l;

    std::rotate(local_line.line.begin(),  local_line.line.end() - local_line.no_rotations, local_line.line.end());

    return local_line.line;
}

int get_total_chars(const vector<string>& s) {
    int total_chars = 0;

    auto iter = s.begin();
    while (iter != s.end()) {
        total_chars += iter->length();
        // for space between words
        total_chars++;
        ++iter;
    }

    return total_chars;
}

int get_total_chars_of_lines(const vector<vector<string>>& l) {
    int total_chars = 0;

    auto iter = l.begin();
    while (iter != l.end()) {
        total_chars += get_total_chars(*iter);
        ++iter;
    }

    return total_chars;
}

int get_total_chars_in_interval(const vector<string>& s, int limit) {
    int total_chars = 0;

    auto iter = s.begin();
    while (iter != (s.begin() + limit)) {
        total_chars += iter->length();
        // for space between words
        total_chars++;
        ++iter;
    }

    return total_chars;
}

void format_output(vector<line_t>& permutations, int total_chars_in_lines) {
    auto iter = permutations.begin();

    while (iter != permutations.end()) {
        vector<string> original = rotate_back(*iter);
        int limit_chars = get_total_chars_in_interval(original, iter->no_rotations);
        //int no_tabs = get_total_chars(iter->line) - limit_chars;
        int no_tabs = total_chars_in_lines - limit_chars;
        
        // generate the border for each line
        string border(no_tabs, ' ');
        original.insert(original.begin(), border);
        iter->line = original;
        
        ++iter;
    }
}

void display_permuted_index(vector<line_t>& permutations) {
    cout << "===========================" << endl;
    auto iter = permutations.begin();
    while (iter != permutations.end()) {
        print_line(iter->line);
        ++iter;
    }
    cout << "===========================" << endl;
}

bool compare(const line_t& l1, const line_t& l2) {
    return l1.line < l2.line;
}

vector<string> split(const string& s) {
    vector<string> ret;
    typedef string::size_type string_size;
    string_size i = 0;

    while (i != s.size()) {
        while (i != s.size() && isspace(s[i])) {
            i++;
        }

        string_size j = i;
        while (j != s.size() && !isspace(s[j])) {
            j++;
        }

        if (i != j) {
            ret.push_back(s.substr(i, j - i));
            i = j;
        }
    }

    return ret;
}

void get_input(vector<vector<string>>& w) {
    string s;

    while (getline(cin, s)) {
        vector<string> v = split(s);
        w.push_back(v);
    }

    return;
}

int main() {
    vector<line_t> permutations;
    vector<vector<string>> lines;

    get_input(lines);

    auto iter = lines.begin();
    while (iter != lines.end()) {
       generate_all_rotations(*iter, permutations);
        ++iter;
    }

    std::sort(permutations.begin(), permutations.end(), compare);

    format_output(permutations, get_total_chars_of_lines(lines));

    display_permuted_index(permutations);

    return 0;
}
