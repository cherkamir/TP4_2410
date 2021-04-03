#pragma once
#ifndef PROFILELEVE_H_INCLUDED
#define PROFILELEVE_H_INCLUDED

#include "Profil.cpp"
#include <string>

class ProfilEleve : public Profil
{
private:
    Renseignements infosProfil;
    std::string typeProfil;


public:
    ProfilEleve() = default;
    //ProfilEleve(Renseignements infosProfil, std::string typeProfil) = default;

    std::string Message() const { 
        return "{Un profil d Eleve vient d etre cree avec succes!}";
    }

    Renseignements getInfosProfil() const override {
        return this->infosProfil;
    }

    std::string getTypeProfil() const override {
        return this->typeProfil;
    }

};
#endif // !PROFILELEVE_H_INCLUDED
