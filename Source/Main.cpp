#include <windows_console.h>
#include <iostream>
#include <conio.h>
#include "../Header/Controleur.h"
#include "../Header/RLE.h"
using namespace windows_console;
using namespace std;

int main(int argc, char* argv[])
{

	RLE rle("Y:\\HIVER_2020\\projet_oracle\\B62_TP1\\Doc\\FichiersRLE\\fichiers_rle");
	rle.getPatron(); 
	//OptionManager manager(argc, argv);
	Univers univers;
	Vue vue;

	Controleur controleur(univers, vue);
	controleur.start();
	return 0;
}






