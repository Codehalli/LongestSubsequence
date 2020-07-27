cmake_minimum_required(VERSION 3.5)
project(P2 CXX)

# require a C++11 compiler for all targets
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(FILE_SOURCE
  file.hpp file.cpp)

set(LCS_SOURCE
  lcs.hpp lcs.txx)

# create student tests
add_executable(student-tests ${FILE_SOURCE} ${LCS_SOURCE} student_tests.cpp)

# create student tests
add_executable(diff ${FILE_SOURCE} ${LCS_SOURCE} diff.cpp)

add_custom_target(submission COMMAND
  ${CMAKE_COMMAND} -E tar "cfv" "${CMAKE_CURRENT_BINARY_DIR}/submission.zip" --format=zip
  ${FILE_SOURCE} lcs.hpp lcs.txx student_tests.cpp diff.cpp tests
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
