cmake_minimum_required(VERSION 3.5)

project(WIN_CGR)

set(SOURCES
    Source.cpp
    CGR.cpp
    Layout.cpp
    Cursor.cpp
    Screen.cpp
)

set(HEADERS
    CGR.h
    Layout.h 
    Cursor.h 
    Screen.h 
)


add_executable(CGR ${SOURCES} ${HEADERS})

set_target_properties (
    CGR PROPERTIES
    CXX_STANDART 11
    CXX_STANDART_REQUIRED ON
)