#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "creationClasses.hpp"

TEST_CASE("L'eleve a acces a la bonne methode de la classe abstraite")
{
	unique_ptr<ClasseAbtraite> eleve = make_unique<CompteEleve>();
	REQUIRE(eleve->analyserPerformance() == true);
}

TEST_CASE("L'eleve n'a pas acces aux methodes reservees au professeur")
{
	unique_ptr<ClasseAbtraite> eleve = make_unique<CompteEleve>();
	REQUIRE(eleve->baseDonneeEtudiants() == false);
	REQUIRE(eleve->laisserCommentaire() == false);
}

TEST_CASE("Le professeur a acces aux bonnes methodes de la classe abstraite")
{
	unique_ptr<ClasseAbtraite> professeur = make_unique<CompteProfesseur>();
	REQUIRE(professeur->baseDonneeEtudiants() == true);
	REQUIRE(professeur->laisserCommentaire() == true);
}

TEST_CASE("Le professeur n'a pas acces a la methode reservee a l'eleve")
{
	unique_ptr<ClasseAbtraite> professeur = make_unique<CompteProfesseur>();
	REQUIRE(professeur->analyserPerformance() == false);
}




