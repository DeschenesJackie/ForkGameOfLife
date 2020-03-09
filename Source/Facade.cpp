#include "..\Header\Facade.h"
#include "..\Header\Constantes.h"

Facade::Facade(std::vector<Cellule>& vecteur, std::vector<Cellule>::iterator iterateurPosition, Regle regle, bool wrap)
	:mVecteur{vecteur}, mRegle{regle}, mIterateur{iterateurPosition}, mWrap{wrap}
{

}

bool Facade::applyRegle()
{
	bool alive = false;
	Cellule cell = *(mIterateur);
	int compteurVivant = 0;
	for (int i{ -1 }; i < 2; i++)  
	{
		for (int j{ -1 }; j < 2; j++)
		{
			//TODO: gerer out of bounds pour horizontal et vertical ici
			if ((mIterateur + i + (j + LARGEUR) != mIterateur)) {
				if ((*(mIterateur + i + (j + LARGEUR))).etat()) {
					++compteurVivant;
				}
			}
		}
	}

	std::vector<int> vecteurCourant;
	if (mIterateur->etat) {
		vecteurCourant = mRegle.regleSurvive();
	}
	else
	{
		vecteurCourant = mRegle.regleBorn();
	}

	std::vector<int>::iterator regleCurrent = vecteurCourant.begin();

	while (regleCurrent != vecteurCourant.end())
	{
		if (*regleCurrent == compteurVivant) alive = true;
		++regleCurrent;
	}

		
	
	return alive;
}

