# TP5 — Réinventer std::vector, pour comprendre

Tableau dynamique écrit à la main avec `new[]` / `delete[]`, puis observation de ses dangers
avec les sanitizers (AddressSanitizer, LeakSanitizer), enfin comparaison avec `std::vector`.

## Versions des outils

| Outil   | Version |
|---------|---------|
| g++     | g++ (Ubuntu 15.2.0-4ubuntu4) 15.2.0 |
| clang++ | Ubuntu clang version 20.1.8 |
| cmake   | cmake version 3.31.6 |
| ninja   | 1.12.1 |
| gdb     | GNU gdb (Ubuntu 16.3-1ubuntu2) 16.3 |
| git     | git version 2.51.0 |

## Construire

    cmake --preset debug
    cmake --build --preset debug

## Les expériences (une cible par question du TP)

| Cible | Question | Résultat attendu |
|-------|----------|------------------|
| `./build/debug/partie_a`    | A.1 | aucun rapport ; capacités 4,4,4,4,8,8,8,8,16,16 |
| `./build/debug/a3_fuite`    | A.3 | LeakSanitizer : fuite de 128 octets (16 double) |
| `./build/debug/a4_mismatch` | A.4 | AddressSanitizer : alloc-dealloc-mismatch |
| `./build/debug/partie_b`    | B   | AddressSanitizer : attempting double-free |
| `./build/debug/partie_c`    | C   | std::vector : aucune fonction de libération, aucune erreur |

## Structure

    include/tp5/tableau.hpp   TableauDynamique, ajouter, liberer, element
    app/partie_a_b.cpp        parties A et B (macros selon la cible)
    app/partie_c.cpp          partie C (std::vector)
