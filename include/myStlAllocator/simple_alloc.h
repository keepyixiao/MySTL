//
// Created by yixiao on 2022/9/26.
//

#ifndef MYSTL_SIMPLE_ALLOC_H
#define MYSTL_SIMPLE_ALLOC_H



#ifdef __USE_MALLOC

typedef __malloc_alloc_template<0> malloc_alloc;

typedef malloc_alloc alloc;

#else

#include "default_alloc.h"
#include "iostream"

typedef default_alloc_template alloc;

#endif


template <class T, class Alloc = alloc>
class simple_alloc{
public:
    typedef T value_type;
    typedef T * pointer;
    typedef const T * const_pointer;
    typedef T& reference;
    typedef const T& const_reference;
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
public:
    static T * allocate(size_t n){
        std::cout << "enter my allocate " << '\n';
        return 0 == n ? 0 : (T*)Alloc::allocate(n * sizeof(T));
    }

    static T * allocate(void){
        return (T*)Alloc::allocate(sizeof(T));
    }

    static void deallocate(T * p, size_t n){
        if(0 != n){
            Alloc::deallocate(p, n * sizeof(T));
        }
    }

    static void deallocate(T * p){
        Alloc::deallocate(p, sizeof(T));
    }
};


#endif //MYSTL_SIMPLE_ALLOC_H