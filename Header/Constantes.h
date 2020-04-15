// Cégep du Vieux Montréal - B62
// 
// Constantes 
//  
// dans le cadre d'un automate cellulaire dans le Jeu de la vie 
// 
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
// 
// Date de création : 2  mars 2020
// Auteurs : 
// - Collectif

#pragma once
#ifndef _Constantes_h_
#define _Constantes_h_

#include <vector>
#include "..\Header\Cellule.h"
#include <string>

const std::string NOMPROG = "Game of life", FONTFAMILY = "consolas";

const int LARGEUR{ 300 }, HAUTEUR{ 200 };

const bool ALIVE{ 1 }, DEAD{ 0 };

const int BORDURES_MORTES{}, BORDURES_CYCLIQUES{ 1 };

const std::string REGLE1{ "B3/S23" }, REGLE2{ "B36/S23" }, REGLE3{ "B3678/S34678" };

using Patron = struct {
	std::vector<Cellule> contenu;
	int nbColonnes; 
	int nbRangees; 
};

enum borders {TOP_LEFT, TOP_RIGHT, BOTTOM_LEFT, BOTTOM_RIGHT, TOP, BOTTOM, LEFT, RIGHT, DEFAULT };

#endif