#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "Student_info.h"

using std::cin;
using std::cout;
using std::domain_error;
using std::endl;
using std::max;
using std::setprecision;
using std::sort;
using std::streamsize;
using std::string;
using std::vector;

int main() {
    Student_info student = {
        .name = "Tom",
        .midterm = 89.2,
        .final = 91.2,
        .homework = {87.0, 89.1, 91.4}
    };

    int maxlen = 0;
    // we need to cast
    maxlen = max(student.name.size(), static_cast<string::size_type>(maxlen));

    cout << "Max length is " << maxlen << endl;

    return 0;
}
