#include "..\Header\Univers.h"
#include "..\Header\Constantes.h"

Univers::Univers()
	:mVecteur1(LARGEUR*HAUTEUR), mVecteur2(LARGEUR*HAUTEUR), mVecteurActif{&mVecteur1}, mVecteurInactif{&mVecteur2}
{

}

void Univers::switchVecteur()
{
	std::vector< Cellule > * temp{ mVecteurActif };
	mVecteurActif = mVecteurInactif;
	mVecteurInactif = temp;
}
