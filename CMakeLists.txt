#Specify minimum cmake version requirement
CMAKE_MINIMUM_REQUIRED(VERSION 3.1 FATAL_ERROR)

#Set compiler flags variable to allow for longer loops
set(EXTRA_COMPILE_FLAGS "-fconstexpr-steps=1000000000")

#Specify project name and languages
project(string LANGUAGES CXX)

#Option for code sanitization
#include(../Sanitizers.cmake)

#Globally include 'include' directory
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

#Create variable for cexpr_basic_string header
set(string_headers ${CMAKE_CURRENT_SOURCE_DIR}/include/ra/cexpr_basic_string.hpp)

#Create vrariable for cexpr_mandelbrot header
set(mandelbrot_headers ${CMAKE_CURRENT_SOURCE_DIR}/include/ra/mandelbrot.hpp)

#Add executable targets
add_executable(test_cexpr_basic_string ${CMAKE_CURRENT_SOURCE_DIR}/app/test_cexpr_basic_string.cpp ${string_headers})
add_executable( test_mandelbrot ${CMAKE_CURRENT_SOURCE_DIR}/app/test_mandelbrot.cpp ${mandelbrot_headers})

#Make sure mandelbrot gets compiler flags for longer loops
set_source_files_properties(${CMAKE_CURRENT_SOURCE_DIR}/app/test_mandelbrot.cpp PROPERTIES COMPILE_FLAGS ${EXTRA_COMPILE_FLAGS})

#Find Catch2 package
#find_package(Catch2 REQUIRED)

#Include Catch2 header
#include(Catch)
