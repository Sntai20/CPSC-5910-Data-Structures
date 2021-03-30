#include <iostream>
#include <fstream>

int main() {
    std::ofstream myfile;
    myfile.open ("tmpwords.txt");
    //myfile.open ("tmpwords.txt", std::ios::app);      // to append...
    myfile << "foo" << std::endl;
    myfile << "bar" << std::endl;
    myfile.close();
}
