cmake_minimum_required(VERSION 3.23)
project(Address_Book_System)


set(CMAKE_CXX_STANDARD 14)
set(SCR_LIST
        src/main.cpp
        src/storage/Page.cpp
        src/buffer/BufferPoolManager.cpp
        src/storage/Node.cpp
        src/storage/BPlusTree.cpp
        src/Iterator/Iterator.cpp
        src/data/User.cpp
        src/disk/File.cpp
        src/menu/Menu.cpp
        src/data/Admin.cpp
        )

include_directories(.)

add_executable(Address_Book_System
        ${SCR_LIST}
        )

target_include_directories(Address_Book_System
        PRIVATE
        ${PROJECT_SOURCE_DIR}/include
        )
