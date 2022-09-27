#include <iostream>
#include "include/allocator/simpleAllocator.h"
#include "include/myStlAllocator/simple_alloc.h"
#include <vector>
#include <iostream>

int main() {


    int ia[5] = {1, 2, 3, 4, 5};


    int * addr  = simple_alloc<int>::allocate(10);
    addr[0] = 1;
    addr[1] = 2;

    std::cout << addr[0] <<'\n';
    std::cout <<addr[1] << '\n';

    std::cout << std::endl;

    return 0;
}
