#include "..\Header\RLE.h"

RLE::RLE(std::string chemin)
{
	mNbPatrons = 0;
	findRCLFiles(chemin);
	mIterateur = mFiles.begin();
	mNbPatrons = mFiles.size();
	mNbCell = 0; 
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

void RLE::charManager(char c, Patron & p) {
	if (c >= 48 && c <= 57) {
		mNbCell *= 10;
		mNbCell += (int)c - '0';
	}
	else if (c == 'b' || c == 'o') {
		bool etat{ c == 'b' ? false : true }; // si char est b, cellule inactive, sinon active

		if (mNbCell == 0) { // si pas de nombre, 1 cellule pushed 
			mNbCell = 1;
		}

		for (int i{}; i < mNbCell; ++i) {
			p.contenu.push_back(Cellule(etat));
		}

		mNbCell = 0; 
	}
}


Patron RLE::getPatron()
{
	std::ifstream iStream(*mIterateur, std::ios::in);
	std::regex commentaire("^#.+"); //  # ...
	std::regex limitations("x\\s=\\s(\\d+),\\sy\\s=\\s(\\d+).*"); // x = [0-9]+, y = [0-9]+
	bool limitationDone{ false }; 
	std::smatch capture; 
	Patron patron; 

	if (iStream.is_open()) {
		while (!iStream.eof()) {
			std::string ligne; 			
			std::getline(iStream, ligne);
	
			if (!std::regex_match(ligne, commentaire)) { 
				if(limitationDone)
					std::for_each(ligne.begin(), ligne.end(), [&patron, this](char c) { charManager(c, patron); });
				else {
					if (std::regex_match(ligne, capture, limitations)) {
						if (capture.size() == 3) {
							patron.nbRangees = std::stoi(capture[1].str());
							patron.nbColonnes = std::stoi(capture[2].str());

							limitationDone = true; 
						}  
					}
				}
			}
		}
	}

	return patron;
}

void RLE::previousPatron()
{
	if (mIterateur == mFiles.begin())
		mIterateur = mFiles.end();
	std::advance(mIterateur, -1);
}

void RLE::nextPatron()
{
	std::advance(mIterateur, 1);
	if (mIterateur == mFiles.end())
		mIterateur = mFiles.begin();
}

