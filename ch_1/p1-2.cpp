#include <iostream>
#include <string>

int main() {
    // Valid
    const std::string exclam = "!";
    // Invalid. The + operation has left-to-right assoaciativity so we can
    // reshape the next line like:
    // const std::string message = (("Hello" + ", world") + exclam)
    //                              \_______  ________/
    //                                      \/
    //                            This is a string literal
    // so the first + operates between two string literals which is invalid
    const std::string message = "Hello" + ", world" + exclam;

    std::cout << message <<std::endl;

    return 0;
}
