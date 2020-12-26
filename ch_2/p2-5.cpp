#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::cin;

// The square dimmension must be even
void display_square(int dim) {
    for (int i = 0; i < dim/2; i++) {
        for (int j = 0; j < dim; j++) {
            if (i == 0 || i == ((dim / 2) - 1)) {
                // draw the upper and the lower square lines
                cout << "*";
            } else {
                if (j == 0 || j == (dim - 1)) {
                    // draw one * for the left for right square lines
                    cout << "*";
                } else {
                    cout << " ";
                }
            }
        }
        cout << endl;
    }
}

// The rectangle dimmension must be even
void display_rectangle(int dim) {
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < (dim / 2); j++) {
            if (i == 0 || i == (dim - 1)) {
                // draw the upper and the lower square lines
                cout << "*";
            } else {
                if (j == 0 || j == ((dim / 2) - 1)) {
                    // draw one * for the left for right square lines
                    cout << "*";
                } else {
                    cout << " ";
                }
            }
        }
        cout << endl;
    }

}

// The triangle dimmension must be odd
void display_triangle(int dim) {
    int first_star_pos = 1;
    int second_star_pos = dim - 2; 
    string base(dim, '*');

    cout << base << endl;
    while (first_star_pos <= second_star_pos) {
        for (int i = 0; i < dim; i++) {
            if (i == first_star_pos || i == second_star_pos) {
                cout << "*";
            }
            else {
                cout << " ";
            }
        }
        first_star_pos++;
        second_star_pos--;
        cout << endl;
    }
}

int main() {
    // ask for the square dimmension
    cout << "Please give the square dimmension:";

    // save the input
    int s_dim;
    cin >> s_dim;

    display_square(s_dim);


    // ask for the rectangle dimmension
    cout << "Please give the rectangle dimmension:";

    // save the input
    int r_dim;
    cin >> r_dim;

    display_rectangle(r_dim);

    // ask for the triangle dimmension
    cout << "Please give the triangle dimmension:";

    // save the input
    int t_dim;
    cin >> t_dim;

    display_triangle(t_dim);

    return 0;
}
