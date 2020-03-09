#include "../Header/Controleur.h"


Controleur::Controleur(Univers & univers, Vue & vue)
	:mUnivers{ univers }, mVue{vue}
{
	
}

void Controleur::start() {
	while (true) { // A changer pour condition d'arret
		mUnivers.evolve();
		// Fonction d'affichage du VecteurActif de la vue 
		// appelle pour avoir access au vecteur Actif est mUnivers.getVecteurActif()
	}
}