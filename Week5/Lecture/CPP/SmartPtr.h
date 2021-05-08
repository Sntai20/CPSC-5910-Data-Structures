//
// Created by Scott McMaster on 4/28/2021.
//

#ifndef CPP_SMARTPTR_H
#define CPP_SMARTPTR_H

#include <iostream>

template <class T>
class SmartPtr {
public:
    SmartPtr(T* d) {
        std::cerr << "owning " << d << std::endl;
        std::cerr.flush();
        data = d;
    }

    ~SmartPtr() {
        std::cerr << "deleting " << data << std::endl;
        std::cerr.flush();
        delete data;
    }

    T& operator*() {
        return *data;
    }

    T* operator->() {
        return data;
    }

private:
    T* data;
};

#endif //CPP_SMARTPTR_H
