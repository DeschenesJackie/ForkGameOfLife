// Cégep du Vieux Montréal - B62
// 
// Option Manager (bonus (not really))  
//  
// dans le cadre d'un automate cellulaire dans le Jeu de la vie 
// 
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
// 
// Date de création : 2  mars 2020
// Auteurs : 
// - Jackie Deschenes 

#pragma once 
#ifndef _OptionManager_h_
#define _OptionManager_h_
#include <string>

class OptionManager {
public:
	OptionManager(int argc, char* argv[]);
	std::string mRegle;
	bool mRegleValide;
	bool evaluationOption();
private:
	int mArgc;
	char **mArgv;
};

#endif