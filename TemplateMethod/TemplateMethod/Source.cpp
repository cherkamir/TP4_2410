#include <iostream>
#include <memory>
using namespace std;

class ClasseAbtraite {

public:
	virtual bool analyserPerformance() const = 0;

	virtual bool baseDonneeEtudiants() const = 0;

	virtual bool laisserCommentaire() const = 0;

	bool templateMethod() 
	{
		return baseDonneeEtudiants() && laisserCommentaire() || analyserPerformance();
	}

	ClasseAbtraite() = default;
};


class CompteEleve : public ClasseAbtraite {
public:

	CompteEleve()
	{
		_class_ = __func__;
		cout << "On a cree un compte eleve, les methodes auxquelles l'eleve a acces sont : \n" << endl;
	}
	
	bool analyserPerformance() const override
	{
		cout << _class_ << "::" << __func__ << endl;
		return true;
	}

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

	CompteProfesseur()
	{
		_class_ = __func__;
		cout << "On a cree un compte professeur, les methodes auxquelles le professeur a acces sont : \n" << endl;
	}

	bool analyserPerformance() const override
	{
		return false;
	}

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


int main() {

	unique_ptr<ClasseAbtraite> test = make_unique<CompteProfesseur>();
	test->templateMethod();
}