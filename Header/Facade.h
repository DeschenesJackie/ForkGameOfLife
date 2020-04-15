// Cégep du Vieux Montréal - B62
// 
// Facade 
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
#ifndef _Facade_h_
#define _Facade_h_
#include "../Header/Cellule.h"
#include "../Header/Constantes.h"
#include <vector>
#include "../Header/Regle.h"

class Facade {

private: 
	std::vector<Cellule>& mVecteur;
	std::vector<Cellule>::iterator mIterateur;
	Regle& mRegle;
	bool& mWrap;
	borders evalBorder(int distance);

public:

	Facade(std::vector<Cellule>& vecteur, std::vector<Cellule>::iterator iterateurPosition, Regle& regle, bool& wrap);
	~Facade() = default;

	bool applyRegle();
};


#endif