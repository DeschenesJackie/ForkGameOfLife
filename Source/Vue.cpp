#include "../Header/Vue.h"
#include <windows_console.h>
#include <iostream>
#include <string>

using namespace std;
using namespace windows_console;

const string NAME("Game of life");
const string FONT_FAMILY("Consolas");

void formaterFenetre();

Vue::Vue() {
	formaterFenetre();
}

void formaterFenetre() {
	csl << window::title(NAME)
		<< window::fit(300, 150, FONT_FAMILY, 3, 1.0)
		<< window::unresizable
		<< window::unclosable
		<< window::center
		<< cursor::invisible;

	image im;
	csl >> im;
}

void capterEvenement() {
	bool quit{};
	int multiplier = 0;

	while (!quit) {
		console_events consoleEvents;
		consoleEvents.read_events();
		while (consoleEvents.key_events_count() > 0) {
			switch (consoleEvents.next_key_event().ascii_value()) {
			case '32':	/* À faire */		break;	// Espace : Pause/Reprise de la simulation
			case '1':	multiplier = 1;		break;	// vitesse de la simulation
			case '2': 	multiplier = 2;		break;	// vitesse de la simulation
			case '3':	multiplier = 3;		break;	// vitesse de la simulation
			case '4': 	multiplier = 4;		break;	// vitesse de la simulation
			case '5':	multiplier = 5;		break;	// vitesse de la simulation
			case '6':	multiplier = 6;		break;	// vitesse de la simulation
			case '7':	multiplier = 7;		break;	// vitesse de la simulation
			case '8':	multiplier = 8;		break;	// vitesse de la simulation
			case '9':	multiplier = 9;		break;	// vitesse de la simulation
			case 'r':
			case 'R':	/* À faire */		break;	



			case 27: quit = true; break;
			}
		}
	}
}