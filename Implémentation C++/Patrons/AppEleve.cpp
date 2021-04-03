#pragma once
#ifndef APPELEVE_H_INCLUDED
#define APPELEVE_H_INCLUDED

#include <string>
#include "Application.cpp"
#include "Profil.cpp"
#include "ProfilEleve.cpp"

class AppEleve : public Application
{
public:
    Profil* methodeFabrique() const override{
        return new ProfilEleve();
    }
};

#endif // !APPELEVE_H_INCLUDED
