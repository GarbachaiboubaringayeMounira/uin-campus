#pragma once

#include <string>
#include <string_view>

namespace tp3 {

/// Lit une ligne de texte (espaces compris).
std::string lireTexte(std::string_view invite);

/// Lit un entier compris entre min et max ; redemande tant que la saisie est invalide.
int lireEntier(std::string_view invite, int min, int max);

/// Lit une note dans [0 ; 20] ; accepte la virgule décimale (12,5).
double lireNote(std::string_view invite);

} // namespace tp3
