
Programme C++23 : lit les notes d'une UE (virgule décimale acceptée, valeurs hors [0 ; 20] refusées)
et affiche min, max, moyenne, écart-type, admis et histogramme par mention.

## Versions des outils (à compléter avec TES valeurs : TP2, partie A)

| Outil   | Version |
|---------|---------|
| g++ | ( ce que la commande a affiché) |
| clang++ | Ubuntu clang version 20.1.8 |
| cmake | cmake version 3.31.6 |
| ninja | 1.12.1 |
| gdb | GNU gdb ( Ubuntu 16.3-1ubuntu2) 16.3 |
| git | git version 2.51.0 |
## Construire et exécuter

    cmake --preset debug
    cmake --build --preset debug
    ./build/debug/statistiques

## Qualité

    clang-format -i include/tp3/*.hpp src/*.cpp app/*.cpp
    clang-tidy -p build/debug src/*.cpp app/*.cpp

## Structure

    include/tp3/  en-têtes (regles.hpp, saisie.hpp)
    src/          implémentations
    app/          main.cpp
