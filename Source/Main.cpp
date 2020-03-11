#include <windows_console.h>
#include <iostream>
#include <conio.h>
#include "../Header/Controleur.h"
#include "../Header/OptionManager.h"
using namespace windows_console;
using namespace std;

int main(int argc, char* argv[])
{
	OptionManager manager(argc, argv);
	Univers univers;
	Vue vue;

	manager.evaluationOption();
	if (manager.mRegleValide) {
		univers.setRegle(manager.mRegle);
	}

	Controleur controleur(univers, vue);
	controleur.start();
	return 0;
}






