/**************************************
PROGRAMME : tp7v0.cpp
BUT : Code a completer en deux phases
Projet 1. Le code de la methode interprete(Contexte&) doit etre renseigne dans
chaque classe et le main () est a completer
Projet 2. Le code de la classe Contexte doit permettre de stocker et de
consulter les couples <identifiant, valeur> grace a un map
DATE CREATION : /
DATE DERNIERE MODIFICATION : /
AUTEUR : Lopisteguy Philippe
COMMENTAIRES : /
***************************************/
#include <iostream>

#include "BooleanExp.h"
#include "Programme.h"
#include "Contexte.h"

#include "Decrypteur.h"

using namespace std;


/**
* @author Jodge
* @version 1.0
* @date 11/01/2016
*
* @name tp8.cpp
*/
///////////////////////// BooleanExp
///////////////////////// tp7v0.cpp
int main ()
{
    Contexte contexte;
    //contexte.affecter("X", false);
    //contexte.affecter("Y", true);

    /*
    *  |   X   |   Y   |  EXP  |
    *  | TRUE  | TRUE  | TRUE  |
    *  | TRUE  | FALSE | TRUE  |
    *  | FALSE | TRUE  | TRUE  |
    *  | FALSE | FALSE | FALSE |
    */
/*
    BooleanExp* expression;
    VariableExp* x = new VariableExp("X");
    VariableExp* y = new VariableExp("Y");
    expression = new OrExp(
        new AndExp(new Constant(true), x),
        new AndExp(y, new NotExp(x))
    );

    Programme* prog;
    prog =  new Instructions(
                new EditionTexte("Veuillez entrer une valeur pour X : "),
                new Instructions(
                    new Saisit("X"),
                    new Instructions(
                        new EditionTexte("Veuillez entrer une valeur pour Y : "),
                        new Instructions(
                            new Saisit("Y"),
                            new Instructions(
                                new EditionTexte("La valeur du BooleanExp est de : "),
                                new Instructions(
                                    new EditionExpBool(expression),
                                    NULL
                                )
                            )
                        )
                    )
                )
            );
*/
    BooleanExp* expression = new VariableExp("X");

    Programme* prog;
    prog =  new Instructions(
                new EditionTexte("Né avant 1998 ?\n"),
                new Instructions(
                    new Saisit("X"),
                    new Instructions(
                        new EditionTexte("Dans ce cas vous êtes : "),
                        new siAlorsSinon(expression,
                            new EditionTexte("Majeur !\n"),
                            new EditionTexte("Mineur !\n")
                        )
                    )
                )
            );

   // Programme* prog = Decrypteur::getProgramme("test.txt");
    prog->interprete(contexte);

    //cout << "Le résultat de l'expression boolean est : " << expression->interprete(contexte) << endl;

    return 0;
}
