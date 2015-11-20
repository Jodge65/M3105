#ifndef _OUTILS
#define _OUTILS
#include "Individu.h"
class Outils
{
	public:
        int anneeActuelle();
        void afficheAgeIndividuParValeur (Individu ind);
        void afficheAgeIndividuParReference (Individu &ind);
        void afficheAgeIndividuParAdresse (Individu* ind);
};


#endif

