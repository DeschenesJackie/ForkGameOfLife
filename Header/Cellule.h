// Cégep du Vieux Montréal - B62
// 
// Cellule 
//  
// dans le cadre d'un automate cellulaire dans le Jeu de la vie 
// 
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
// 
// Date de création : 2  mars 2020
// Auteurs : 
// - Alexandre Howison

#pragma once
#ifndef _Cellule_h_
#define _Cellule_h_

class Cellule {

private: 
	bool mEtat{};

public:
	Cellule(bool etat = 0);

	~Cellule() = default;

	bool etat() const;
	void setEtat(bool value);
};


#endif //Cellule.h