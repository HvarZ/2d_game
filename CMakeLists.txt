cmake_minimum_required(VERSION 3.17)
project(2d_game)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES
        sources/main.cpp
        )

set(HEADERS
        include/boss.hpp
        include/hero.hpp
        )

find_package(SFML 2.5.1 COMPONENTS graphics audio REQUIRED)

add_executable(2d_game ${SOURCES})

target_include_directories(2d_game
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(2d_game sfml-graphics sfml-audio)
