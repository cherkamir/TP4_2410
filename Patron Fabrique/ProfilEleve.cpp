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

    void setInfosProfil(const Renseignements& infosProfil, std::string& typeProfil) override {
        this->infosProfil = infosProfil;
        this->typeProfil = typeProfil;
    }

    void afficher(const Renseignements& infosProfil) const override
    {
        std::cout << "Type de profil : " + this->typeProfil << std::endl;
        std::cout << "Nom: " << infosProfil.nom << "    " << "Prenom: " << infosProfil.prenom << std::endl
            << "Telephone: " <<  infosProfil.telephone << std::endl
            << "adresse: " << infosProfil.adresseDomicile << std::endl
            << "courriel: " << infosProfil.adresseCourriel << std::endl;
    }


};
#endif // !PROFILELEVE_H_INCLUDED


