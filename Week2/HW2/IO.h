//
// Created by Antonio Santana on 4/18/21.
//
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include <list>

#ifndef HW2_IO_H
#define HW2_IO_H
class IO{
public:
    static std::list<std::string> ProcessFile(const std::string& inputFilePath);
};

#endif //HW2_IO_H
