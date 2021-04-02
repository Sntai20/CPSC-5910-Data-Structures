#include <iostream>
#include <string>

template <class T>
T mymax(T first, T second) {
    if (first > second) {
        return first;
    }
    return second;
}

int main() {
    std::cout << mymax(6, 9) << std::endl;
    std::cout << mymax('A', 'Z') << std::endl;;
    std::cout << mymax('Z', 'A') << std::endl;;
    std::cout << mymax(std::string("aaa"), std::string("zzz")) << std::endl;;
    return 0;
}
