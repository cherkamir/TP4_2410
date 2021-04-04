#pragma once
#ifndef PROFIL_H_INCLUDED
#define PROFIL_H_INCLUDED

#include "Renseignements.h"
#include <string>
#include <vector>
#include <iostream>
#include <memory>

// Interface Product du patron Factory Method
// Elle contient toutes les fonctionnalit�s d'un profil
class Profil
{
public:
    Profil() = default;
    // Message de confirmation de cr�ation d'un profil de Professeur / Eleve
    virtual std::string Message() const = 0;
    // M�thodes communes � tous les types de profils
    virtual Renseignements getInfosProfil() const = 0;
    virtual std::string getTypeProfil() const = 0;
    virtual void setInfosProfil(const Renseignements& infosProfil) = 0;
    virtual void afficher() const = 0;
    virtual ~Profil() = default;
};



#endif // PROFIL_H_INCLUDED

