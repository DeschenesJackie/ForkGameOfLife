#include "../Header/Cellule.h"

Cellule::Cellule(bool etat) :mEtat{ etat }
{
	
}

bool Cellule::etat() const {
	return mEtat;
}

void Cellule::setEtat(bool value) {
	mEtat = value;
}
