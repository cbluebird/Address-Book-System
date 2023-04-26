cmake_minimum_required(VERSION 3.23)
project(Address_Book_System)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Address_Book_System
        src/main.cpp
        src/BPTree.cpp
        include/BPTree.h
        include/BufferPoolManager.h
        include/Page.h
        include/File.h
        include/BPlusTree.h
        include/BPlusTreePage.h
        src/BufferPoolManager.cpp
        src/BPlusTree.cpp
        LICENSE
        README.md)
