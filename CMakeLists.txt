cmake_minimum_required(VERSION 3.20)

project(Moonpack VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Moonpack
        src/main.cpp
        src/file_scanner.cpp
        src/module.cpp
        src/parse.cpp
        src/file_utils.cpp
        src/lexer/lexer.cpp
        src/collector.cpp
        src/parser/parser.cpp
)