#include "tp3/regles.hpp"
#include "tp3/saisie.hpp"

#include <algorithm>
#include <array>
#include <cmath>
#include <format>
#include <print>
#include <string>
#include <vector>

int main()
{
    const std::string ue = tp3::lireTexte("Nom de l'UE : ");
    const int nb = tp3::lireEntier("Nombre d'étudiants (1 à 200) : ", 1, 200);

    std::vector<double> notes;
    for (int i{1}; i <= nb; ++i) {
        notes.push_back(tp3::lireNote(std::format("Note de l'étudiant {} : ", i)));
    }

    // Première passe : minimum, maximum, somme, admis, répartition par mention
    double minimum{tp3::noteMax};
    double maximum{tp3::noteMin};
    double somme{0.0};
    int admis{0};
    std::array<int, tp3::nbMentions> repartition{};

    for (double n : notes) {
        minimum = std::min(minimum, n);
        maximum = std::max(maximum, n);
        somme += n;
        if (n >= tp3::seuilValidation) { ++admis; }
        ++repartition[static_cast<std::size_t>(tp3::mentionPour(n))];
    }

    const double taille = static_cast<double>(notes.size());
    const double moyenne = somme / taille;

    // Deuxième passe : écart-type  sigma = sqrt( somme((x - moyenne)^2) / n )
    double sommeEcarts{0.0};
    for (double n : notes) {
        sommeEcarts += (n - moyenne) * (n - moyenne);
    }
    const double ecartType = std::sqrt(sommeEcarts / taille);

    // Affichage
    std::println("\nStatistiques — {} ({} étudiants)", ue, nb);
    std::println("{:-<58}", "");
    std::println("{:<18}: {:7.2f}", "Note minimale", minimum);
    std::println("{:<18}: {:7.2f}", "Note maximale", maximum);
    std::println("{:<18}: {:7.2f}", "Moyenne", moyenne);
    std::println("{:<18}: {:7.2f}", "Écart-type", ecartType);
    std::println("{:<18}: {:7} ({:.1f} %)", "Admis", admis, 100.0 * admis / taille);

    std::println("\nRépartition par mention");
    for (std::size_t i{0}; i < tp3::nbMentions; ++i) {
        const auto mention = static_cast<tp3::Mention>(i);
        const auto effectif = static_cast<std::size_t>(repartition[i]);
        std::println("{:<12} {} ({})", tp3::libelle(mention), std::string(effectif, '*'), effectif);
    }
}
