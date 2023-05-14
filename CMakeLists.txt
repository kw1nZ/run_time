cmake_minimum_required(VERSION 3.23)
project(run_time
        DESCRIPTION "Simple header-only lib for measuring execution time"
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME} main.cpp run_time.hpp)