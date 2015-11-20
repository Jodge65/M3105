#ifndef _INDIVIDU
#define _INDIVIDU

#include <iostream>

class Individu
{
	protected:
        std::string nom;
        std::string prenom;
        int anneeNaissance;

	public:
		Individu();
		Individu(std::string nom, std::string prenom, int anneeNaissance);

		std::string getNom()const;
		std::string getPrenom()const;
		int getAnneeNaissance()const;

        void setNom(std::string nom);
        void setPrenom(std::string prenom);
        void setAnneeNaissance(int anneeNaissance);

        virtual int getAge()const;

        std::string toString()const;

};


#endif

