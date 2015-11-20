#ifndef _INDIVIDU
#define _INDIVIDU

#include <iostream>
#include "Voiture.h"
class Voiture;

class Individu
{
	public:
        std::string nom;
	    std::string prenom;
	    Voiture* maVoiture;

	public:
		Individu(std::string nom = "empty", std::string prenom = "empty", Voiture* maVoiture = 0);

        void afficher();
        void afficherTout();

        void majMaVoiture(Voiture* maVoiture);
        void supprimerLien();

        void setMaVoiture(Voiture* maVoiture);

        ~Individu();

};

#endif

