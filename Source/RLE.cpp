#include "..\Header\RLE.h"

RLE::RLE(std::string chemin)
{
	std::list<std::string> files;
	findRCLFiles(chemin);

}



void RLE::findRCLFiles(std::string chemin)
{
	if (empty(files)) {
		std::string cheminActuel{};

		for (auto const & p : efs::directory_iterator(chemin)) {

			if (efs::is_regular_file(p)) {
				efs::path const & cheminFichier{ p.path() };

				cheminActuel = cheminFichier.parent_path().string() +
					cheminFichier.stem().string() +
					cheminFichier.extension().string();

				files.push_back(cheminActuel);
			}
		}
	}

}