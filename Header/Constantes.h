#pragma once
#ifndef _Constantes_h_
#define _Constantes_h_

const int LARGEUR = 300, HAUTEUR = 200; 

const int PRECEDENT{ -1 }, COURANT{ 0 }, SUIVANT{ 1 };

const bool ALIVE = 1, DEAD = 0; 

enum borders {TOP_LEFT, TOP_RIGHT, BOTTOM_LEFT, BOTTOM_RIGHT, TOP, BOTTOM, LEFT, RIGHT, DEFAULT };

#endif