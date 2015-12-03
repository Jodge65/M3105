#include <iostream>

#include <list>
#include <map>
#include <utility>


using namespace std;

void listeSimple();
void listePair();
void listeMap();

int main()
{
    cout << "#1# --- --- --- --- --- --- --- --- --- --- --- ---" << endl;
    listeSimple();
    cout << "#2# --- --- --- --- --- --- --- --- --- --- --- ---" << endl;
    listePair();
    cout << "#3# --- --- --- --- --- --- --- --- --- --- --- ---" << endl;
    listeMap();

    return 0;
}

void listeSimple()
{
    typedef list<string> ListeS;

    ListeS uneListeS;

    uneListeS.push_back("Eliana");
    uneListeS.push_back("Khouloud");
    uneListeS.push_back("Philippe");
    uneListeS.push_back("Xabi");

    for(ListeS::iterator i = uneListeS.begin(); i!=uneListeS.end(); i++)
    {
        cout << "Nom :" << *i << endl;
    }
}

void listePair()
{
    typedef list <pair<string, string> > ListeP;

    ListeP uneListeP;

    uneListeP.push_back(ListeP::value_type ("Khouloud","06.01.01.01.01"));
    uneListeP.push_back(ListeP::value_type ("Eliana","06.02.02.02.02"));
    uneListeP.push_back(ListeP::value_type ("Philippe","06.03.03.03.03"));
    uneListeP.push_back(ListeP::value_type ("Xabi","06.04.04.04.04"));

    for(ListeP::iterator i = uneListeP.begin(); i!=uneListeP.end(); i++)
    {
        cout << "Nom : " << i->first << ", Tel : " << i->second << endl;
    }
}

void listeMap()
{
    typedef map<string, string > Annuaire;

    Annuaire uneListeM;

    uneListeM.insert(Annuaire::value_type("Khouloud", "06.01.01.01.01"));
    uneListeM.insert(Annuaire::value_type("Eliana", "06.02.02.02.02"));
    uneListeM.insert(Annuaire::value_type("Philippe", "06.03.03.03.03"));
    uneListeM.insert(Annuaire::value_type("Xabi", "06.04.04.04.04"));

    for(Annuaire::iterator i = uneListeM.begin(); i!=uneListeM.end(); i++)
    {
        cout << "Nom : " << i->first << ", Tel : " << i->second << endl;
    }

    Annuaire::iterator f = uneListeM.find("Xabi");
    if(f != uneListeM.end())
        cout << "Tel : " << f->second << endl;
}

