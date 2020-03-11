#include "../Header/Controleur.h"


Controleur::Controleur(Univers & univers, Vue & vue)
	:mUnivers{ univers }, mVue{vue}
{
	
}

void Controleur::start() {
	while (!mVue.getMQuit()) { // A changer pour condition d'arret
		mUnivers.evolve();
		mVue.capterEvenement();
		mVue.affiche(mUnivers.getVecteurActif());
	}
}