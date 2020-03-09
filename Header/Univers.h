#pragma once
#ifndef _Univers_h_
#define _Univers_h_
#include "../Header/Cellule.h"
#include "../Header/Constantes.h"
#include <vector>

class Univers
{
public:
	Univers();
	~Univers() = default;
	void evolve();
	std::vector<Cellule> getVecteurActif();
	std::vector<Cellule> getVecteurInactif();

private:
	void switchVecteur();
	std::vector<Cellule> mVecteur1;
	std::vector< Cellule> mVecteur2;
	std::vector<Cellule> * mVecteurActif;
	std::vector<Cellule> * mVecteurInactif;
};

static Cellule VecteurCellXY(int x, int y, std::vector<Cellule> vecteur, int largeur = LARGEUR, int hauteur = HAUTEUR, bool wrap = true);


#endif