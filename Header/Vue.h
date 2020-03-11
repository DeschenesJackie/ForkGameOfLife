#pragma once

#ifndef _Vue_h_
#define _Vue_h_

#include "../Header/Constantes.h"

class Vue
{
	private:
		int multiplier{};
		int pourcentage{};
		bool simStatus = true;
		int fichier{};
		int compteurRegle{};
		int effetsBords{};	// 0 ou 1 : 0 = bordure morte, 1 = bordure vivante

		void formatterFenetre();
		void capterEvenement();
		void pause();

	public:
		Vue();
		~Vue() = default;

		int getMultiplier();
		int getPercentage();
		int getFile();
		bool getSimStatus();
		std::string getNomRegle();

};

#endif