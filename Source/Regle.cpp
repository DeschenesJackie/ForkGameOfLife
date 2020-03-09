#include "..\Header\Regle.h"

Regle::Regle(std::string regleEntree)
: Regle(Regle::genRegleBorn(regleEntree), Regle::genRegleSurvive(regleEntree))
{
}

Regle::Regle(std::vector<int> regleBorn, std::vector<int> regleSurvive)
	:	mRegleBorn {regleBorn}, mRegleSurvive {regleSurvive}
{
}

//Rendu ici, d�finir les regles genRegleBorn et genRegleSurvive
std::vector<int> Regle::genRegleBorn(std::string mRegleEntree)
{
	std::vector<int> vecteur;
	std::string::iterator iterateurString = mRegleEntree.begin();
	
	while (*iterateurString != '/') {
		if (*iterateurString != 'B' || *iterateurString != 'b') vecteur.push_back((*iterateurString - '0'));
		++iterateurString;
	}

	return std::vector<int>();
}

std::vector<int> Regle::genRegleSurvive(std::string mRegleEntree)
{
	std::vector<int> vecteur;
	std::string::iterator iterateurString = mRegleEntree.begin();

	while (*iterateurString != '/') {
		++iterateurString;
	}
	++iterateurString;
	while (iterateurString != mRegleEntree.end()) {
		if (*iterateurString != 'S' || *iterateurString != 's') vecteur.push_back((*iterateurString - '0'));
	}

	return std::vector<int>();
}





