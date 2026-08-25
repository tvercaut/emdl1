cmake_minimum_required(VERSION 3.10)
project(emdL1 CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(emdL1_test emdL1_test.cpp emdL1.cpp)

add_executable(emdl1_sandbox sandbox/emdl1_sandbox.cpp emdL1.cpp)
target_include_directories(emdl1_sandbox PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/sandbox)
