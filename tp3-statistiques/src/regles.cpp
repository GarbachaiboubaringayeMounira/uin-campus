#include "tp3/regles.hpp"

namespace tp3 {

Mention mentionPour(double note)
{
    if (note < seuilValidation) { return Mention::Ajourne; }
    if (note < 12.0) { return Mention::Passable; }
    if (note < 14.0) { return Mention::AssezBien; }
    if (note < 16.0) { return Mention::Bien; }
    return Mention::TresBien;
}

std::string_view libelle(Mention mention)
{
    using enum Mention;
    switch (mention) {
    case Ajourne: return "Ajourné";
    case Passable: return "Passable";
    case AssezBien: return "Assez bien";
    case Bien: return "Bien";
    case TresBien: return "Très bien";
    }
    return "Inconnue";
}

} // namespace tp3
