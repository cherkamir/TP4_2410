#define CATCH_CONFIG_MAIN  //  This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"
#include "Application.h"
#include "Profil.h"
#include "ProfilEleve.h"
#include "ProfilProfesseur.h"


using namespace std;

/// Affiche le menu principal
void afficherMenu()
{
    cout << "(a) Nom\n"
        << "(b) Prenom\n"
        << "(c) Telelphone\n"
        << "(d) Domicile\n"
        << "(e) Courriel\n"
        << "(q) Quitter\n"
        << endl;
}

/// Nettoye le tampon 
void nettoyerTampon()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << endl;
}


Renseignements Client(const Profil& profil)
{
    cout << "Rentrez dans l ordre votre nom, prenom, telephone, adresseDomicile et votre adresseCourriel:" << endl;
    Renseignements infosProfil;

    getline(cin, infosProfil.nom, '\n');
    getline(cin, infosProfil.prenom, '\n');
    getline(cin, infosProfil.telephone, '\n');
    getline(cin, infosProfil.adresseDomicile, '\n');
    getline(cin, infosProfil.adresseCourriel, '\n');
    return infosProfil;

}

Renseignements Client2(Renseignements& infosProfil)
{
    char input;
        do
        {
        afficherMenu();
        cout << "Choisir le renseignement a changer :  ";
        cin >> input;
        nettoyerTampon();
        switch (input)
        {
        case 'a':
            cout << "Rentrer le nouveau nom ..." << endl;
            getline(cin, infosProfil.nom, '\n');
            break;
        case 'b':
            cout << "Rentrer le nouveau prenom ..." << endl;
            getline(cin, infosProfil.prenom, '\n');
            break;
        case 'c':
            cout << "Rentrer le nouveau numero de telephone ... " << endl;
            getline(cin, infosProfil.telephone, '\n');
            break;
        case 'd':
            cout << "Rentrer la nouvelle adresse de domicile ... " << endl;
            getline(cin, infosProfil.adresseDomicile, '\n');
            break;
        case 'e':
            cout << "Rentrer la nouvelle adresse courriel ... " << endl;
            getline(cin, infosProfil.adresseCourriel, '\n');
            break;
        case 'q':
            cout << "Sortie ..." << endl;
            break;
        default:
            cout << "Cette option n existe pas, reessayez ... " << endl;
        }

        }
    while (input != 'q');
        return infosProfil;
}

TEST_CASE("L'application de  l'eleve lui cree un profil Eleve")
{
    unique_ptr<Application> app = make_unique<AppEleve>();
    unique_ptr<Profil> profilE = app->methodeFabrique();
    REQUIRE(profilE->Message() == "{Un profil d Eleve vient d etre cree avec succes!}");
}

TEST_CASE("L'application du professeur lui cree un profil de Professeur")
{
    unique_ptr<Application> app = make_unique<AppProfesseur>();
    unique_ptr<Profil> profilP = app->methodeFabrique();
    REQUIRE(profilP->Message() == "{Une profil de Professeur vient d etre cree avec succes!}");
}

TEST_CASE("Le profil d'eleve possede le bon type apres sa creation")
{
    unique_ptr<Application> app = make_unique<AppEleve>();
    string type = app->methodeFabrique()->getTypeProfil();
    REQUIRE(type == "Eleve");
}

TEST_CASE("Le professeur peut rentrer ses infos personnelles pour creer un profil de professeur")
{
    unique_ptr<Application> app = make_unique<AppProfesseur>();
    unique_ptr<Profil> profilP = app->methodeFabrique();
    cout << "Test qui verifie la bonne lecture des renseignements " << endl
        << "Creation d'un nouveau profil de Professeur ..." << endl << endl;
    Renseignements infosProfil = Client(*profilP);
    REQUIRE(infosProfil.prenom == "Malcolm");
    REQUIRE(infosProfil.nom == "Kokrane");
    REQUIRE(infosProfil.telephone == "514 504-3504");
    REQUIRE(infosProfil.adresseDomicile == "3500 Chemin de La Croix");
    REQUIRE(infosProfil.adresseCourriel == "test.fabrique@patron.ca");
    cout << endl;

}

TEST_CASE("L'eleve peut changer certaines informations a propos de son profil")
{
    unique_ptr<Application> app = make_unique<AppEleve>();
    unique_ptr<Profil> profilE = app->methodeFabrique();
    cout << "Test qui v�rifie que l'utlisateur peut modifier les renseignements de son profil." << endl 
         << "Creation d'un nouveau profil Etudiant ..." << endl << endl;
    Renseignements infosEleve = Client(*profilE);
    cout << "Modification de l'adresse et du courriel ..." << endl;
    infosEleve = Client2(infosEleve);
    profilE->setInfosProfil(infosEleve);
    REQUIRE(infosEleve.adresseDomicile == "3500 Cross Road Street");
    REQUIRE(infosEleve.adresseCourriel == "test.factory@pattern.com");
    cout << endl;
}