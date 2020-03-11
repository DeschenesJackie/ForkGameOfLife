#include "..\Header\RLE.h"

RLE::RLE(std::string chemin)
{
	mNbPatrons = 0;
	findRCLFiles(chemin);
	mIterateur = mFiles.begin();
	mNbPatrons = mFiles.size();
}

void RLE::findRCLFiles(std::string chemin)
{
	if (empty(mFiles)) {
		std::string cheminActuel{};

		for (auto const & p : efs::directory_iterator(chemin)) {

			if (efs::is_regular_file(p)) {
				efs::path const & cheminFichier{ p.path() };

				cheminActuel = cheminFichier.parent_path().string() + "\\" +
					cheminFichier.stem().string() + 
					cheminFichier.extension().string();

				mFiles.push_back(cheminActuel);
			}
		}
	}
}

/*Cellule RLE::charToCell(char c){
	return
}*/

Patron RLE::getPatron()
{
	std::ifstream iStream(*mIterateur, std::ios::in);
	std::regex commentaire("^#.+"); 
	Patron patron; 

	if (iStream.is_open()) {
		while (!iStream.eof()) {
			std::string ligne; 			
			std::getline(iStream, ligne);
	
			if (!std::regex_match(ligne, commentaire)) { 
				//std::for_each(ligne.begin(), ligne.end(), [&patron](char c) { patron.contenu.push_back(charToCell(c))});
			}

		}
	}

	return patron;
}

void RLE::previousPatron()
{
	if (mIterateur == mFiles.begin())
		mIterateur = mFiles.end();
	else
		std::advance(mIterateur, -1); 
}

void RLE::nextPatron()
{	
	if (mIterateur == mFiles.end())
		mIterateur = mFiles.begin();
	else
		std::advance(mIterateur, 1);
}

