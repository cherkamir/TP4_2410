#ifndef RENSEIGNEMENTS_H_INCLUDED
#define RENSEIGNEMENTS_H_INCLUDED

#include <string>

// Structure repr�sentant les informations personnelles de chaque profil
struct Renseignements
{
    std::string nom;
    std::string prenom;
    std::string telephone;
    std::string adresseDomicile;
    std::string adresseCourriel;
    
};
#endif // RENSEIGNEMENTS_H_