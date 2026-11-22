#pragma once

#include <vector>

namespace carnet {

enum class Ordre { Croissant, Decroissant };

/// Résultat des calculs statistiques (renvoyé par valeur).
struct Statistiques {
    double minimum{};
    double maximum{};
    double moyenne{};
    int nbValidees{};
};

// ---------- Calculs : aucune entrée-sortie ----------

/// @pre notes n'est pas vide
[[nodiscard]] Statistiques calculerStatistiques(const std::vector<double>& notes);

/// Ajoute bonus à chaque note, en gardant le résultat dans [0 ; 20].
void appliquerBonus(std::vector<double>& notes, double bonus);

/// Trie les notes dans l'ordre demandé.
void trier(std::vector<double>& notes, Ordre ordre);

// ---------- Interface utilisateur (une fonction par option du menu) ----------

void ajouter(std::vector<double>& notes);
void afficherNotes(const std::vector<double>& notes);
void modifier(std::vector<double>& notes);
void supprimer(std::vector<double>& notes);
void menuTrier(std::vector<double>& notes);
void afficherStatistiques(const std::vector<double>& notes);
void menuBonus(std::vector<double>& notes);

/// Affiche le menu et renvoie le choix de l'utilisateur (0 à 7).
[[nodiscard]] int afficherMenu();

} // namespace carnet
