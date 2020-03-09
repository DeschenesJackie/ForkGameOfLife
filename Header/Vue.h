#pragma once
#include "../Header/Constantes.h"

#ifndef _Vue_h_
#define _Vue_h_

class Vue
{
private:
	int multiplier{};
	int pourcentage{};
	int fichier = COURANT;

	void formatterFenetre();
	void capterEvenement(); 
	
public:
	Vue();
	~Vue() = default;

	int getMultiplier(); 
	int getPercentage();
	int getFile(); 
};

#endif

for (i{ -1 }; i < 2; ++i) {
	for (j{ -1 }; j < 2; ++j) {
		if (*(iteratorActif + i + (j + LARGEUR)) != iteratorActif)
			*(iteratorActif + i + (j + LARGEUR))
	}
}