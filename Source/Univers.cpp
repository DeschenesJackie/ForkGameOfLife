#include "..\Header\Univers.h"

Univers::Univers()
	:mVecteur1{  };
{

}

void Univers::switchVecteur()
{
	std::vector< Cellule > * temp = mVecteurActif;
	mVecteurActif = mVecteurInactif;
	mVecteurInactif = temp;
}
