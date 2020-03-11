#pragma once

#ifndef _Vue_h_
#define _Vue_h_

#include "../Header/Constantes.h"
#include <string>
#include <vector>
#include <windows_console.h>

class Vue
{
	private:
		int multiplier{};
		int pourcentage{};
		bool simStatus{};	//	init a 1 qd demarre
		bool mQuit{};
		int fichier{};
		int compteurRegle{};
		int compteurCouleur{};
		bool effetsBords = true;	// 0 ou 1 : 0 = bordure morte, 1 = bordure vivante
		windows_console::image image;
		bool modeCouleur{};
		std::string nomRegle = "";

		void formatterFenetre();
		void pause();
		void basculeModeCouleur();
		void getCouleur();
		void nextCouleur();
		void nextRegle();	
		void gererEffetBords();

	public:
		Vue();
		~Vue() = default;

		int getMultiplier();
		int getPercentage();
		int getFile();
		bool getSimStatus();
		bool getMQuit();
		bool getEffetsBords();

		std::string getNomRegle();
		void capterEvenement();
		void affiche(std::vector <Cellule> const & vecteur);

};

#endif