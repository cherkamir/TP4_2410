#pragma once
#ifndef PROFIL_H_INCLUDED
#define PROFIL_H_INCLUDED

#include "Renseignements.h"
#include <string>
#include <vector>
#include <iostream>
#include <memory>

class Profil
{
public:
    Profil() = default;

    virtual std::string Message() const = 0;
    virtual Renseignements getInfosProfil() const = 0;
    virtual std::string getTypeProfil() const = 0;
    virtual void setInfosProfil(const Renseignements& infosProfil) = 0;
    virtual void afficher(const Renseignements& infosProfil) const = 0;
    virtual ~Profil() = default;
};



#endif // PROFIL_H_INCLUDED

