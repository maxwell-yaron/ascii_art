cmake_minimum_required(VERSION 2.8)
project(ascii_art)
set(CMAKE_CXX_FLAGS "-std=c++11")
find_package( OpenCV REQUIRED )
add_library(ascii ascii_art.cpp)
add_executable( example example.cpp )
target_link_libraries( example ${OpenCV_LIBS} ascii)
