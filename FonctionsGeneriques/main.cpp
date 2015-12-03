#include <iostream>

#include <list>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

// Class
class Prod
{
    public:
        string refe, lib;
        float prix;
        Prod(string refe, string lib, float prix): refe(refe), lib(lib), prix(prix){}
};
class Piece
{
    public:
        string refe, lib;
        float prix, poids;
        Piece(string refe, string lib, float prix, float poids): refe(refe), lib(lib), prix(prix), poids(poids){}

        static void afficher(Piece* unePiece){cout << "Reference : " << unePiece->refe << ", Libelle : " << unePiece->lib << ", Prix : " << unePiece->prix << ", Poids : " << unePiece->poids << endl;}
        static void surPoids(Piece* unePiece){if(unePiece->poids>80) unePiece->poids *= 1.1;}
        static bool tropCestTrop(Piece* unePiece){return (unePiece->prix > 100);}
};

// Variable
static string STRING_TO_FIND = "Produit_2";

// Fonction
bool referenceCherchee(Prod unProd)
{
    return STRING_TO_FIND == unProd.refe;
};

int main()
{
    /// QUESTION 1
    typedef map<string, pair<string, float> > Produit;

    Produit mpC;
    mpC["Produit_1"] = pair<string, float>("Produit 1", 59.99F);
    mpC["Produit_2"] = pair<string, float>("Produit 2", 159.99F);
    mpC["Produit_3"] = pair<string, float>("Produit 3", 89.99F);

    Produit::iterator i = mpC.find("Produit_1");
    if(i != mpC.end())
        cout << i->second.first << ", " << i->second.second << endl;
    else
        cout << "Echec" << endl;


    /// QUESTION 2
    cout << endl;
   /* struct Prod // Don't work whit list<prod>
    {
        string refe, lib;
        float prix;
        Prod(string refe, string lib, float prix): refe(refe), lib(lib), prix(prix){}
    };*/
    typedef list<Prod> ListProduit;

    Prod p1("Produit_1", "Produit 1", 58.99F);
    Prod p2("Produit_2", "Produit 2", 158.99F);
    Prod p3("Produit_3", "Produit 3", 88.99F);

    ListProduit lp;
    lp.push_back(p1);
    lp.push_back(p2);
    lp.push_back(p3);

    ListProduit::iterator y = find_if(lp.begin(), lp.end(), referenceCherchee);
    if(y != lp.end())
        cout << y->refe << ", " << y->lib << ", " << y->prix << endl;
    else
        cout << "Echec" << endl;
    STRING_TO_FIND = "Produit_4";
    y = find_if(lp.begin(), lp.end(), referenceCherchee);
    if(y != lp.end())
        cout << y->refe << ", " << y->lib << ", " << y->prix << endl;
    else
        cout << "Echec" << endl;

    /// QUESTION 3
    cout << endl;
    typedef list<Piece*> listPiece;
    Piece pi1("Piece_1", "Piece 1", 58.99F, 20.0F);
    Piece pi2("Piece_2", "Piece 2", 158.99F, 500.0F);
    Piece pi3("Piece_3", "Piece 3", 88.99F, 99.99F);
    Piece pi4("Piece_4", "Piece 4", 258.99F, 666.777F);
    listPiece lpi;
    lpi.push_back(&pi1);
    lpi.push_back(&pi2);
    lpi.push_back(&pi3);
    lpi.push_back(&pi4);

    for_each(lpi.begin(), lpi.end(), Piece::surPoids);

    listPiece::iterator z = partition(lpi.begin(), lpi.end(), Piece::tropCestTrop);

    cout << "Prix > 100" << endl;
    for_each(lpi.begin(), z, Piece::afficher);
    cout << "Prix < 100" << endl;
    for_each(z, lpi.end(), Piece::afficher);

    return 0;
}


