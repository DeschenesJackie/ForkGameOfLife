#include "../Header/Vue.h"
#include "../Header/Constantes.h"
#include <windows_console.h>
#include <iostream>
#include <string>

using namespace std;
using namespace windows_console;

const string NAME("Game of life");
const string FONT_FAMILY("Consolas");
const int PRECEDENT{ -1 }, COURANT{ 0 }, SUIVANT{ 1 };

void formaterFenetre();
void capterEvenement(); 

Vue::Vue() {
	formaterFenetre();
}

void formaterFenetre() {
	csl << window::title(NAME)
		<< window::fit(LARGEUR, HAUTEUR, FONT_FAMILY, 3, 1.0)
		<< window::unresizable
		<< window::unclosable
		<< window::center
		<< cursor::invisible;

	image im;
	csl >> im;
}

void capterEvenement() {
	bool quit{};
	int multiplier{0};
	int pourcentage{0};
	int fichier = COURANT;

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
			case 'R':	/* À faire */		break;	// Basculer vers diff. règles (B3/S23, B36/S23, B3678/S34678, une règle de votre crue)
			case 'b':
			case 'B':	/* À faire */		break;	// Basculer entre 2 regles pour gestion des bords (bordures mortes, bordures cycliques)
			case 'p':
			case 'P':	/* À faire */		break;	// Bascule entre les différentes couleurs pour les cellules actives (blanc intense, rouge intense, vert intense, bleu intense, jaune intense, magenta intense, cyan intense)
			case 'o':
			case 'O':	/* À faire */		break;	// Bascule le mode de couleur pour les cellules inactives (noir, même couleur que les cellules actives mais foncées)

			case 'a':
			case 'A':	pourcentage = 1;	break;	// Génération aléatoire selon le pourcentage de chance que Cell soit vivante
			case 's':
			case 'S':	pourcentage = 5;	break;	// Génération aléatoire selon le pourcentage de chance que Cell soit vivante
			case 'd':
			case 'D':	pourcentage = 10;	break;	// Génération aléatoire selon le pourcentage de chance que Cell soit vivante
			case 'f':
			case 'F':	pourcentage = 15;	break;	// Génération aléatoire selon le pourcentage de chance que Cell soit vivante
			case 'g':
			case 'G':	pourcentage = 25;	break;	// Génération aléatoire selon le pourcentage de chance que Cell soit vivante
			case 'h':
			case 'H':	pourcentage = 50;	break;	// Génération aléatoire selon le pourcentage de chance que Cell soit vivante

			case 'z':
			case 'Z':	fichier = PRECEDENT;
			case 'x':
			case 'X':	fichier = COURANT;
			case 'c':
			case 'C':	fichier = SUIVANT;


			case 27: quit = true; break;
			}
		}
	}
}