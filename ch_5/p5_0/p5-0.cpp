#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <list>
#include <iterator>

#include "grade.h"
#include "Student_info.h"

using std::cin;
using std::cout;
using std::domain_error; using std::endl;
using std::max;
using std::setprecision;
using std::sort;
using std::streamsize;
using std::string;
using std::vector;
using std::list;
using std::iterator;

int main() {
    list<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0; // the length of the longest name

    // read and store all the students data.
    // Invariant: students contains all the student records read so far
    // max len contains the length of the logenst name in students
    while (read(cin, record)) {
        // find the length of the logest name
        maxlen = max(maxlen, record.name.size());
        students.push_back(record);
    }

    // write the names and grades
    list<Student_info>::iterator s_iter = students.begin();
    while (s_iter != students.end()) {
        cout << s_iter->name << string(maxlen + 1 - s_iter->name.size(), ' ');

        // compute and write the grade
        try {
            double final_grade = grade(*s_iter);
            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade << setprecision(prec);
        } catch (domain_error e) {
            cout << e.what();
        }
        cout << endl;

        ++s_iter;
    }

    // find the students that failed
    list<Student_info> fail = extract_fails(students);
    // display the failes
    list<Student_info>::iterator iter = fail.begin();
    cout << "The students that failed are:" << endl;
    while (iter != fail.end()) {
        cout << iter->name << endl;
        ++iter;
    }

    return 0;
}
