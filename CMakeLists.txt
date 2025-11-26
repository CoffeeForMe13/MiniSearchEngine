cmake_minimum_required(VERSION 3.20)
project(MiniSearchEngineForLocalTextFiles)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    "src/*.cpp"
    "src/*.h"
)

add_executable(MiniSearchEngine ${SOURCES})

