#ifndef PROGRAMME_H_PROGRAMME
#define PROGRAMME_H_PROGRAMME

#include <iostream>
#include "Contexte.h"
#include "BooleanExp.h"

using namespace std;

class Programme
{
public:
    Programme() {};
    virtual bool interprete(Contexte& contexte) = 0;
};

class Instruction : public Programme
{
public:
    Instruction() {};
    virtual bool interprete(Contexte& contexte) = 0;

private:
};

class Instructions : public Instruction
{
public:
    Instructions(Instruction *inst1, Instruction *inst2) {this->inst1 = inst1;;this->inst2 = inst2;};
    virtual bool interprete(Contexte& contexte){
        if(inst1 != NULL)inst1->interprete(contexte);
        if(inst2 != NULL)inst2->interprete(contexte);
        return true;
    };

private:
    Instruction* inst1;
    Instruction* inst2;
};

class Affectation : public Instruction
{
public:
    Affectation(string key, bool value) {this->key = key; this-> value = value;};
    virtual bool interprete(Contexte& contexte){contexte.affecter(key, value); return true;};

private:
    string key;
    bool value;
};

class Saisit : public Instruction
{
public:
    Saisit(string key) {this->key = key;};
    virtual bool interprete(Contexte& contexte){
        string temps;
        cin >> temps;
        bool value = (temps == "true" || temps == "vrai" || temps == "1" || temps == "oui");
        contexte.affecter(key, value);
        return value;
    };

private:
    string key;
    bool value;
};

class Edition : public Instruction
{
public:
    Edition() {}
    virtual bool interprete(Contexte& contexte) = 0;

private:

};

class EditionExpBool : public Edition
{
public:
    EditionExpBool(BooleanExp* value) {this->value = value;}
    virtual bool interprete(Contexte& contexte){
        if(value->interprete(contexte)==1)
        {
            cout << "true";
            return true;
        }
        else
        {
            cout << "false";
            return false;
        }
    };

private:
    BooleanExp* value;
};

class EditionTexte : public Edition
{
public:
    EditionTexte(string texte) {this->texte = texte;}
    virtual bool interprete(Contexte& contexte){cout << texte; return true;};

private:
    string texte;
};

class condition : public Instruction
{
public:
    condition() {}
    virtual bool interprete(Contexte& contexte) = 0;

private:

};

class siAlors : public condition
{
public:
    siAlors(BooleanExp* condition, Instruction* actionSucces) {this->condition = condition; this->actionSucces = actionSucces;};
    virtual bool interprete(Contexte& contexte){
        if(condition->interprete(contexte))
        {
            actionSucces->interprete(contexte);
            return true;
        }
        else
            return false;
};
private:
    BooleanExp* condition;
    Instruction* actionSucces;
};

class siAlorsSinon : public condition
{
public:
    siAlorsSinon(BooleanExp* condition, Instruction* actionSucces, Instruction* actionEchec)
    {
        this->condition = condition;
        this->actionSucces = actionSucces;
        this->actionEchec = actionEchec;
    };
    virtual bool interprete(Contexte& contexte){
        if(condition->interprete(contexte))
        {
            actionSucces->interprete(contexte);
            return true;
        }
        else
        {
            actionEchec->interprete(contexte);
            return false;
        }

    };
private:
    BooleanExp* condition;
    Instruction* actionSucces;
    Instruction* actionEchec;
};



#endif // PROGRAMME_H_INCLUDED
