#pragma once

namespace carnet {

/// Bornes du barème et seuil de validation.
inline constexpr double noteMin = 0.0;
inline constexpr double noteMax = 20.0;
inline constexpr double seuilValidation = 10.0;

/// Une note est valide si elle appartient à [noteMin ; noteMax].
constexpr bool estNoteValide(double note)
{
    return note >= noteMin && note <= noteMax;
}

} // namespace carnet
