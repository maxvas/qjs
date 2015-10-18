cmake_minimum_required(VERSION 2.6.4)
set(PROJECT qjs)

project(${PROJECT})

find_package( Qt5 REQUIRED COMPONENTS Core)

add_definitions( -DQJS_LIBRARY )

SET (SOURCES
    qjs.cpp
    qjsleakstest.cpp
    qjsmapping.cpp
    qjssharednode.cpp
)

SET (HEADERS
    qjs.h
    qjs_global.h
    qjsleakstest.h
    qjsmapping.h
	qjssharednode.h
)

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR})
SET (MOC_SOURCES )
qt5_wrap_cpp (MOC_SOURCES ${HEADERS})

add_library ( ${PROJECT} SHARED ${HEADERS} ${SOURCES} ${MOC_SOURCES})

qt5_use_modules(${PROJECT} Core)

install(TARGETS ${PROJECT} DESTINATION ${CMAKE_BINARY_DIR}/bin)
