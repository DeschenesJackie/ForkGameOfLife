// Cégep du Vieux Montréal - B62
// 
// Vue 
//  
// dans le cadre d'un automate cellulaire dans le Jeu de la vie 
// 
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
// 
// Date de création : 2  mars 2020
// Auteurs : 
// - Mélanie Boucher 
// - Jackie et Alexandre (implémentation de plusieurs fonctions) 

#pragma once

#ifndef _Vue_h_
#define _Vue_h_

#include "../Header/Constantes.h"
#include <string>
#include <vector>
#include <windows_console.h>
#include "../Header/RLE.h"

class Vue
{
	private:
		int multiplier{1};
		int pourcentage{};
		bool simStatus{true};	//	init a 1 qd demarre
		bool mQuit{};
		int compteurRegle{};
		int compteurCouleur{};
		bool effetsBords = true;	// 0 ou 1 : 0 = bordure morte, 1 = bordure vivante
		windows_console::image image;
		bool modeCouleur{};
		std::string nomRegle = "";
		std::string mCustomRegle = "";

		void formatterFenetre();
		void pause();
		void basculeModeCouleur();
		void getCouleur();
		void nextCouleur();
		void nextRegle();	
		void gererEffetBords();

	public:
		Vue(RLE &rle);
		~Vue() = default;

		int getMultiplier();
		int getPercentage();
		bool getSimStatus();
		bool getMQuit();
		bool getEffetsBords();
		RLE &mRLE;

		std::string getNomRegle();
		bool capterEvenement();
		void affiche(std::vector <Cellule> const & vecteur);
		void setCustomRegle(std::string s);

};

#endif