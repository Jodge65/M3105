#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <termios.h>

using namespace std;

#define ESC '\033'
#define TRUE 1
#define FALSE 0

////////////////////////////// Terminal
class Terminal
{
public:

    void clear ()
    {
        cout << ESC << "[H" << ESC << "[2J";
    };

    void charplot (int l, int c, char motif)
    {
        cout << ESC << '[' << l << ';' << c << 'H' << motif;
    };

    void stringplot (int l, int c, char *string)
    {
        cout << ESC << '[' << l << ';' << c << 'H' << string;
    };
};


////////////////////////////// Graphique
class Graphique
{
public :
    // operations � sp�cialiser selon l'objet compos� / simple
    virtual void afficher (Terminal) { };
    virtual void effacer (Terminal) { };
    virtual void deplacerDe (int, int) { };

    // m�thodes permettant de g�rer la composition
    virtual void ajouter (Graphique*) { };
    virtual void supprimer (Graphique*) { };
    virtual int acqEnfant ()
    {
        return 0;
    };
protected:
    virtual void dessiner (bool, Terminal) {};
};


////////////////////////////// GraphiqueSimple
class GraphiqueSimple : public Graphique
{
public :
    void afficher (Terminal);
    void effacer (Terminal);
    virtual void deplacerDe (int, int) { };
};

void GraphiqueSimple::afficher (Terminal t)
{
    dessiner (TRUE, t);
}

void GraphiqueSimple::effacer (Terminal t)
{
    dessiner (FALSE, t);
}


////////////////////////////// Point
class Point : public GraphiqueSimple
{
private :
    char motif;
    int x, y;

public :
    Point (int, int, char);
    void definir (int, int);
    virtual void deplacerDe (int, int);
protected :
    void dessiner (bool, Terminal);
};

Point::Point (int a, int b, char c = 'o')
{
    definir (a, b);
    motif = c;
}

void Point::definir (int a, int b)
{
    x = a;
    y = b;
}

void Point::deplacerDe (int dx, int dy)
{
    x += dx;
    y += dy;
}

void Point::dessiner (bool marquer, Terminal t)
{
    t.charplot (x, y, marquer ? motif : ' ');
}

////////////////////////////// ---------------------------- Trait
class Trait : public GraphiqueSimple
{
private :
    int x, y, taille;
    bool direction;
public :
    Trait (int, int, int, char, bool);
    void definir (int, int, int, bool vertical = false);
    virtual void deplacerDe (int, int);
protected :
    char motif;
    void dessiner (bool, Terminal);
};
Trait::Trait (int a, int b, int t, char c = 'o', bool vertical = false)
{
    definir (a, b, t, vertical);
    motif = c;
}

void Trait::definir (int a, int b, int t, bool vertical)
{
    x = a;
    y = b;
    taille = t, direction = vertical;
}
void Trait::deplacerDe (int dx, int dy)
{
    x += dx;
    y += dy;
}
void Trait::dessiner (bool marquer, Terminal t)
{
    int i;

    if (direction)
    {
        for (i = 0; i < taille; i++)
            t.charplot (x + i, y, marquer ? motif : ' ');
    }
    else
    {
        for (i = 0; i < taille; i++)
            t.charplot (x, y + i, marquer ? motif : ' ');
    }
}

////////////////////////////// ---------------------------- Rectangle
class Rectangle : public GraphiqueSimple
{
private :
    int x1, y1, longeur, Largeur;
public :
    Rectangle (int, int, int, int, char);
    void definir (int, int, int, int);
    virtual void deplacerDe (int, int);
protected :
    char motif;
    void dessiner (bool, Terminal);
};
Rectangle::Rectangle(int x1, int y1, int longeur, int Largeur, char c = '0')
{
    definir (x1, y1, longeur, Largeur);
    motif = c;
}
void Rectangle::definir (int x1, int y1, int longeur, int Largeur)
{
    this->x1 = x1;
    this->y1 = y1;
    this->longeur = longeur;
    this->Largeur = Largeur;
}
void Rectangle::dessiner (bool marquer, Terminal t)
{
    int i;

    for (i = 0; i <= longeur; i++)
        t.charplot (x1 + i, y1, marquer ? motif : ' ');
    for (i = 0; i <= Largeur; i++)
        t.charplot (x1, y1 + i, marquer ? motif : ' ');

    for (i = 0; i <= longeur; i++)
        t.charplot (x1 + i, y1 + Largeur, marquer ? motif : ' ');
    for (i = 0; i <= Largeur; i++)
        t.charplot (x1 + longeur, y1 + i, marquer ? motif : ' ');
}
void Rectangle::deplacerDe (int dx, int dy)
{
    x1 += dx;
    y1 += dy;
}

////////////////////////////// GraphiqueCompose
class GraphiqueCompose : public Graphique
{
private :
    int nbEnfants;
    Graphique* lesEnfants[10];
public :
    GraphiqueCompose ()
    {
        nbEnfants = 0;
    };
    virtual void afficher (Terminal);
    virtual void effacer (Terminal);
    virtual void deplacerDe (int, int);
    virtual void ajouter (Graphique*);
    virtual void supprimer (Graphique*) { };
    virtual int acqEnfant ()
    {
        return 1;
    };
};


void GraphiqueCompose::afficher (Terminal t)
{
    for(int i = 0; i < nbEnfants; i++)
    {
        lesEnfants[i]->afficher(t);
    }
}

void GraphiqueCompose::effacer (Terminal t)
{
    for(int i =0; i < nbEnfants; i++)
    {
        lesEnfants[i]->effacer(t);
    }
}

void GraphiqueCompose::deplacerDe (int dx, int dy)
{
    for(int i =0; i < nbEnfants; i++)
    {
        lesEnfants[i]->deplacerDe(dx, dy);
    }
}

void GraphiqueCompose::ajouter (Graphique* g)
{
    lesEnfants[nbEnfants] = g;
    nbEnfants++;
}

////////////////////////////// main tp6v2incomplet.cpp
main ()
{
    char c;
    Terminal t;
    Point p1 (6, 10, '*'), p2 (6, 20, '#'), p3 (10, 15);
    Trait t1 (12, 48, 5, '-');
    Rectangle c1 (15, 14, 4, 10, '*');
    GraphiqueCompose gc;
    gc.ajouter(&p1);
    gc.ajouter(&p2);
    gc.ajouter(&p3);
    gc.ajouter(&t1);
    gc.ajouter(&c1);




    t.clear ();

    t.stringplot (20, 1, "TP6-V2 taper un car (affiche graphique compose) : ");
    cin >> c;
    gc.afficher (t);

    t.stringplot (20, 1, "TP6-V2 taper un car (efface graphique compose)  : ");
    cin >> c;
    gc.effacer (t);

    t.stringplot (20, 1, "TP6-V2 taper un car (deplace graphique compose) : ");
    cin >> c;
    gc.deplacerDe (-5, 10);

    t.stringplot (20, 1, "TP6-V2 taper un car (affiche graphique compose) : ");
    cin >> c;
    gc.afficher (t);

    t.stringplot (20, 1, "T E R M I N E ...");
}
