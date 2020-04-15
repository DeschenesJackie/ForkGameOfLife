// Cégep du Vieux Montréal - B62
// 
// Univers 
//  
// dans le cadre d'un automate cellulaire dans le Jeu de la vie 
// 
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
// 
// Date de création : 2  mars 2020
// Auteurs : 
// - Jackie Deschenes

#pragma once
#ifndef _Univers_h_
#define _Univers_h_
#include "../Header/Cellule.h"
#include "../Header/Constantes.h"
#include "../Header/Regle.h"
#include <vector>
#include <string>

class Univers
{
public:
	Univers(Patron patron, std::string regle = "b3/s23");
	~Univers() = default;
	void evolve(bool wrap);
	std::vector<Cellule>& getVecteurActif();
	std::vector<Cellule>& getVecteurInactif();
	void setRegle(std::string regle);
	void reset(Patron patron, std::string regle);

private:
	void switchVecteur();
	std::vector<Cellule> mVecteur1;
	std::vector< Cellule> mVecteur2;
	std::vector<Cellule> * mVecteurActif;
	std::vector<Cellule> * mVecteurInactif;
	Regle mRegle;
};

static Cellule VecteurCellXY(int x, int y, std::vector<Cellule> vecteur, int largeur = LARGEUR, int hauteur = HAUTEUR, bool wrap = true);


#endif