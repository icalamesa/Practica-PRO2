cmake_minimum_required(VERSION 3.0)
project("Evaluator" VERSION 0.1 LANGUAGES CXX)

include_directories("${CMAKE_SOURCE_DIR/src/*}")

add_compile_options(-D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11)

add_subdirectory(src/include)
add_subdirectory(src/platform) 
add_subdirectory(src/bin)
