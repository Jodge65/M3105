#include <iostream>
#include "Individu.h"
#include "IndividuMenteur.h"
#include "Outils.h"

using namespace std;

int main()
{
    Individu ind1("Individu_1", "", 1960);
    IndividuMenteur ind2("Individu_2", "", 1960);
    IndividuMenteur ind3("Individu_3", "", 1990);

    Outils o;
    cout << "Année actuel : " << o.anneeActuelle() << endl;
    cout << "Individu_1 est née en : " << ind1.getAnneeNaissance() << " et prétend avoir : " << ind1.getAge() << " ans." << endl;
    cout << "Individu_2 est née en : " << ind2.getAnneeNaissance() << " et prétend avoir : " << ind2.getAge() << " ans." << endl;
    cout << "Individu_3 est née en : " << ind3.getAnneeNaissance() << " et prétend avoir : " << ind3.getAge() << " ans." << endl;

    o.afficheAgeIndividuParValeur(ind1);
    o.afficheAgeIndividuParReference(ind1);
    o.afficheAgeIndividuParAdresse(&ind1);
    cout << endl;
    o.afficheAgeIndividuParValeur(ind2);
    o.afficheAgeIndividuParReference(ind2);
    o.afficheAgeIndividuParAdresse(&ind2);
    cout << endl;
    o.afficheAgeIndividuParValeur(ind3);
    o.afficheAgeIndividuParReference(ind3);
    o.afficheAgeIndividuParAdresse(&ind3);

    return 0;
}
