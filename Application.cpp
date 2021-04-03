#pragma once
#ifndef APPLICATION_H_INCLUDED
#define APPLICATION_H_INCLUDED

#include "Profil.cpp"
#include <iostream>
#include <string>

class Application
{
public:
    virtual ~Application() {};

    virtual Profil* methodeFabrique() const = 0;

    std::string creationObjet() const {
        Profil* profil = this->methodeFabrique();
        std::string resultat = "L'application nous envoie le message : " + profil->Message();
        delete profil;
        return resultat;
    }
};



#endif // APPLICATION_H_INCLUDED
