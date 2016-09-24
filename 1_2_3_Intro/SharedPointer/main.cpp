#include <iostream>
#include "SharedPtr.h"

using namespace std;

class Person
{
public:
    Person() {}
    void test()
    {

    }
};

int main()
{

    SharedPtr<Person> s(new Person());
    SharedPtr<Person> t(new Person());
    SharedPtr<Person> g(t);
    t = s;
    cout << g.count() << endl;
    cout << t.count() << endl;
    return 0;
}