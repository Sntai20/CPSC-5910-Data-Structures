#include <iostream>
#include <fstream>      // new include here

int main() {
    std::ifstream rfile;
    char line[20];  // watch the size
    rfile.open("words.txt");    // watch for the working directory when you run the project
    if (rfile.is_open()) {
        while (rfile.getline(line, 20)) {
            std::cout << line << std::endl;
        }
        rfile.close();
    }
}
