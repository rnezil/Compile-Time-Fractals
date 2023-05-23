#Specify minimum cmake version requirement
CMAKE_MINIMUM_REQUIRED(VERSION 3.1 FATAL_ERROR)

#Specify project name and languages
project(string LANGUAGES CXX)

#Option for code sanitization
#include(../Sanitizers.cmake)

#Globally include 'include' directory
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

#Create variables for cexpr_basic_string header
set(string_headers ${CMAKE_CURRENT_SOURCE_DIR}/include/ra/cexpr_basic_string.hpp)

#Add executable target
add_executable(test_cexpr_basic_string ${CMAKE_CURRENT_SOURCE_DIR}/app/test_cexpr_basic_string.cpp ${string_headers})

#Find Catch2 package
find_package(Catch2 REQUIRED)

#Include Catch2 header
include(Catch)
