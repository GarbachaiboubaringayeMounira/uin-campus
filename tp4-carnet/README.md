# TP4 — Carnet de notes en mode menu

Programme C++23 structuré en fonctions : tout le code (hors `main`) est dans l'espace de noms `carnet`.
Les fonctions de calcul (`calculerStatistiques`, `appliquerBonus`, `trier`) n'ont aucune entrée-sortie.

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
    ./build/debug/carnet

## Structure

    include/carnet/  en-têtes (regles.hpp, saisie.hpp, carnet.hpp)
    src/             implémentations (saisie.cpp, carnet.cpp)
    app/             main.cpp
