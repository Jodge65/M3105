#include "Outils.h"
#include "time.h"

int Outils::anneeActuelle ()
{
    time_t timer;
    struct tm *newTime;
    time (&timer);
    newTime = localtime(&timer);
    return newTime->tm_year + 1900;
}


void Outils::afficheAgeIndividuParValeur(Individu ind)
{
    std::cout << ind.toString();
}

void Outils::afficheAgeIndividuParReference(Individu& ind)
{
    std::cout << ind.toString();
}

void Outils::afficheAgeIndividuParAdresse(Individu* ind)
{
    std::cout << ind->toString();
}
