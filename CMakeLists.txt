
cmake_minimum_required(VERSION 3.22)
project(neo_font_editor)

add_library(
    neo_font_lib
    STATIC
    src/NeoCharacter.cc
    src/NeoCharacterEncoding.cc
    src/NeoFont.cc
    )

target_include_directories(
    neo_font_lib
    PUBLIC
    include
    PRIVATE
    src
    )

add_executable(
    neo_font_test
    test/test_main.cpp
    )

target_link_libraries(
    neo_font_test
    neo_font_lib
    )

target_compile_features(
    neo_font_lib
    PUBLIC
    cxx_std_17)
