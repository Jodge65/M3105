#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <termios.h>

#define ESC '\033'
#define TRUE 1
#define FALSE 0


/**
* @author Joey
* @version 1.0.0
*/

using namespace std;

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

////////////////////////////// GraphiqueSimple
class GraphiqueSimple
{
public :
    void afficher (Terminal);
    void effacer (Terminal);
protected:
    virtual void dessiner (bool, Terminal) {};
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
    int x, y;
public :
    Point (int, int, char);
    void definir (int, int);
    virtual void dessiner (bool, Terminal);
protected :
    char motif;

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

void Point::dessiner (bool marquer, Terminal t)
{
    t.charplot (x, y, marquer ? motif : ' ');
}

class Trait : public GraphiqueSimple
{
private :
    int x, y, taille;
    bool direction;
public :
    Trait (int, int, int, char, bool);
    void definir (int, int, int, bool vertical = false);
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

class Rectangle : public GraphiqueSimple
{
private :
    int x1, y1, longeur, Largeur;
public :
    Rectangle (int, int, int, int, char);
    void definir (int, int, int, int);
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
////////////////////////////// main tp6v1.cpp
main ()
{
    Terminal t;
    char c;
    Point p1 (6, 10, '*'), p2 (6, 20, '#'), p3 (10, 15);
    Trait t1 (2, 2, 5, '-');
    //Trait t2 (20, 15, 8, 'à', true);
    Rectangle c1 (6, 6, 4, 4, '*');

    t.clear ();
    t.stringplot (20, 1, "TP6-V1 taper un car (affiche point c1) : ");
    cin >> c;
    c1.afficher (t);

    t.stringplot (20, 1, "TP6-V1 taper un car (affiche point t1) : ");
    cin >> c;
    t1.afficher (t);

    //t.stringplot (20, 1, "TP6-V1 taper un car (affiche point t2) : ");
    //cin >> c; t2.afficher (t);

    t.stringplot (20, 1, "TP6-V1 taper un car (affiche point p1) : ");
    cin >> c;
    p1.afficher (t);

    t.stringplot (20, 1, "TP6-V1 taper un car (affiche point p2) : ");
    cin >> c;
    p2.afficher (t);

    t.stringplot (20, 1, "TP6-V1 taper un car (affiche point p3) : ");
    cin >> c;
    p3.afficher (t);

    t.stringplot (20, 1, "T E R M I N E ...");
}
