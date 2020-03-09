#pragma once
#ifndef _Controleur_h_
#define _Controleur_h_
#include "../Header/Univers.h"
#include "../Header/Vue.h"

class Controleur
{
public:
	Controleur(Univers & univers, Vue & vue);

	~Controleur() = default;

	void start();
private:
	Univers & mUnivers;
	Vue & mVue;
};
#endif