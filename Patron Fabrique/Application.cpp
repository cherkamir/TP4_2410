#pragma once
#ifndef APPLICATION_H_INCLUDED
#define APPLICATION_H_INCLUDED

#include "Profil.cpp"
#include "ProfilProfesseur.cpp"
#include "ProfilEleve.cpp"
#include <iostream>
#include <string>


class Application
{
public:
    virtual ~Application() = default;

    virtual std::unique_ptr<Profil> methodeFabrique() const = 0;

    std::string creationObjet() const {
        std::unique_ptr<Profil> profil = this->methodeFabrique();
        std::string phrase = "L Application PolyPiano vous envoie le message suivant:   " + profil->Message();
        return phrase;
    }
};


class AppProfesseur : public Application
{
public:
    std::unique_ptr<Profil> methodeFabrique() const override
    {
        return  std::make_unique<ProfilProfesseur>();
    }

};


class AppEleve : public Application
{
public:
    std::unique_ptr<Profil> methodeFabrique() const override
    {
        return std::make_unique<ProfilEleve>();
    }
};


#endif // APPLICATION_H_INCLUDED
