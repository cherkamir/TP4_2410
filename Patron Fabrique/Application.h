#pragma once
#ifndef APPLICATION_H_INCLUDED
#define APPLICATION_H_INCLUDED

#include "Profil.h"
#include "ProfilProfesseur.h"
#include "ProfilEleve.h"
#include <iostream>
#include <string>

// Classe abstraite Creator du patron Factory Method
// D�legue la resposabilit� de cr�er des profils (Products) aux classes d�riv�es 
class Application
{
public:
    virtual ~Application() = default;

    // M�thode virtuelle pure impl�ment�e par les classes d�riv�es AppProfesseur et AppEleve

    virtual std::unique_ptr<Profil> methodeFabrique() const = 0;

    // Cree un profil via methodeFabrique() et renvoi un message de confirmation
    std::string creationObjet() const {
        std::unique_ptr<Profil> profil = this->methodeFabrique();
        std::string phrase = "L Application PolyPiano vous envoie le message suivant:   " + profil->Message();
        return phrase;
    }
};

// Classe ConcreteCreator du patron Factory Method 
// elle se charge de cr�er un profil de Professeur
class AppProfesseur : public Application
{
public:
    // Cr�e un renvoie un pointeur de profil de Professeur
    std::unique_ptr<Profil> methodeFabrique() const override
    {
        return  std::make_unique<ProfilProfesseur>();
    }

};

// Classe ConcreteCreator du patron Factory Method 
// elle se charge de cr�er un profil d'Eleve
class AppEleve : public Application
{
public:
    // Cr�e et renvoie un profil d'Eleve 
    std::unique_ptr<Profil> methodeFabrique() const override
    {
        return std::make_unique<ProfilEleve>();
    }
};


#endif // APPLICATION_H_INCLUDED
