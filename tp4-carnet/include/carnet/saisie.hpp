#pragma once

#include <string>
#include <string_view>

namespace carnet {

/// Lit une ligne de texte (espaces compris).
[[nodiscard]] std::string lireTexte(std::string_view invite);

/// Lit un entier compris entre min et max ; redemande tant que la saisie est invalide.
[[nodiscard]] int lireEntier(std::string_view invite, int min, int max);

/// Lit une note dans [0 ; 20] ; accepte la virgule décimale (12,5).
[[nodiscard]] double lireNote(std::string_view invite);

} // namespace carnet
