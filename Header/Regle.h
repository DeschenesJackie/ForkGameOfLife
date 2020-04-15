// Cégep du Vieux Montréal - B62
// 
// Regle 
//  
// dans le cadre d'un automate cellulaire dans le Jeu de la vie 
// 
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
// 
// Date de création : 2  mars 2020
// Auteurs : 
// - Alexandre Howison
// - Jackie Deschenes 

#pragma once
#include <vector>
#include <stdlib.h>

class Regle {

private: 
	std::vector<int> mRegleBorn;
	std::vector<int> mRegleSurvive;

public:

	Regle(std::string regleEntree);
	Regle(std::vector<int> regleBorn, std::vector<int> regleSurvive);

	~Regle() = default;

	std::vector<int> const & regleBorn() const;
	std::vector<int> const & regleSurvive() const;
	static std::vector<int> genRegleBorn(std::string mRegleEntree);
	static std::vector<int> genRegleSurvive(std::string mRegleEntree);
	static bool confirmRegle(std::string mRegleEntree);
};