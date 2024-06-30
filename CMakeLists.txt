cmake_minimum_required(VERSION 3.28)
project(The_Feed)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(.circleci)
include_directories(src)

add_executable(The_Feed
        .circleci/config.yml
        src/main.cpp
        .gitignore
        build.bat
        build.sh
        README.md
        test/tests.cpp)

# Catch 2, unit test framework
add_executable(tests test/tests.cpp
        test/catch/catch_amalgamated.hpp
        test/catch/catch_amalgamated.cpp)