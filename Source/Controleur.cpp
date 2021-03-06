#include "../Header/Controleur.h"

Controleur::Controleur(Univers & univers, Vue & vue)
	:mUnivers{ univers }, mVue{vue}
{
	
}

void Controleur::start() {
	while (!mVue.getMQuit()) { // A changer pour condition d'arret
		if (mVue.capterEvenement()) {
			mUnivers.reset(mVue.mRLE.getPatron(), mVue.getNomRegle(), mVue.getPercentage());
		}

		if (mVue.getSimStatus()) {
			for (int i{}; i < mVue.getMultiplier(); ++i) {
				mUnivers.evolve(mVue.getEffetsBords());
			}
			mVue.affiche(mUnivers.getVecteurActif());
		}
		
	}
}


