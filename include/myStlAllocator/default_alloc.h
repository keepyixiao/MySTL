//
// Created by yixiao on 2022/9/27.
//

#ifndef MYSTL_DEFAULT_ALLOC_H
#define MYSTL_DEFAULT_ALLOC_H



#include <cstddef>   // for ptrdiff_t, size_t


enum{
    ALIGN = 8
};

enum{
    MAX_BYTES = 128
};

enum{
    NFREELISTS = MAX_BYTES / ALIGN
};


class default_alloc_template{
private:
    static size_t ROUND_UP(size_t bytes){
        return ((bytes) + ALIGN - 1) & (~ (ALIGN - 1));
    }

private:
    union obj{
        union obj * free_list_link;
        char client_data[1];
    };

private:
    static obj * free_list[NFREELISTS];

    static size_t FREELIST_INDEX(size_t bytes){
        return (((bytes) + ALIGN - 1) / ALIGN - 1);
    }

    static void * refiil(size_t n);

    static char * chunk_alloc(size_t size, int &nobjs);


    static char * start_free;
    static char * end_free;
    static size_t heap_size;

public:
    static void * allocate(size_t n);

    static void deallocate(void *p, size_t n);

    static void * reallocate(void * p, size_t old_sz, size_t new_sz);

};





#endif //MYSTL_DEFAULT_ALLOC_H