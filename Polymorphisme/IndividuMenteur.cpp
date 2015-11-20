#include "IndividuMenteur.h"
#include "Outils.h"

IndividuMenteur::IndividuMenteur():Individu::Individu(){}

IndividuMenteur::IndividuMenteur(std::string nom, std::string prenom, int anneeNaissance):Individu::Individu(nom, prenom, anneeNaissance){}


int IndividuMenteur::getAge() const
{
    Outils o;
	int age = o.anneeActuelle() - anneeNaissance;
    return  age - (age>30? 2:0);

}
