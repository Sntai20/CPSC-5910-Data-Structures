//
// Created by Scott McMaster on 5/9/21.
//
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>

int main() {
    std::cout << "STL Demos" << std::endl;
    std::vector<int> vec;
    std::deque<int> deq;
    int findMe;

    srand(7);

    const int RANGE = 100;
    const long SIZE = 10;
    int* data = new int[SIZE];
    for (int i = 0; i < SIZE; i++) {
        int val = rand() % RANGE;
        vec.push_back(val);
        deq.push_back(val);
        findMe = val;
    }

    std::cout << "Iterate vector: ";
    for(std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
        std::cout << *it <<", ";
    }
    std::cout << std::endl;

    std::cout << "Iterate deque: ";
    for(std::deque<int>::iterator it = deq.begin(); it != deq.end(); it++) {
        std::cout << *it <<", ";
    }
    std::cout << std::endl;

    std::cout << "Go backwards: ";
    for(std::deque<int>::reverse_iterator it = deq.rbegin(); it != deq.rend(); it++) {
        std::cout << *it <<", ";
    }
    std::cout << std::endl;

    std::cout << "Use a stack: ";
    std::stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    while (!st.empty()) {
        std::cout << st.top() << ", ";
        st.pop();
    }
    std::cout << std::endl;

    std::cout << "Use a queue: ";
    std::queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    while (!q.empty()) {
        std::cout << q.front() << ", ";
        q.pop();
    }
    std::cout << std::endl;

    std::cout << "Sort: ";
    std::sort(vec.begin(), vec.end());
    for(std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
        std::cout << *it <<", ";
    }
    std::cout << std::endl;

    std::cout << "Do it desc: ";
    std::sort(vec.begin(), vec.end() , std::greater<int>());
    for(std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
        std::cout << *it <<", ";
    }
    std::cout << std::endl;

    std::cout << "Find something: ";
    std::vector<int>::iterator found = std::find(vec.begin(), vec.end(), findMe);
    if (found != vec.end()) {
        std::cout << *found;
    } else {
        std::cout << "not found";
    }
    std::cout << std::endl;

    std::cout << "Find nothing: ";
    std::vector<int>::iterator notfound = std::find(vec.begin(), vec.end(), RANGE + 100);
    if (notfound != vec.end()) {
        std::cout << *notfound;
    } else {
        std::cout << "not found";
    }
    std::cout << std::endl;

    std::cout << "Done" << std::endl;

    return 0;
}