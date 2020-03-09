#include "Regle.h"

Regle::Regle(std::string regleEntree)
: Regle(Regle::genRegleBorn(regleEntree), Regle::genRegleSurvive(regleEntree))
{
}

Regle::Regle(std::vector<int> regleBorn, std::vector<int> regleSurvive)
	:	mRegleBorn {regleBorn}, mRegleSurvive {regleSurvive}
{
}

//Rendu ici, définir les regles genRegleBorn et genRegleSurvive
std::vector<int> Regle::genRegleBorn(std::string mRegleEntree)
{
	return std::vector<int>();
}

std::vector<int> Regle::genRegleSurvive(std::string mRegleEntree)
{
	return std::vector<int>();
}





