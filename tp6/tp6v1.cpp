
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <termios.h>

#define ESC '\033'
#define TRUE 1
#define FALSE 0


/**
* @author P.Lopistéguy
* @version 1.0.0
*/

using namespace std;

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

////////////////////////////// GraphiqueSimple
class GraphiqueSimple {
public :
	void afficher (Terminal);
	void effacer (Terminal);
protected:
	virtual void dessiner (bool, Terminal) {};
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
	int x, y;
public :
	Point (int, int, char);
	void definir (int, int);
protected :
	char motif;
	void dessiner (bool, Terminal);
};

Point::Point (int a, int b, char c = 'o') {
	definir (a, b);
	motif = c;
}

void Point::definir (int a, int b) {
	x = a; y = b;
}

void Point::dessiner (bool marquer, Terminal t) {
	t.charplot (x, y, marquer ? motif : ' ');
//	if (marquer)
//		t.charplot (x, y, motif);
//	else	t.charplot (x, y, ' ');
}


////////////////////////////// main tp6v1.cpp
main () {
	Terminal t;
	char c;
	Point p1 (6, 10, '*'), p2 (6, 20, '#'), p3 (10, 15);

	t.clear ();
	t.stringplot (20, 1, "TP6-V1 taper un car (affiche point p1) : ");
	cin >> c; p1.afficher (t);

	t.stringplot (20, 1, "TP6-V1 taper un car (affiche point p2) : ");
	cin >> c; p2.afficher (t);

	t.stringplot (20, 1, "TP6-V1 taper un car (affiche point p3) : ");
	cin >> c; p3.afficher (t);

	t.stringplot (20, 1, "T E R M I N E ...");
}