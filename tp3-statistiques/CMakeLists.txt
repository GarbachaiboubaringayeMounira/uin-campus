cmake_minimum_required(VERSION 3.25)
project(TP3Statistiques VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(TP3_ACTIVER_SANITIZERS "Activer AddressSanitizer et UBSan" OFF)

# Options communes à toutes les cibles
add_library(tp3_options INTERFACE)
target_compile_features(tp3_options INTERFACE cxx_std_23)

if(MSVC)
    target_compile_options(tp3_options INTERFACE /W4 /permissive-)
else()
    target_compile_options(tp3_options INTERFACE
        -Wall -Wextra -Wpedantic -Wshadow -Wconversion)
endif()

if(TP3_ACTIVER_SANITIZERS AND NOT MSVC)
    target_compile_options(tp3_options INTERFACE
        -fsanitize=address,undefined -fno-omit-frame-pointer)
    target_link_options(tp3_options INTERFACE
        -fsanitize=address,undefined)
endif()

# Bibliothèque : règles (mentions) et saisie robuste
add_library(tp3_core
    src/regles.cpp
    src/saisie.cpp)
target_include_directories(tp3_core PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(tp3_core PRIVATE tp3_options)

# Application
add_executable(statistiques app/main.cpp)
target_link_libraries(statistiques PRIVATE tp3_core tp3_options)
