cmake_minimum_required(VERSION 3.23)
project(Address_Book_System)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Address_Book_System
        src/main.cpp

        src/include/storage/Page.h
        src/include/buffer/BufferPoolManager.h
        src/include/storage/Node.h
        src/include/storage/BPlusTree.h
        src/include/executor/Table.h
        src/data/User.h
        src/menu/Menu.h
        src/data/Admin.h

        src/storage/Page.cpp
        src/buffer/BufferPoolManager.cpp
        src/storage/Node.cpp
        src/storage/BPlusTree.cpp
        src/Iterator/Iterator.cpp
        src/data/User.cpp
        src/include/disk/File.h
        src/disk/File.cpp
        src/menu/Menu.cpp
        src/data/Admin.cpp
        LICENSE
        README.md)
