#include <iostream>
#include <string>
#include <vector>

int main() {
    const int NO_HOMEWORKS = 3;
    std::vector<std::string> students;
    std::vector<double> grades;
    std::string name;

    std::cout << "Please give the sutend's name: ";
    while (std::cin >> name) {
        students.push_back(name);

        // ask for and read the midterm and final grades
        std::cout << "Please enter student's midterm and final exam grades:";
        double midterm, final;
        std::cin >> midterm >> final;

        // read the homeworks' grades
        std::cout << "Enter all student's homework grades: ";
        double grade;
        double sum = 0;
        for (int i = 0; i < NO_HOMEWORKS; i++) {
            std::cin >> grade;
            sum += grade;
        }

        double final_grade = 0.2 * midterm + 0.4 * final + 0.4 * sum / NO_HOMEWORKS;
        grades.push_back(final_grade);

        std::cout << std::endl;
        std::cout << "Please give the name of another student or end-of-file to exit: ";
    }

    // display the final result
    for (int i = 0; i < students.size(); i++) {
        std::cout << students[i] << " : " << grades[i] << std::endl;
    }

    return 0;
}
