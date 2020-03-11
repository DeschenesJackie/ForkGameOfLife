#include <windows_console.h>
#include <iostream>
#include <conio.h>
#include "../Header/Controleur.h"
#include "../Header/OptionManager.h"
#include "../Header/RLE.h"

using namespace windows_console;
using namespace std;

int main(int argc, char* argv[])
{
	OptionManager manager(argc, argv);
	RLE rle("Y:\\62Oracle\\TPEQUIPE\\B62_TP1\\Doc\\FichiersRLE\\fichiers_rle");
	Univers univers(rle.getPatron());
	Vue vue;

	manager.evaluationOption();
	if (manager.mRegleValide) {
		univers.setRegle(manager.mRegle);
	}

	Controleur controleur(univers, vue);
	controleur.start();
	return 0;
}






