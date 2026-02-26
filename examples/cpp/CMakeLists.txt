cmake_minimum_required(VERSION 3.16)

project(cpp_preproc_example LANGUAGES CXX)

add_executable(cpp_preproc src/main.cpp)
target_compile_features(cpp_preproc PRIVATE cxx_std_20)

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
  target_compile_options(cpp_preproc PRIVATE -Wall -Wextra -Wpedantic)
elseif(MSVC)
  target_compile_options(cpp_preproc PRIVATE /W4)
endif()
