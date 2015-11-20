#include <iostream>
#include "SingletonDirecteurIUT.h"

using namespace std;

int main()
{
    SingletonDirecteurIUT *directeur, *leChef;
    directeur = SingletonDirecteurIUT::getInstance();
    directeur->setNom("Nodenot");
    directeur->setPrenom("Thierry");
    leChef = SingletonDirecteurIUT::getInstance();
    cout << "Le Chef : " << leChef->getPrenom() << " " << leChef->getNom() << endl;

    return 0;
}
