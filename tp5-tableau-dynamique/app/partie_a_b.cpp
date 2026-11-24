// Parties A et B du TP5. Le comportement change selon les macros définies par CMake :
//   (aucune)              A.1 : programme correct
//   TP5_SANS_LIBERER      A.3 : l'appel à liberer() est supprimé -> fuite mémoire
//   TP5_DELETE_SIMPLE     A.4 : delete au lieu de delete[]       -> alloc-dealloc-mismatch
//   TP5_COPIE             B   : copie superficielle              -> double libération

#include "tp5/tableau.hpp"

#include <print>

int main()
{
    tp5::TableauDynamique notes;
    for (int i{0}; i < 10; ++i) {
        tp5::ajouter(notes, 10.0 + i);
        std::println("taille {:>2}, capacité {:>2}", notes.taille, notes.capacite);
    }
    std::println("premier élément : {}", tp5::element(notes, 0));

#ifdef TP5_COPIE
    tp5::TableauDynamique copie = notes; // copie membre par membre : MÊME pointeur
    tp5::liberer(copie);
#endif

#ifndef TP5_SANS_LIBERER
    tp5::liberer(notes);
#endif
}
