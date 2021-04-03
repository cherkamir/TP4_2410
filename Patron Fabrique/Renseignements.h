
#ifndef RENSEIGNEMENTS_H_INCLUDED
#define RENSEIGNEMENTS_H_INCLUDED

#include <string>

struct Renseignements
{
    std::string nom;
    std::string prenom;
    int telephone = 0000000000;
    std::string adresseDomicile;
    std::string adresseCourriel;
    
};
#endif // RENSEIGNEMENTS_H_