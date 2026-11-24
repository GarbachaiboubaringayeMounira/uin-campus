# UIN-Campus — Système de gestion académique

Projet fil rouge du cours de POO en C++ moderne (C++23).

## Versions des outils

| Outil   | Version |
|---------|---------|
| g++     | g++ (Ubuntu 15.2.0-4ubuntu4) 15.2.0 |
| clang++ | Ubuntu clang version 20.1.8 |
| cmake   | cmake version 3.31.6 |
| ninja   | 1.12.1 |
| gdb     | GNU gdb (Ubuntu 16.3-1ubuntu2) 16.3 |
| git     | git version 2.51.0 |

## Construire et exécuter

    cmake --preset debug
    cmake --build --preset debug
    ./build/debug/uin-campus
    ./build/debug/uin-campus --version
    ./build/debug/uin-campus --aide

## Qualité

    clang-format -i include/uincampus/*.hpp src/*.cpp app/*.cpp
    clang-tidy -p build/debug src/*.cpp app/*.cpp

## Structure

    include/uincampus/  version, regles, saisie, calculs
    src/                implémentations
    app/                main.cpp
