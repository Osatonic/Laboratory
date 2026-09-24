cmake_minimum_required(VERSION 4.4)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab1
        lab1/main.cpp
        lab1/Hospital.cpp
        lab1/Hospital.h
)

add_executable(lab2
        lab2/main.cpp
        lab2/List.cpp
        lab2/List.h
)

add_executable(lab3
        lab3/main.cpp
        lab3/Transport.cpp
        lab3/Transport.h
)

add_executable(lab4
        lab4/main.cpp
        lab4/TObject.cpp
        lab4/TObject.h
)

add_executable(lab4_1
        lab4_1/main.cpp
        lab4_1/TObject.cpp
        lab4_1/TObject.h
)

add_executable(lab5
        lab5/main.cpp
        lab5/List.h
        lab1/Hospital.cpp
        lab1/Hospital.h
)
