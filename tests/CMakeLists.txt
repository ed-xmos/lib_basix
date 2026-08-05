cmake_minimum_required(VERSION 3.21)
include($ENV{XMOS_CMAKE_PATH}/xcommon.cmake)
project(tests)

option(BASIX_BUILD_XC_TESTS "Build XC compatibility tests" ON)

add_subdirectory(test_basix_pass)
add_subdirectory(test_basix_fail)

if(BASIX_BUILD_XC_TESTS)
  add_subdirectory(test_basix_xc)
endif()
