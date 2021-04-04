#define CATCH_CONFIG_MAIN  //  This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"
#include "Application.h"
#include "Profil.h"
#include "ProfilEleve.h"
#include "ProfilProfesseur.h"


using namespace std;

Renseignements Client(const Profil& profil)
{
    cout << "Rentrez dans l ordre votre nom, prenom, telephone, adresseDomicile et votre adresseCourriel:" << endl;
    Renseignements infosProfil;

    getline(cin, infosProfil.nom, '\n');
    getline(cin, infosProfil.prenom, '\n');
    getline(cin, infosProfil.telephone, '\n');
    getline(cin, infosProfil.adresseDomicile, '\n');
    getline(cin, infosProfil.adresseCourriel, '\n');
    //cout << endl;
    return infosProfil;
    //profil.afficher(infosProfil);

}


TEST_CASE("L'application de  l'eleve lui cree un profil Eleve")
{
    unique_ptr<Application> app = make_unique<AppEleve>();
    unique_ptr<Profil> profil = app->methodeFabrique();
    REQUIRE(profil->Message() == "{Un profil d Eleve vient d etre cree avec succes!}");
}

TEST_CASE("L'application du professeur lui cree un profil de Professeur")
{
    unique_ptr<Application> app = make_unique<AppProfesseur>();
    unique_ptr<Profil> profil = app->methodeFabrique();
    REQUIRE(profil->Message() == "{Une profil de Professeur vient d etre cree avec succes!}");
}


TEST_CASE("Le professeur peut rentrer ses infos personnelles pour creer un profil de professeur")
{
    unique_ptr<Application> app = make_unique<AppProfesseur>();
    unique_ptr<Profil> profil = app->methodeFabrique();
    Renseignements infosProfil = Client(*profil);
    REQUIRE(infosProfil.prenom == "Malcolm");
    REQUIRE(infosProfil.nom == "Kokrane");
    REQUIRE(infosProfil.telephone == "514 504-3504");
    REQUIRE(infosProfil.adresseDomicile == "3500 Chemin de La Croix");
    REQUIRE(infosProfil.adresseCourriel == "test.fabrique@patron.com");

}