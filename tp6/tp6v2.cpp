
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
class Terminal {
public:

	void clear () {
	  cout << ESC << "[H" << ESC << "[2J";
	};

	void charplot (int l, int c, char motif) {
	  cout << ESC << '[' << l << ';' << c << 'H' << motif;
	};

	void stringplot (int l, int c, char *string) {
	  cout << ESC << '[' << l << ';' << c << 'H' << string;
	};
};


////////////////////////////// Graphique
class Graphique {
public :
	// operations � sp�cialiser selon l'objet compos� / simple
	virtual void afficher (Terminal) { };
	virtual void effacer (Terminal) { };
	virtual void deplacerDe (int, int) { };

	// m�thodes permettant de g�rer la composition
	virtual void ajouter (Graphique*) { };
	virtual void supprimer (Graphique*) { };
	virtual int acqEnfant () {  return 0;  };
protected:
	virtual void dessiner (bool, Terminal) {};
};




////////////////////////////// GraphiqueSimple
class GraphiqueSimple : public Graphique {
public :
	void afficher (Terminal);
	void effacer (Terminal);
	virtual void deplacerDe (int, int) { };
};

void GraphiqueSimple::afficher (Terminal t) {
	dessiner (TRUE, t);
}

void GraphiqueSimple::effacer (Terminal t) {
	dessiner (FALSE, t);
}


////////////////////////////// Point
class Point : public GraphiqueSimple {
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

Point::Point (int a, int b, char c = 'o') {
	definir (a, b);
	motif = c;
}

void Point::definir (int a, int b) {
	x = a; y = b;
}

void Point::deplacerDe (int dx, int dy) {
	x += dx; y += dy;
}

void Point::dessiner (bool marquer, Terminal t) {
	t.charplot (x, y, marquer ? motif : ' ');
}


////////////////////////////// GraphiqueCompose
class GraphiqueCompose : public Graphique {
private :
	int nbEnfants;
	Graphique* lesEnfants[10];
public :
	GraphiqueCompose () { nbEnfants = 0; };
	virtual void afficher (Terminal);
	virtual void effacer (Terminal);
	virtual void deplacerDe (int, int);
	virtual void ajouter (Graphique*);
	virtual void supprimer (Graphique*) { };
	virtual int acqEnfant () {  return 1;  };
};


void GraphiqueCompose::afficher (Terminal t) {
// ........... A VOUS DE FAIRE ............
}

void GraphiqueCompose::effacer (Terminal t) {
// ........... A VOUS DE FAIRE ............
}

void GraphiqueCompose::deplacerDe (int dx, int dy) {
// ........... A VOUS DE FAIRE ............
}

void GraphiqueCompose::ajouter (Graphique* g) {
// ........... A VOUS DE FAIRE ............
}



////////////////////////////// main tp6v2incomplet.cpp
main () {
	char c;
	Terminal t;
	Point p1 (6, 10, '*'), p2 (6, 20, '#'), p3 (10, 15);

	GraphiqueCompose gc;
	// initialiser l'objet "gc" en lui attribuant les 3 fils !
	// ........... A VOUS DE FAIRE ............

	t.clear ();

	t.stringplot (20, 1, "TP6-V2 taper un car (affiche graphique compose) : ");
	cin >> c; gc.afficher (t);

	t.stringplot (20, 1, "TP6-V2 taper un car (efface graphique compose)  : ");
	cin >> c; gc.effacer (t);

	t.stringplot (20, 1, "TP6-V2 taper un car (deplace graphique compose) : ");
	cin >> c; gc.deplacerDe (-5, 10);

	t.stringplot (20, 1, "TP6-V2 taper un car (affiche graphique compose) : ");
    cin >> c; gc.afficher (t);

	t.stringplot (20, 1, "T E R M I N E ...");
}
