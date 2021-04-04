#pragma once
#ifndef PROFILELEVE_H_INCLUDED
#define PROFILELEVE_H_INCLUDED

#include "Profil.h"
#include <string>

// Classe représentant le profil d'un élève
// implémente d'interface Profil
class ProfilEleve : public Profil
{
private:
    Renseignements infosProfil;
    std::string typeProfil = "Eleve";
public:
    ProfilEleve() = default;

    // Message de confirmation de création d'un profil d'Eleve
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

    void afficher() const override
    {
        std::cout << "Type de profil : " + this->typeProfil << std::endl;
        std::cout << "Nom: " << this->infosProfil.nom << "    " << "Prenom: " << this->infosProfil.prenom << std::endl
            << "Telephone: " <<  this->infosProfil.telephone << std::endl
            << "adresse: " << this->infosProfil.adresseDomicile << std::endl
            << "courriel: " << this->infosProfil.adresseCourriel << std::endl;
    }


};
#endif // !PROFILELEVE_H_INCLUDED


