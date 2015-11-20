#include "Voiture.h"

Voiture::Voiture(std::string marque, std::string plaqueImmatriculation, Individu* monConducteur) : marque(marque), plaqueImmatriculation(plaqueImmatriculation), monConducteur(monConducteur){}

void Voiture::afficher()
{
    std::cout << "Marque : " << marque << ", Plaque Immatriculation : " << plaqueImmatriculation << std::endl;
}

void Voiture::afficherTout()
{
    afficher();
    if(monConducteur != 0)
        monConducteur->afficher();
    else
        std::cout << "Pas de Conducteur" << std::endl;
}

void Voiture::majMonConducteur(Individu* monConducteur)
{
    this->monConducteur->supprimerLien();
    this->monConducteur = monConducteur;
}

void Voiture::supprimerLien()
{
    monConducteur = 0;
}

void Voiture::setMonConducteur(Individu* monConducteur)
{
    monConducteur->majMaVoiture(this);
    this->monConducteur = monConducteur;
}

Voiture::~Voiture()
{
    if(monConducteur != 0)
        monConducteur->supprimerLien();
}
