#ifndef _VOITURE
#define _VOITURE

#include <iostream>
#include "Individu.h"
class Individu;

class Voiture
{
	public:
	    std::string marque;
	    std::string plaqueImmatriculation;
	    Individu* monConducteur;

	public:
		Voiture(std::string marque = "empty", std::string plaqueImmatriculation = "empty", Individu* monConducteur = 0);

        void afficher();
        void afficherTout();

        void majMonConducteur(Individu* monConducteur);
        void supprimerLien();

        void setMonConducteur(Individu* monConducteur);

        ~Voiture();
};

#endif

