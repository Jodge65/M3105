#include "Individu.h"
#include "Outils.h"
#include <sstream>

Individu::Individu(): nom(""), prenom(""), anneeNaissance(0){}

Individu::Individu(std::string nom, std::string prenom, int anneeNaissance): nom(nom), prenom(prenom), anneeNaissance(anneeNaissance){}



std::string Individu::getNom() const
{
    return nom;
}

std::string Individu::getPrenom() const
{
    return prenom;
}

int Individu::getAnneeNaissance() const
{
    return anneeNaissance;
}

void Individu::setNom(std::string nom)
{
    this->nom = nom;
}

void Individu::setPrenom(std::string prenom)
{
    this->prenom = prenom;
}

void Individu::setAnneeNaissance(int anneeNaissance)
{
    this->anneeNaissance = anneeNaissance;
}

int Individu::getAge() const
{
    Outils o;
    return o.anneeActuelle() - anneeNaissance;
    //return Outils::anneeActuelle() - anneeNaissance;
}

std::string Individu::toString() const
{
    std::ostringstream dateNaissance;
    dateNaissance << anneeNaissance;
    std::ostringstream age;
    age << getAge();

    return "Individu:[nom=" + nom + ",prenom=" + prenom + ",anneeNaissance=" + dateNaissance.str() + ",age=" + age.str() + "]\n";
}



