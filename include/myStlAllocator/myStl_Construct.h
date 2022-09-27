//
// Created by yixiao on 2022/9/25.
//

#ifndef MYSTL_MYSTL_CONSTRUCT_H
#define MYSTL_MYSTL_CONSTRUCT_H

#endif //MYSTL_MYSTL_CONSTRUCT_H

#include <new.h>

namespace myStl{
    template<class T1, class T2>
    inline void construct(T1 * p, const T2& value){
        new(p) T1(value);
    }


    template <Class T>
    inline void destroy(T* pointer){
        pointer->~T();
    }


    template <class ForwardIterator>
    inline void destroy(ForwardIterator first, ForwardIterator last){
        __destroy(first, last, value_type(first));
    }

    template <class ForwardIterator, class T>
    inline void __destroy(ForwardIterator first, ForwardIterator last, T*){
        typedef typename __type_traits<T>::has_trival_destructor trival_destructor;
        __destroy_aux(first, last, trival_destructor());
    }

    template <class ForwardIterator>
    inline void
    __destroy_aus(ForwardIterator first, ForwardIterator last, false_type){
        for(;first < last; ++first){
            destroy(&*first);
        }
    }

    template <class ForwardIterator>
    inline void __destroy_aux(ForwardIterator, ForwardIterator, __true_type){}

    inline void destroy(char *, char *) {}

    inline void destroy(wchar_t *, wchar_t *) {}

}