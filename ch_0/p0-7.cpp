#include <iostream>

int main() {
    /* This is a comment that extends over several lines
    because it uses /* and */ as its starting and ending delimiters */
    std::cout << "Does this work?" << std::endl;

    return 0;
}

// Does not work. Comment evaluaiton stops at first */ and the second /* is
// not evaluated at a starting point for the second /* */ comment.
