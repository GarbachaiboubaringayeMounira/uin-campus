#pragma once

#include <cassert>
#include <cstddef>

namespace tp5 {

/// Tableau dynamique « à la C » : pointeur brut + taille + capacité.
struct TableauDynamique {
    double* donnees{nullptr};
    std::size_t taille{0};
    std::size_t capacite{0};
};

/// Ajoute une valeur ; double la capacité (4 au départ) quand le tableau est plein.
inline void ajouter(TableauDynamique& t, double valeur)
{
    if (t.taille == t.capacite) {
        const std::size_t nouvelleCapacite = (t.capacite == 0) ? 4 : t.capacite * 2;
        double* nouveau = new double[nouvelleCapacite]; // 1. nouveau tableau plus grand
        for (std::size_t i{0}; i < t.taille; ++i) {
            nouveau[i] = t.donnees[i]; // 2. recopie des éléments existants
        }
#ifdef TP5_DELETE_SIMPLE
        delete t.donnees; // ERREUR VOLONTAIRE (A.4) : new[] doit être libéré par delete[]
#else
        delete[] t.donnees; // 3. libération de l'ancien tableau
#endif
        t.donnees = nouveau; // 4. le pointeur désigne le nouveau tableau
        t.capacite = nouvelleCapacite; // 5. mise à jour de la capacité
    }
    t.donnees[t.taille] = valeur;
    ++t.taille;
}

/// Libère la mémoire et remet la structure à zéro.
inline void liberer(TableauDynamique& t)
{
#ifdef TP5_DELETE_SIMPLE
    delete t.donnees; // ERREUR VOLONTAIRE (A.4)
#else
    delete[] t.donnees;
#endif
    t.donnees = nullptr;
    t.taille = 0;
    t.capacite = 0;
}

/// Accès à l'élément i.
/// @pre i < t.taille
[[nodiscard]] inline double& element(TableauDynamique& t, std::size_t i)
{
    assert(i < t.taille && "element() : indice hors limites");
    return t.donnees[i];
}

} // namespace tp5
