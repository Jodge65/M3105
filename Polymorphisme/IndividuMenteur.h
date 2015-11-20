#ifndef _INDIVIDUMENTEUR
#define _INDIVIDUMENTEUR

#include <iostream>
#include "Individu.h"

class IndividuMenteur : public Individu
{
	public:
		IndividuMenteur();
		IndividuMenteur(std::string nom, std::string prenom, int anneeNaissance);

        virtual int getAge()const;

};


#endif

