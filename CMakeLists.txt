cmake_minimum_required(VERSION 3.17)
project(n2Demo2)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)
include_directories(/usr/local/include/)

link_directories("/usr/local/lib" "/usr/local/opt/llvm/lib")    # import info with openmp if find openmp
include_directories("/usr/local/include" "/usr/local/opt/llvm/include")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Xpreprocessor -fopenmp -lomp -mavx2")

# link_libraries(/Users/chunel/Documents/code/cpp/n2Demo/libn2.a)    # import openblas static lib

set(SOURCE_FILES
        src/hnsw.cc
        src/heuristic.cc
        src/hnsw_build.cc
        src/hnsw_model.cc
        src/hnsw_node.cc
        src/hnsw_search.cc
        src/mmap.cc
        main.cpp)

add_executable(n2Demo2 ${SOURCE_FILES})