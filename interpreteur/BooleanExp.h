#ifndef _BOOLEANEXP
#define _BOOLEANEXP

#include <iostream>
#include "Contexte.h"
using namespace std;


class BooleanExp
{
public:
    BooleanExp() {};
    virtual bool interprete(Contexte& contexte) = 0;
};

///////////////////////// Constant
class Constant : public BooleanExp
{
public:
    Constant(int v){_value = v;};
    bool interprete(Contexte& contexte) {return _value;};
protected:
    bool _value;
};
///////////////////////// VariableExp
class VariableExp : public BooleanExp
{
public:
    VariableExp(const string name){_name = name;};
    bool interprete(Contexte& contexte) {return contexte.consulter(_name);};
protected:
    string _name;
};

///////////////////////// NotExp
class NotExp : public BooleanExp
{
public:
    NotExp(BooleanExp* op){_operand = op;};
    bool interprete(Contexte& contexte) {return !_operand->interprete(contexte);};
protected:
    BooleanExp* _operand;
};

///////////////////////// AndExp
class AndExp : public BooleanExp
{
public:
    AndExp(BooleanExp* op1, BooleanExp* op2){_operand1 = op1; _operand2 = op2;};
    bool interprete(Contexte& contexte) {return (_operand1->interprete(contexte)) && (_operand2->interprete(contexte));};
protected:
    BooleanExp *_operand1, *_operand2;
};
///////////////////////// OrExp
class OrExp : public BooleanExp
{
public:
    OrExp(BooleanExp* op1, BooleanExp* op2){_operand1 = op1; _operand2 = op2;};
    bool interprete(Contexte& contexte) {return (_operand1->interprete(contexte)) || (_operand2->interprete(contexte));};
protected:
    BooleanExp *_operand1, *_operand2;
};



#endif

