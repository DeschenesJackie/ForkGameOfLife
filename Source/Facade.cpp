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
			bool border{};
			int x = i;
			int y = j;
			int distance = std::distance(mVecteur.begin(), mIterateur);
			borders test = evalBorder(distance);
			switch (test)
			{
			case TOP_LEFT:
				border = true;
				if (x < 0) x = LARGEUR - 1;
				if (y < 0) y = HAUTEUR-1;
				break;
			case TOP_RIGHT:
				border = true;
				if (y < 0) y = HAUTEUR-1;
				if (x > 0) x = 0;
				break;
			case BOTTOM_LEFT:
				border = true;
				if (x < 0) x = LARGEUR - 1;
				if (y > 0) y = 0;
				break;
			case BOTTOM_RIGHT:
				border = true;
				if (y > 0) y = 0;
				if (x > 0) x = 0;
				break;
			case TOP:
				border = true;
				if (y < 0) y = HAUTEUR-1;
				break;
			case BOTTOM:
				border = true;
				if (y > 0) y = 0;
				break;
			case LEFT:
				border = true;
				if (x < 0) x = LARGEUR - 1;
				break;
			case RIGHT:
				border = true;
				if (x > 0) x = 0;
				break;
			}
			if ((mIterateur + x + (y * LARGEUR) != mIterateur)) {
				if ((!mWrap && !border) || mWrap) {
					if ((*(mIterateur + x + (y * LARGEUR))).etat()) { //a checker pour wrap around
						++compteurVivant;
					}
				}
			}
		}
	}

	std::vector<int> vecteurCourant;
	if (mIterateur->etat()) {
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

borders Facade::evalBorder(int distance)
{
	borders valeurRetour = DEFAULT;
	bool top = false;
	bool bottom = false;
	bool left = false;
	bool right = false;
	if (distance%LARGEUR == 0) {
		left = true;
	}
	if (distance%LARGEUR == LARGEUR - 1) {
		right = true;
	}
	if (distance < LARGEUR) {
		top = true;
	}
	if (distance >= (HAUTEUR-1) * LARGEUR) {
		bottom = true;
	}


	if (top && left) valeurRetour = TOP_LEFT;
	else if (top && right) valeurRetour = TOP_RIGHT;
	else if (bottom && left) valeurRetour = BOTTOM_LEFT;
	else if (bottom && right) valeurRetour = BOTTOM_RIGHT;
	else if (top) valeurRetour = TOP;
	else if (bottom) valeurRetour = BOTTOM;
	else if (left) valeurRetour = LEFT;
	else if (right) valeurRetour = RIGHT;

	return valeurRetour;
}
