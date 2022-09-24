#include <iostream>
#include "include/allocator/simpleAllocator.h"
#include <vector>
#include <iostream>

int main() {

    int ia[5] = {0, 1, 2, 3, 4};
    unsigned int i;

    std::vector<int, mystl::allocator<int> > iv(ia, ia+5);

    for(int i = 0; i < iv.size(); ++i){
        std::cout << iv[i] << ' ';
    }
    std::cout << std::endl;

    return 0;
}
