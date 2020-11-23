#include <iostream>
#include <string>

int main() {
    // Valid
    const std::string hello = "Hello";
    // Valid. The + operation has left-to-right assoaciativity so we can
    // reshape the next line like:
    // const std::string message = ((hello + ", world") + "!")
    //                              \_______  ________/
    //                                      \/
    //                            converted to std::string
    // so the second + does not operate between two two literals
    const std::string message = hello + ", world" + "!";

    std::cout << message << std::endl;

    return 0;
}
