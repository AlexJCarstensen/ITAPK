//
// Created by matth on 31-08-2016.
//

#ifndef SHAREDPOINTER_SHAREDPTR_H
#define SHAREDPOINTER_SHAREDPTR_H

#include <iostream>

using namespace std;

template<typename T>
class SharedPtr {
public:
    SharedPtr(T *t) {
        _ptr = t;
        _count = new size_t(1);

        cout << "Shared 1\n";
    }

    SharedPtr(const SharedPtr &sp) {
        _ptr = sp._ptr;
        _count = sp._count;
        ++_count;
        cout << "Shared 2\n";

    }

    SharedPtr &operator=(const SharedPtr &sp) {
        cout << "= operator\n";

        if (this != &sp) {
            if (*_count == 0) {
                delete _ptr;
                delete _count;
            }

            _ptr = sp._ptr;
            _count = sp._count;
            ++*_count;
        }
        return *this;
    }

    ~SharedPtr() {
        cout << "Destructor called\n";

        --*_count;

        if (*_count == 0) {
            delete _ptr;
            delete _count;
        }

    }

    T &operator*() const {
        return *_ptr;
    }

    T *operator->() const {
        return _ptr;
    }

    size_t const count() {
        return *_count;
    }

private:
    T *_ptr;
    size_t *_count;
};

#endif //SHAREDPOINTER_SHAREDPTR_H
