
cmake_minimum_required(VERSION 3.22)
project(neo_font_editor)

add_executable(
    neo_font_editor
    NeoCharacter.cc
    NeoCharacterEncoding.cc
    NeoFont.cc
    PresetFonts.cc
    main.cpp
    )

target_compile_features(neo_font_editor PRIVATE cxx_std_17)
