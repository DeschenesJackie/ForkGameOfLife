#include "..\Header\Univers.h"
#include "..\Header\Constantes.h"

Univers::Univers()
	:mVecteur1(LARGEUR*HAUTEUR), mVecteur2(LARGEUR*HAUTEUR), mVecteurActif{&mVecteur1}, mVecteurInactif{&mVecteur2}
{

}

void Univers::evolve()
{
	std::vector<Cellule>::iterator iteratorActif = getVecteurActif().begin();
	std::vector<Cellule>::iterator iteratorInactif = getVecteurInactif().begin();
	while (iteratorActif != getVecteurActif().end()) {
		(*iteratorInactif).setEtat(true); // a implementer remplacer le true par le fonction qui retourne la prochaine state de la cellule
		++iteratorActif;
		++iteratorInactif;
	}
	switchVecteur();
}

std::vector<Cellule> Univers::getVecteurActif()
{
	return *mVecteurActif;
}

std::vector<Cellule> Univers::getVecteurInactif()
{
	return *mVecteurInactif;
}

void Univers::switchVecteur()
{
	std::vector< Cellule > * temp{ mVecteurActif };
	mVecteurActif = mVecteurInactif;
	mVecteurInactif = temp;
}

// Usefullness TBD
Cellule VecteurCellXY(int x, int y, std::vector<Cellule> static vecteur, int largeur, int hauteur, bool wrap)
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
