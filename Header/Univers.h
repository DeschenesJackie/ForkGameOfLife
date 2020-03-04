#pragma once
#ifndef _Univers_h_
#define _Univers_h_
#include "../Header/Cellule.h"
#include <vector>

class Univers
{
public:
	Univers();
	~Univers() = default;

	void switchVecteur();
private:
	std::vector<Cellule> mVecteur1;
	std::vector< Cellule> mVecteur2;
	std::vector<Cellule> * mVecteurActif;
	std::vector<Cellule> * mVecteurInactif;
};




#endif