cmake_minimum_required(VERSION 3.26)
project(Applied_Project)

set(CMAKE_CXX_STANDARD 17)

add_executable(Applied_Project main.cpp
        graph.cpp
        graphHeader.h
        Trie.h
        Trie.cpp
        LinkedList.h
        LinkedList.cpp
        AStar.h
        AStar.cpp)
