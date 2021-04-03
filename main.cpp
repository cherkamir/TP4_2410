#include "Profil.cpp"
#include "Application.cpp"
#include "ProfilEleve.cpp"
#include "ProfilProfesseur.cpp"
#include "AppEleve.cpp"
#include "AppProfesseur.cpp"

using namespace std;

void Client(const Application& app)
{
    cout << "Je ne sais pas comment est ecrite la classe Application mais elle marche! " << app.creationObjet() << endl;
}

int main()
{
    cout << "Application lancee. Creation d un profil d eleve ..." << endl;
    Application* app = new AppEleve();
    Client(*app);
    cout << endl;

    cout << "Application lancee. Creation d un profil de professeur ..." << endl;
    Application* app2 = new AppProfesseur();
    Client(*app2);
    cout << endl;

    delete app;
    delete app2;
    return 0;

}