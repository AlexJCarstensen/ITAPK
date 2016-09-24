//
// Created by carty on 9/7/16.
//

#ifndef EXCEPTIONS_STRING_H
#define EXCEPTIONS_STRING_H


#include <cstring>

class String
{
public:
    String() : s_(nullptr)
    {}

    String(const char *s) : s_(new char[strlen(s) + 1])
    {
        strcpy(s_, s);
    }

    String(const String &other)  : s_(new char[strlen(other.s_) + 1])
    {
        strcpy(s_, other.s_);
    }


    String &operator=(const String &other)
    {
        delete[] s_;
        s_ = new char[strlen(other.s_) + 1];
        strcpy(s_, other.s_);
        return *this;
    }

    ~String()
    {
        delete[] s_;
    }

private:
    char *s_;
};

void stringMethod()
{
    String s;
    String aCopy(s);

    s = "hellow girls";
}
#endif //EXCEPTIONS_STRING_H
