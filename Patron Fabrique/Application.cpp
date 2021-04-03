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

    Profil* creationObjet() const {
        Profil* profil = this->methodeFabrique();
        return profil;
    }
};



#endif // APPLICATION_H_INCLUDED
