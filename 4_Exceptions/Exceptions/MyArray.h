//
// Created by carty on 9/7/16.
//

#ifndef EXCEPTIONS_MYARRAY_H
#define EXCEPTIONS_MYARRAY_H

#include <iostream>
#include <glob.h>
#include "Test.h"

using namespace std;
template <typename  T, size_t N>
class MyArray
{
public:
    T& operator[](size_t i)
    {
        return data_[i];
    }

private:
    T data_[N];

};

void myArrayMethod()
{
    MyArray<string, 10> my;
    string t = "ss";
    my[5] = t;
}
#endif //EXCEPTIONS_MYARRAY_H
