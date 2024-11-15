cmake_minimum_required(VERSION 3.29)
project(newBoringAssignment)

set(CMAKE_CXX_STANDARD 20)

add_executable(newBoringAssignment main.cpp
        libraryItem/libraryItem.h
        libraryItem/libraryItem.cpp
        items/book/book.h
        items/journal/journal.h
        items/dvd/dvd.h
        items/book/book.cpp
        items/journal/journal.cpp
        items/dvd/dvd.cpp
        member/member.h
        member/member.cpp
        librarySystem/librarySystem.h
        librarySystem/librarySystem.cpp)
