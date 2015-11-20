#include "SingletonDirecteurIUT.h"


SingletonDirecteurIUT* SingletonDirecteurIUT::_instance=NULL;

SingletonDirecteurIUT::SingletonDirecteurIUT():nom(""), prenom("") {}
SingletonDirecteurIUT::~SingletonDirecteurIUT() {}

SingletonDirecteurIUT* SingletonDirecteurIUT::SingletonDirecteurIUT::getInstance()
{
    if(_instance == NULL)
        _instance = new SingletonDirecteurIUT();
    return _instance;
}

void SingletonDirecteurIUT::SingletonDirecteurIUT::killInstance()
{
    if(_instance != NULL)
    {
        delete _instance;
        _instance = NULL;
    }
}

void SingletonDirecteurIUT::setNom(std::string nom)
{
    this->nom = nom;
}

void SingletonDirecteurIUT::setPrenom(std::string prenom)
{
    this->prenom = prenom;
}

std::string SingletonDirecteurIUT::getNom()const
{
    return nom;
}

std::string SingletonDirecteurIUT::getPrenom()const
{
    return prenom;
}

