#pragma once
#ifndef PROFILELEVE_H_INCLUDED
#define PROFILELEVE_H_INCLUDED

#include "Profil.cpp"
#include <string>

class ProfilEleve : public Profil
{
private:
    Renseignements infosProfil;
    std::string typeProfil = "Eleve";


public:
    ProfilEleve() = default;

    std::string Message() const { 
        return "{Un profil d Eleve vient d etre cree avec succes!}";
    }

    Renseignements getInfosProfil() const override {
        return this->infosProfil;
    }

    std::string getTypeProfil() const override {
        return this->typeProfil;
    }

    void setInfosProfil(const Renseignements& infosProfil) override {
        this->infosProfil = infosProfil;
    }
};
#endif // !PROFILELEVE_H_INCLUDED


