#include "..\Header\Univers.h"
#include "..\Header\Facade.h"
#include "..\Header\Constantes.h"

Univers::Univers(Patron patron, std::string regle)
	:mVecteur1(LARGEUR*HAUTEUR), mVecteur2(LARGEUR*HAUTEUR), mVecteurActif{&mVecteur1}, mVecteurInactif{&mVecteur2}, mRegle(regle)
{
	std::vector<Cellule>::iterator indexPatron = patron.contenu.begin();
	std::vector<Cellule>::iterator iterateurActif = getVecteurActif().begin();

	bool etat;
	int departL = LARGEUR / 2 - patron.nbColonnes / 2;
	int departH = HAUTEUR / 2 - patron.nbRangees / 2;
	for (int i{}; i < patron.nbColonnes; ++i) {
		for (int j{}; j < patron.nbRangees; ++j) {
			etat = (*(indexPatron + j + (i*patron.nbColonnes))).etat();
			(*(iterateurActif + j + ((i)*LARGEUR))).setEtat(etat);
		}
	}
}

void Univers::evolve(bool wrap)
{
	std::vector<Cellule>::iterator iteratorActif = getVecteurActif().begin();
	std::vector<Cellule>::iterator iteratorInactif = getVecteurInactif().begin();
	while (iteratorActif != getVecteurActif().end()) {
		(*iteratorInactif).setEtat(Facade(getVecteurActif(), iteratorActif, mRegle, wrap).applyRegle()); //a changer pour la variable de la vue pour l'option de "wrap around"
		++iteratorActif;
		++iteratorInactif;
	}
	switchVecteur();
}

std::vector<Cellule>& Univers::getVecteurActif()
{
	return *mVecteurActif;
}

std::vector<Cellule>& Univers::getVecteurInactif()
{
	return *mVecteurInactif;
}

void Univers::setRegle(std::string regle)
{
	mRegle = Regle(regle);
}

void Univers::switchVecteur()
{
	std::vector< Cellule > * temp{ mVecteurActif };
	mVecteurActif = mVecteurInactif;
	mVecteurInactif = temp;
}

// Usefullness TBD
Cellule VecteurCellXY(int x, int y, std::vector<Cellule> const vecteur, int largeur, int hauteur, bool wrap)
{
	if (wrap) {
		if (x < 0 || x > largeur) {
			x = x % largeur;
			if (x < 0) x = largeur - x;
		}
		if (y < 0 || y > hauteur) {
			y = y % hauteur;
			if (y < 0) y = hauteur - y;
		}
	}
	return vecteur[x + (y + largeur)];
}
