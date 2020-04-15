#include "../Header/Vue.h"
#include "../Header/Constantes.h"
#include <windows_console.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using namespace windows_console;

const string NAME(NOMPROG);
const string FONT_FAMILY(FONTFAMILY);



void Vue::formatterFenetre() {
	csl << window::title(NAME)
		<< window::fit(LARGEUR, HAUTEUR, FONT_FAMILY, 3, 1.0)
		<< window::unresizable
		<< window::unclosable
		<< window::center
		<< cursor::invisible;
	
	csl >> image;
	image << pen(dot, text_color(bright, white), background_color(bright, white));
	csl << image;
}

Vue::Vue(RLE &rle)
:mRLE{rle}
{
	formatterFenetre();

}

void Vue::pause() {
	if (simStatus) {
		simStatus=false;
	}
	else { simStatus=true; }
}

void Vue::basculeModeCouleur()
{
	if (modeCouleur)
	{
		modeCouleur = false;
	}
	else
	{
		modeCouleur = true;
	}
}

bool Vue::getEffetsBords() {
	return effetsBords;
}

int Vue::getMultiplier()
{
	return multiplier;
}

void Vue::nextCouleur() {
	++compteurCouleur;
	if (compteurCouleur == 7) 
	{
		compteurCouleur = 0;
	}	
}

void Vue::setCustomRegle(std::string s) {
	mCustomRegle = s;
}

void Vue::getCouleur() {
	switch (compteurCouleur)
	{
	case 0: image << pen(dot, text_color(bright, white), background_color(bright, white));
		image << brush(dot, text_color(dark, white), background_color(dark, white));
		break;
	case 1: image << pen(dot, text_color(bright, red), background_color(bright, red));
		image << brush(dot, text_color(dark, red), background_color(dark, red));
		break;
	case 2: image << pen(dot, text_color(bright, green), background_color(bright, green));
		image << brush(dot, text_color(dark, green), background_color(dark, green));
		break;
	case 3: image << pen(dot, text_color(bright, blue), background_color(bright, blue));
		image << brush(dot, text_color(dark, blue), background_color(dark, blue));
		break;
	case 4:	image << pen(dot, text_color(bright, yellow), background_color(bright, yellow));
		image << brush(dot, text_color(dark, yellow), background_color(dark, yellow));
		break;
	case 5: image << pen(dot, text_color(bright, magenta), background_color(bright, magenta));
		image << brush(dot, text_color(dark, magenta), background_color(dark, magenta));
		break;
	case 6: image << pen(dot, text_color(bright, cyan), background_color(bright, cyan));
		image << brush(dot, text_color(dark, cyan), background_color(dark, cyan));
		break;
	}
	if (modeCouleur) {
		image << brush(dot, text_color(dark, black), background_color(dark, black));
	}
}

void Vue::nextRegle() {
	++compteurRegle;
	if (compteurRegle == 4)
	{
		compteurRegle = 0;
	}
}

string Vue::getNomRegle() {
		
	switch (compteurRegle)
	{
		case 0: nomRegle = REGLE1;			break;
		case 1: nomRegle = REGLE2;			break;
		case 2: nomRegle = REGLE3;			break;
		case 3: 
			if (mCustomRegle != "")
				nomRegle = mCustomRegle;
			else {
				nextRegle();
				getNomRegle();
			}
			break;
	}
	return nomRegle;
}

int Vue::getPercentage()
{
	return pourcentage;
}


bool Vue::getSimStatus()
{
	return simStatus;
}

void Vue::affiche(vector <Cellule> const & vecteurActif) {
	std::vector<Cellule>::const_iterator iterateur = vecteurActif.cbegin();
	int x{}, y{};
	
	csl >> image;
	getCouleur();
	
	image << fill;

	while (iterateur != vecteurActif.cend()) {
		if (x == LARGEUR) {
			++y; x = 0;
		}
		if (iterateur->etat()) {
			image << point(x, y);
		}
		; // retourne un bool a afficher (true pale false fonce)

		++iterateur;
		++x;
	}
	csl << image;

}

bool Vue::getMQuit() {
	return mQuit;
}

void Vue::gererEffetBords() {
	if (effetsBords == true)
		effetsBords = false;
	else
		effetsBords = true;
}

bool Vue::capterEvenement() {
	console_events consoleEvents;
	consoleEvents.read_events();
	bool recompile = false;
	pourcentage = 0;

	
	csl << key_events::add_filter<key_filter_up>;
	if (consoleEvents.key_events_count() > 0) {
		switch (consoleEvents.next_key_event().ascii_value()) {
			case 32:	pause();			break;	// Espace : Pause/Reprise de la simulation

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
			case 'R':	nextRegle(); recompile = true;		break;	// Basculer vers diff. règles (B3/S23, B36/S23, B3678/S34678, une règle de votre crue)
			case 'b':
			case 'B':	gererEffetBords();		break;	// Basculer entre 2 regles pour gestion des bords (bordures mortes, bordures cycliques)
			case 'p':
			case 'P':	nextCouleur();			break;	// Bascule entre les différentes couleurs pour les cellules actives (blanc intense, rouge intense, vert intense, bleu intense, jaune intense, magenta intense, cyan intense)
			case 'o':
			case 'O':	basculeModeCouleur();	break;	// Bascule le mode de couleur pour les cellules inactives (noir, même couleur que les cellules actives mais foncées)

			case 'a':
			case 'A':	pourcentage = 1; recompile = true;	break;	// Génération aléatoire selon le pourcentage de chance que Cell soit vivante
			case 's':
			case 'S':	pourcentage = 5; recompile = true;	break;	// Génération aléatoire selon le pourcentage de chance que Cell soit vivante
			case 'd':
			case 'D':	pourcentage = 10; recompile = true;	break;	// Génération aléatoire selon le pourcentage de chance que Cell soit vivante
			case 'f':
			case 'F':	pourcentage = 15; recompile = true;	break;	// Génération aléatoire selon le pourcentage de chance que Cell soit vivante
			case 'g':
			case 'G':	pourcentage = 25; recompile = true;	break;	// Génération aléatoire selon le pourcentage de chance que Cell soit vivante
			case 'h':
			case 'H':	pourcentage = 50; recompile = true;	break;	// Génération aléatoire selon le pourcentage de chance que Cell soit vivante

			case 'z':
			case 'Z':	mRLE.previousPatron(); recompile = true;  
						if (!(mRLE.generatePatron())) { mQuit = true;  };	break;
			case 'x':
			case 'X':	recompile = true;	break;
			case 'c':
			case 'C':	mRLE.nextPatron(); recompile = true;  
						if (!(mRLE.generatePatron())) { mQuit = true;  };	break;


			case 27:	mQuit = true;		break;	// Escape
		}
	}
	return recompile;
}