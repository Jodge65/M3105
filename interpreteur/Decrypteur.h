#ifndef DECRYPTEUR_H_INCLUDED
#define DECRYPTEUR_H_INCLUDED

#include <iostream>
#include "Contexte.h"
#include "Programme.h"
#include "BooleanExp.h"

#include <fstream>
#include <list>

using namespace std;

class Decrypteur
{
public:
    static Programme* getProgramme(string fileName)
    {
        fstream file(fileName.c_str(), ios::in);

        list<Instruction*> listOfInstruction;
        list<Instruction*>::iterator it = listOfInstruction.begin();
        //listOfInstruction.push_back(NULL);
        if(file)
        {
            string temps;
            while(getline(file, temps))
            {
                list<string> functionFull = getFunction(temps);
                if((*functionFull.begin()) == "end")
                {
                    *it =  new Instructions(NULL, NULL);
                    break;
                }
                else
                {
                    it = listOfInstruction.end();
                    listOfInstruction.push_back(getInstruction(functionFull));
                    listOfInstruction.push_back(NULL);
                    /*Instruction* i0 = *it;
                    Instruction* i1 = *it++;
                    Instruction* i2 = *it++;
                    i0 =  new Instructions(i1, i2);*/
                    *it =  new Instructions(*(it++), *((it++)++));
                    //it++; it++;
                }
            }
            cout << " ### " << *listOfInstruction.begin() << endl;
            file.close();
        }
        else
        {
            cout << "[ERREUR] ouvertur du fichier  \"" << fileName << "\" impossible..." << endl;
        }


        return (*listOfInstruction.begin());
    };

    static list<string> getFunction(string line)
    {
        list<string> fullFunction;
        char temps;

        string buffer = "";
        int i = 0;
        while((temps = line[i]) != ' ' && temps != '(' && temps != ';')
        {
            buffer += temps;
            i++;
        }
        fullFunction.push_back(buffer);

        while(line[i] != ';')
        {
            i++;
            if(line[i] == ' ') i++;
            else if (line[i] == ';') break;

            while((temps = line[i]) != ',' && temps != ')' && temps != ';')
            {
                if(temps != '"')
                    buffer += temps;
                i++;
            }
            fullFunction.push_back(buffer);
        }

        return fullFunction;
    };

    static Instruction* getInstruction(list<string> fullFunction)
    {
        list<string>::iterator it = fullFunction.begin();
        string temps = *it;
        it++;
        string text = (*it).substr(temps.size());
        Instruction* myFunction;

        if(temps == "afficher")
            myFunction = new EditionTexte(text);
        else if(temps == "saisir")
            myFunction = new Saisit(text);
        else if(temps == "affecter")
        {
            it++;
            bool value = (*it == "true" || *it == "vrai");
            it--;
            myFunction = new Affectation(text, value);
        }


        return myFunction;
    }

};


#endif // DECRYPTEUR_H_INCLUDED
