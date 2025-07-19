cmake_minimum_required(VERSION 3.20...3.24)


project(
  LetThereBeLight
  VERSION 0.0.1
  LANGUAGES CXX
)



set(CMAKE_CXX_STANDARD 20)          # C++20
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(BUILD_TESTING)
  add_subdirectory(tests)
endif()


add_subdirectory(src)