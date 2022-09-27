//
// Created by yixiao on 2022/9/27.
//


#include "../../include/myStlAllocator/default_alloc.h"
#include "../../include/allocator//simpleAllocator.h"


void * default_alloc_template::allocate(size_t n ){
    obj * * my_free_list;
    obj * result;


    if(n > (size_t)MAX_BYTES){
        return ::malloc(n);
    }

    my_free_list = free_list + FREELIST_INDEX(n);

    result = *my_free_list;
    if(result == 0){
        void * r = refiil(ROUND_UP(n));
        return r;
    }

    *my_free_list = result->free_list_link;
    return result;

}


void default_alloc_template::deallocate(void *p, size_t n){
    obj * q = (obj *)p;
    obj * * my_free_list;

    if(n > (size_t)MAX_BYTES){
        return free(p);
    }

    my_free_list = free_list + FREELIST_INDEX(n);
    q->free_list_link = *my_free_list;
    *my_free_list = q;
}


void * default_alloc_template::refiil(size_t n){
    int nobj = 20;

    char * chunk = chunk_alloc(n, nobj);

    obj * * my_free_list;

    obj * result;

    obj * current_obj, * next_obj;

    if(1 == nobj){
        return chunk;
    }

    my_free_list = free_list + FREELIST_INDEX(n);

    result = (obj*)chunk;

    ///fixme : + n is right???
    *my_free_list = next_obj = (obj*)(chunk + n);
    for(int i = 1; ; ++i){
        current_obj= next_obj;
        next_obj = (obj *)((char *)next_obj + n);
        if(nobj - 1 == i){
            current_obj->free_list_link = 0;
            break;
        }else{
            current_obj->free_list_link = next_obj;
        }
    }

    return result;

}


char * default_alloc_template::chunk_alloc(size_t size, int &nobjs){
    char * result;
    size_t total_bytes = size * nobjs;

    size_t bytes_left = end_free - start_free;  // 内存池剩余空间

    if(bytes_left > total_bytes){
        result = start_free;
        start_free += total_bytes;
        return result;
    }else if(bytes_left > size){
        nobjs = bytes_left / size;
        total_bytes = size * nobjs;
        result = start_free;
        start_free += total_bytes;
        return result;
    }else{
        size_t bytes_to_get = 2 * total_bytes + ROUND_UP(heap_size >> 4);
        if(bytes_left > 0){
            obj * * my_free_list = free_list + FREELIST_INDEX(bytes_left);
            ((obj*)start_free)->free_list_link = *my_free_list;
            *my_free_list = (obj*)start_free;
        }

        start_free = (char *)malloc(bytes_to_get);

        if(0 == start_free){
            int i;
            obj ** my_free_list, * p;

            for(i = size; i < MAX_BYTES; ++i){
                my_free_list = free_list + FREELIST_INDEX(i);
                p = *my_free_list;
                if(0 != p){
                    *my_free_list = p->free_list_link;
                    start_free = (char *)p;
                    end_free = start_free + i;
                    return chunk_alloc(size, nobjs);
                }
            }
            end_free = 0;
            //fixme: should call malloc_alloc
            start_free = (char *)malloc(bytes_to_get);
        }
        heap_size += bytes_to_get;
        end_free = start_free + bytes_to_get;

        return chunk_alloc(size, nobjs);

    }


}

char * default_alloc_template::start_free = 0;

char * default_alloc_template::end_free = 0;

size_t default_alloc_template::heap_size = 0;

default_alloc_template::obj * default_alloc_template::free_list[NFREELISTS] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};



