cmake_minimum_required(VERSION 3.5)
project(Exercise08 CXX)

# optional strict mode
if(UNIX AND STRICT)
  message("--Enabling strict compilation mode")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")
endif()

add_executable(clientcode clientcode.cpp treap.cpp treap.h)
set_property(TARGET clientcode PROPERTY CXX_STANDARD 11)

add_executable(unit_test unit_test.cpp treap.cpp treap.h)
set_property(TARGET unit_test PROPERTY CXX_STANDARD 11)