#include <iostream>
#include <string>       // new include here

int main() {
    std::string s("foobar");
    std::string t = "hello";

    std::cout << s << std::endl;
    std::cout << t << std::endl;

    std::cout << "Equal: " << (s == "foobar") << std::endl;
    std::cout << "Compare: " << (s < t) << std::endl;

    // by character
    for (long unsigned int i = 0; i < s.length(); i++) {
        std::cout << s[i] << std::endl;
    }
    return 0;
}
