//
// Created by carty on 9/7/16.
//

#ifndef EXCEPTIONS_MYVECTOR_H
#define EXCEPTIONS_MYVECTOR_H


#include <iostream>
#include <glob.h>
#include "Test.h"

using namespace std;

template<typename T>
class MyVector
{
public:
    MyVector(size_t capacity) : capacity_(capacity), count_(0), data_(new T[capacity])
    {}

    ~MyVector()
    {
        delete[] data_;
    }

    bool full() const
    {
        return count_ == capacity_;
    }

    void push_back( const T &oneMore)
    {

        if (capacity_ > 0)
        {
            if (full())
            {
                capacity_ *= 2;

                T *newData = new T[capacity_];
                try
                {
                    copy(data_, data_ + count_, newData);

                }
                catch (exception& e)
                {
                    cout << "exception " << e.what() << endl;
                    delete[] newData;
                }
                swap(data_, newData);

                delete[] newData;
            }

        } else
            capacity_ = 1;

        data_[count_] = oneMore;
        ++count_;
    }

private:
    size_t capacity_;
    size_t count_;
    T *data_;
};

void myVectorMethod()
{
    MyVector<string> my(20);
    string s = "ss";
    my.push_back(s);
    for (int i = 0; i < 20; ++i)
    {
        my.push_back(s);
    }
}

#endif //EXCEPTIONS_MYVECTOR_H
