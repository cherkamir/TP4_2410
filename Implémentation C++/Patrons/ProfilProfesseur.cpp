#pragma once
#ifndef PROFILPROFESSEUR_H_INLCLUDED
#define PROFILPROFESSEUR_H_INCLUDED

#include "Profil.cpp"

class ProfilProfesseur : public Profil
{
private:
    Renseignements infosProfil;
    std::string typeProfil;
    // vector<Eleve> listeEleve;

public:
    ProfilProfesseur() = default;

    std::string Message() const
    {
        return "{Une profil de Professeur vient d etre cree avec succes!}";
    }

    Renseignements getInfosProfil() const override
    {
        return this->infosProfil;
    }

    std::string getTypeProfil() const override
    {
        return this->typeProfil;
    }

};

#endif // !PROFILPROFESSEUR_H_INLCLUDED
