#include "Profil.cpp"
#include "Application.cpp"
#include "ProfilEleve.cpp"
#include "ProfilProfesseur.cpp"
#include "Renseignements.h"

using namespace std;

void Client(const Profil& profil, char& input)
{    
    string type;
    cout << "Rentrez le type de profil." << endl;
    cin >> type;

    cout << "Rentrez dans l ordre votre nom, prenom, telephone, adresseDomicile et votre adresseCourriel:" << endl;
    Renseignements infosProfil;

    cin >> infosProfil.nom;
    cin >> infosProfil.prenom;
    cin >> infosProfil.telephone;
    cin >> infosProfil.adresseDomicile;
    cin >> infosProfil.adresseCourriel;
    
    profil.afficher(infosProfil, type);
}

/// Affiche le menu principal
void afficherMenu()
{
    cout << "(a) Creer un profil d Eleve\n"
        << "(b) Creer un profil de Professeur\n"
        << "(c) Quitter\n"
        << endl;
}

/// Nettoye le tampon 
void nettoyerTampon()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << endl;
}

int main()
{
    char input = 'd';
    unique_ptr<Application> app1 = make_unique<AppEleve>();
    unique_ptr<Application> app2 = make_unique<AppProfesseur>();

    unique_ptr<Profil> profil1 = app1->methodeFabrique();
    unique_ptr<Profil> profil2 = app2->methodeFabrique();

    do
    {
        afficherMenu();
        cout << "Choisir une option :  ";
        cin >> input;
        nettoyerTampon();
        switch (input)
        {
        case 'a':
            cout << "Application lancee. Creation d un profil d eleve ..." << endl;
            
            Client(*profil1, input);
            cout << endl;
            break;
        case 'b':
            cout << "Application lancee. Creation d un profil de professeur ..." << endl;
            
            Client(*profil2, input);
            cout << endl;
            break;
        case 'c':
            cout << "Fermeture de l'application" << endl;
            break;
        default:
            cout << "Cette option n existe pas, reessayez." << endl;
        }

    } 
    while (input != 'c');


    return 0;

}