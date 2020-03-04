#include <windows_console.h>
#include <iostream>
#include <conio.h>
#include "../Header/Controleur.h"
using namespace windows_console;
using namespace std;

int main(int argc, char* argv[])
{

	//OptionManager manager(argc, argv);
	Univers univers;
	Vue vue;

	Controleur controleur(univers, vue);
	controleur.start();
	return 0;
}






