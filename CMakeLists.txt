cmake_minimum_required(VERSION 3.19)
project(MySTL)

set(CMAKE_CXX_STANDARD 14)

option(_USE_MALLOC "use malloc_alloc_template" OFF)

add_executable(MySTL main.cpp include/myVector.h lib/myVector.cpp include/allocator/simpleAllocator.h include/myStlAllocator/myStl_Construct.h include/myStlAllocator/simple_alloc.h include/myStlAllocator/default_alloc.h lib/myStlAllocator/default_alloc.cpp)