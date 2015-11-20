#include <iostream>
#include "Voiture.h"
#include "Individu.h"

using namespace std;

int main()
{
    Voiture voit1("RenaultClio", "123AB64") ;
    Voiture voit2("Peugeot106", "678CD96") ;
    Voiture voit3("CitroenPicasso", "456EF75") ;
    Individu ind1 ("Dupond", "Pierre") ;
    Individu ind2 ("Martin", "Louis") ;
    Individu ind3 ("Durand", "Marcel") ;

    cout << "#1# --------------- " << endl;
    voit1.afficher();
    voit2.afficher();
    voit3.afficher();
    ind1.afficher();
    ind2.afficher();
    ind3.afficher();
    cout << "#2# --------------- " << endl;
    ind3.maVoiture = &voit3;
    voit3.monConducteur = &ind3;
    ind3.maVoiture->plaqueImmatriculation = "77777NO22";
    voit3.afficher();
    cout << "#4# --------------- " << endl;
    voit3.afficherTout();
    cout << "#5# --------------- " << endl;
    ind2.setMaVoiture(&voit3);
    voit1.afficherTout();
    voit2.afficherTout();
    voit3.afficherTout();
    ind1.afficherTout();
    ind2.afficherTout();
    ind3.afficherTout();

    cout << "#6# --------------- " << endl;

    voit3.afficherTout();

    return 0;
}
