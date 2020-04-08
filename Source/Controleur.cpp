#include "../Header/Controleur.h"
#include <conio.h>

Controleur::Controleur(Univers & univers, Vue & vue)
	:mUnivers{ univers }, mVue{vue}
{
	
}

void Controleur::start() {
	while (!mVue.getMQuit()) { // A changer pour condition d'arret
		if (mVue.capterEvenement()) {
			mUnivers.reset(mVue.mRLE.getPatron(), mVue.getNomRegle());
		}
<<<<<<< HEAD
		if (mVue.getSimStatus()) {
			for (int i{}; i < mVue.getMultiplier(); ++i) {
=======
		if (mVue.getSimStatus()) {			
			for (int i{}; i < mVue.getMultiplier(); ++i){
>>>>>>> 8ad43d09feb63b84ba172e980f26f1c3f234a03e
				mUnivers.evolve(mVue.getEffetsBords());
			}
			mVue.affiche(mUnivers.getVecteurActif());
		}
		else
			_getch();
	}
}


