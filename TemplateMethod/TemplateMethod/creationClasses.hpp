//#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
//#include "catch.hpp"

#include <iostream>
#include <memory>
using namespace std;

//Creation de la classe abstraite, c'est ici que toutes les methodes sont crees, les classes derviees, donc CompteEleve et CompteProfesseur vont override les 
// methodes dont ils elles auront besoin.

class ClasseAbtraite {

public:
	virtual bool analyserPerformance() const = 0;

	virtual bool baseDonneeEtudiants() const = 0;

	virtual bool laisserCommentaire() const = 0;

	// la "templateMethod" qui va nous permettre de return les bonnes methodes selon notre classe.
	bool templateMethod()
	{
		return baseDonneeEtudiants() && laisserCommentaire() || analyserPerformance();
	}

	//Constructeur par defaut de la classe abstraite.
	ClasseAbtraite() = default;
};


class CompteEleve : public ClasseAbtraite {
public:

	/*
	 * _class_ va nous permettre d'afficher sur la console la classe qui est utilisee.
	 * __func__ va nous permettre d'afficher sur la console la methode utilisee.
	 */
	CompteEleve()
	{
		_class_ = __func__;
	}

	// On override la methode analyserPerformance car celle-ci est utilisee par le compte de l'eleve.
	bool analyserPerformance() const override
	{
		cout << _class_ << "::" << __func__ << endl;
		return true;
	}

	//On return false aux deux autres methodes car l'eleve ne doit pas avoir a celles-ci avec son compte.

	bool baseDonneeEtudiants() const override
	{
		return false;
	}

	bool laisserCommentaire() const override
	{
		return false;
	}

private:
	const char* _class_;
};

class CompteProfesseur : public ClasseAbtraite {
public:

	/*
     * _class_ va nous permettre d'afficher sur la console la classe qui est utilisee.
     * __func__ va nous permettre d'afficher sur la console la methode utilisee.
     */
	CompteProfesseur()
	{
		_class_ = __func__;
	}

	// On met false a analyserPerformance() car c'est une methode a laquelle le professeur n'a pas acces.
	bool analyserPerformance() const override
	{
		return false;
	}

	// On override les deux fonctions suivantes car le professeur y a acces avec son compte.

	bool baseDonneeEtudiants() const override
	{
		cout << _class_ << "::" << __func__ << endl;
		return true;
	}

	bool laisserCommentaire() const override
	{
		cout << _class_ << "::" << __func__ << endl;
		return true;
	}

private:
	const char* _class_;

};