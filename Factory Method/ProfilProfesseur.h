#pragma once
#ifndef PROFILPROFESSEUR_H_INLCLUDED
#define PROFILPROFESSEUR_H_INCLUDED

#include "Profil.h"

class ProfilProfesseur : public Profil
{
private:
    Renseignements infosProfil;
    std::string typeProfil = "Professeur";
    // vector<Eleve> listeEleve;
public:
    ProfilProfesseur() = default;

    // Message de confirmation de cr�ation d'un profil d'Eleve
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

    void setInfosProfil(const Renseignements& infosProfil) override
    {
        this->infosProfil = infosProfil;
     
    }
    void afficher() const override
    {
        std::cout << "Type de profil : " + this->typeProfil << std::endl;
        std::cout << "Nom: " << this->infosProfil.nom << "    " << "Prenom: " << this->infosProfil.prenom << std::endl
            << "Telephone: " << this->infosProfil.telephone << std::endl
            << "adresse: " << this->infosProfil.adresseDomicile << std::endl
            << "courriel: " << this->infosProfil.adresseCourriel << std::endl;
    }
};

#endif // !PROFILPROFESSEUR_H_INLCLUDED
