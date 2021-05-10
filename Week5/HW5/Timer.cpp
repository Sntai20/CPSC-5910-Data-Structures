//
// Created by Antonio Santana on 5/10/21.
//
#include <iostream>
#include <string>
#include "Timer.h"

void doSomething() {
    Timer doSomethingTimer("doSomething");

    for (int i = 0; i < 10000000; i++) {

    }
}

int main() {
    Timer mainTimer("main");

    doSomething();

    for (int i = 0; i < 10000000; i++) {

    }
    return 0;
}