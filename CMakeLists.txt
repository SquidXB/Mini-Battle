
cmake_minimum_required(VERSION 4.0)
project(MiniBattle VERSION 0.1.0 LANGUAGES CXX)

add_executable(MiniBattle main.cpp src/Player.cpp src/Enemy.cpp src/Battle.cpp src/Utils.cpp)

include(CTest)
enable_testing()

set_property(TARGET MiniBattle PROPERTY CXX_STANDARD 20)