cmake_minimum_required(VERSION 3.10.0)
project(KKMBackend VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(KKMBackend src/main.cpp src/Recipe.cpp)

target_include_directories(KKMBackend PRIVATE
    ${CMAKE_SOURCE_DIR}/include/KKMBackend
)
