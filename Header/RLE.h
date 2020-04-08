// Cégep du Vieux Montréal - B62
// 
// RLE 
//  
// dans le cadre d'un automate cellulaire dans le Jeu de la vie 
// 
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
// 
// Date de création : 2  mars 2020
// Auteurs : 
// - Jessica Khau
//
// Références : 
// -https://thispointer.com/c-how-to-get-element-by-index-in-list/
//  

// RLE rle("Y:\\HIVER_2020\\projet_oracle\\B62_TP1\\Doc\\FichiersRLE\\fichiers_rle");
// "..\\Doc\\FichiersRLE\\fichiers_rle"
// rle.getPatron(); 
// to put in main 


#pragma once
#ifndef _RLE_h_
#define _RLE_h_

#include <experimental/filesystem>
#include <vector>
#include <string>
#include <regex>

#include <fstream>  
#include <array>   
#include <algorithm> 

#include "..\Header\Cellule.h"
#include "..\Header\Constantes.h"

namespace efs = std::experimental::filesystem;

class RLE {
public: 
	RLE(std::string chemin);						// Initialiser avec un chemin absolu! 
	~RLE() = default; 
	Patron getPatron();
	bool generatePatron();
	void previousPatron();
	void nextPatron();


private: 
	std::vector<std::string> mFiles; 
	int mNbPatrons; 
	std::vector<std::string>::iterator mIterateur;
	Patron mPatron;
	int mNbCell;
	int mSizeLine;

	void charManager(char c, Patron & p);
	void findRCLFiles(std::string chemin);  	  // Singleton pour initialiser variable files
};

#endif