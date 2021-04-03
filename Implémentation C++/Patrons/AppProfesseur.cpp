#pragma once
#ifndef APPPROFESSEUR_H_INCLUDED
#define APPPROFESSEUR_H_INCLUDED

#include <string>
#include "Application.cpp"
#include "ProfilProfesseur.cpp"

class AppProfesseur : public Application
{
public:
    Profil* methodeFabrique() const override
    {
        return new ProfilProfesseur();
    }

};

#endif // !APPPROFESSEUR_H_INCLUDED