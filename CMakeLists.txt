cmake_minimum_required (VERSION 3.2) # require at least version 3.2 of cmake
project (seqan3_infrastructure_tutorial CXX) # this is a c++-only project
set(SeqAn3_DIR "${CMAKE_SOURCE_DIR}/../seqan3/build_system")
find_package (SeqAn3 REQUIRED)

#set (CMAKE_CXX_FLAGS "-g -fopenmp -pthread")
set (CMAKE_CXX_FLAGS "-pthread -std=c++17")

add_executable(testOSS testOSS.cpp)
#add_executable(factorial_test factorial_test.cpp)
target_link_libraries (testOSS seqan3::seqan3)

