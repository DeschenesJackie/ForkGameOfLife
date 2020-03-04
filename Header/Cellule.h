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