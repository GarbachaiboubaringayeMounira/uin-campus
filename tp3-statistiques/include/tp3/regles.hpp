#pragma once

#include <string_view>

namespace tp3 {

/// Bornes du barème et seuil de validation.
inline constexpr double noteMin = 0.0;
inline constexpr double noteMax = 20.0;
inline constexpr double seuilValidation = 10.0;

/// Mentions attribuées selon la note.
enum class Mention { Ajourne, Passable, AssezBien, Bien, TresBien };

/// Nombre de mentions (taille du tableau de compteurs).
inline constexpr std::size_t nbMentions = 5;

/// Une note est valide si elle appartient à [noteMin ; noteMax].
constexpr bool estNoteValide(double note)
{
    return note >= noteMin && note <= noteMax;
}

/// Mention correspondant à une note.
Mention mentionPour(double note);

/// Libellé affichable d'une mention.
std::string_view libelle(Mention mention);

} // namespace tp3
