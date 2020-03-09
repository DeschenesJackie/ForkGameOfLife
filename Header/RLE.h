#pragma once
#ifndef _RLE_h_
#define _RLE_h_

#include <experimental/filesystem>
#include <list>
#include <string>

namespace efs = std::experimental::filesystem;

class RLE {
public: 
	RLE(std::string chemin);						// Initialiser avec un chemin absolu! 
	~RLE() = default; 


private: 
	std::list<std::string> files; 
	void findRCLFiles(std::string chemin);  	  // Singleton pour initialiser variable files

};

#endif