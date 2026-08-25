cmake_minimum_required(VERSION 3.10)
project(emdL1 CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(emdL1_test emdL1_test.cpp emdL1.cpp)

add_subdirectory(sandbox)
