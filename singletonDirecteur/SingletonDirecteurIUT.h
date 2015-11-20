#ifndef _SINGLETONDIRECTEURIUT
#define _SINGLETONDIRECTEURIUT

#include <iostream>


class SingletonDirecteurIUT
{
	protected:
		SingletonDirecteurIUT();
		~SingletonDirecteurIUT();
        static SingletonDirecteurIUT* _instance;
        std::string nom, prenom;

	public:
        static SingletonDirecteurIUT* getInstance();
        static void killInstance();
        std::string getNom()const;
        std::string getPrenom()const;
        void setNom(std::string nom);
        void setPrenom(std::string prenom);

};

#endif

