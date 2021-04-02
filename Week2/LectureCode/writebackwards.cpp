#include <iostream>
#include <string>

int numCalls = 0;

void writeBackwards(std::string s) {
    int length = s.size();
    if (length > 0) {
        std::cout << s.substr(length - 1, 1);
        writeBackwards(s.substr(0, length - 1));
    }
}

int main() {
    writeBackwards("scott");
    return 0;
}
