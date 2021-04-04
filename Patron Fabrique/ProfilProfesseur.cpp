#pragma once
#ifndef PROFILPROFESSEUR_H_INLCLUDED
#define PROFILPROFESSEUR_H_INCLUDED

#include "Profil.cpp"

class ProfilProfesseur : public Profil
{
private:
    Renseignements infosProfil;
    std::string typeProfil = "Professeur";
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

    void setInfosProfil(const Renseignements& infosProfil, std::string& typeProfil) override
    {
        this->infosProfil = infosProfil;
        this->typeProfil = typeProfil;
    }
    void afficher(const Renseignements& infosProfil) const override
    {
        std::cout << "Type de profil : " + this->typeProfil << std::endl;
        std::cout << "Nom: " << infosProfil.nom << "    " << "Prenom: " << infosProfil.prenom << std::endl
            << "Telephone: " << infosProfil.telephone << std::endl
            << "adresse: " << infosProfil.adresseDomicile << std::endl
            << "courriel: " << infosProfil.adresseCourriel << std::endl;
    }
};

#endif // !PROFILPROFESSEUR_H_INLCLUDED
