cmake_minimum_required(VERSION 3.25)
project(TP4Carnet VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(TP4_ACTIVER_SANITIZERS "Activer AddressSanitizer et UBSan" OFF)

# Options communes à toutes les cibles
add_library(tp4_options INTERFACE)
target_compile_features(tp4_options INTERFACE cxx_std_23)

if(MSVC)
    target_compile_options(tp4_options INTERFACE /W4 /permissive-)
else()
    target_compile_options(tp4_options INTERFACE
        -Wall -Wextra -Wpedantic -Wshadow -Wconversion)
endif()

if(TP4_ACTIVER_SANITIZERS AND NOT MSVC)
    target_compile_options(tp4_options INTERFACE
        -fsanitize=address,undefined -fno-omit-frame-pointer)
    target_link_options(tp4_options INTERFACE
        -fsanitize=address,undefined)
endif()

# Bibliothèque : saisie (chapitre 3) et logique du carnet
add_library(carnet_core
    src/saisie.cpp
    src/carnet.cpp)
target_include_directories(carnet_core PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(carnet_core PRIVATE tp4_options)

# Application
add_executable(carnet app/main.cpp)
target_link_libraries(carnet PRIVATE carnet_core tp4_options)
