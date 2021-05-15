cmake_minimum_required(VERSION 3.5)
project(Evaluator CXX)

include_directories("bin" "platform" "include")

add_compile_options(-D_JUDGE_ -D_GLIBCXX_DEBUG -Wall -Wextra -Wno-sign-compare -std=c++11)

add_subdirectory(platform) 
add_subdirectory(bin)


