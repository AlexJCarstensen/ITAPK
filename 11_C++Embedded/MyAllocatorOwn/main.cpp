#include <iostream>
//#include "SmallObjectAllocator.h"
#include "SmallObjectHeap.h"

int main() {

    SmallObjectHeap<3>::Instance().allocate();

    std::cout << "Hello, World!" << std::endl;
    return 0;
}