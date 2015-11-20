#include "Individu.h"

Individu::Individu(std::string nom, std::string prenom, Voiture* maVoiture) : nom(nom), prenom(prenom), maVoiture(maVoiture){}

void Individu::afficher()
{
    std::cout << "Nom : " << nom <<", Prenom : " << prenom << std::endl;
}

void Individu::afficherTout()
{
    afficher();
    if(maVoiture != 0)
        maVoiture->afficher();
    else
        std::cout << "Pas de Voiture" << std::endl;
}

void Individu::majMaVoiture(Voiture* maVoiture)
{
    this->maVoiture->supprimerLien();
    this->maVoiture = maVoiture;
}

void Individu::supprimerLien()
{
    maVoiture = 0;
}

void Individu::setMaVoiture(Voiture* maVoiture)
{
    maVoiture->majMonConducteur(this);
    this->maVoiture = maVoiture;
}

Individu::~Individu()
{
    if(maVoiture != 0)
        maVoiture->supprimerLien();
}
