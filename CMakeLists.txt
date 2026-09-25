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
        lab3/Transport.cpp
        lab3/Transport.h
)

add_executable(lab5
        lab5/main.cpp
        lab5/List.h
        lab1/Hospital.cpp
        lab1/Hospital.h
)

add_executable(lab6
        lab6/main.cpp
        lab6/List.cpp
        lab6/List.h
)

add_executable(lab7_1
        lab7/main1.cpp
        lab7/TransportFile.cpp
        lab7/TransportFile.h
        lab7/Manipulator.h
)

add_executable(lab7_2
        lab7/main2.cpp
        lab7/TransportFile.cpp
        lab7/TransportFile.h
        lab7/Manipulator.h
)

add_executable(lab7_3
        lab7/main3.cpp
        lab7/TransportFile.cpp
        lab7/TransportFile.h
)

add_executable(lab7_4
        lab7/main4.cpp
        lab7/TransportFile.cpp
        lab7/TransportFile.h
)

add_executable(lab7_5
        lab7/main5.cpp
        lab7/TransportFile.cpp
        lab7/TransportFile.h
)
