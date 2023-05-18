cmake_minimum_required(VERSION 3.25)
project(A2_SimpleNavigator_v1_0_0)

set(CMAKE_CXX_STANDARD 17)

include_directories(src/interface
                    src/lib)

set(SOURCE_FILES src/main.cc src/interface/interface.cpp src/lib/s21_graph.cpp src/lib/s21_graph_algorithms.cpp)
add_executable(A2_SimpleNavigator_v1_0_0 ${SOURCE_FILES})

if (CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-c++11-extensions")
endif()