#ifndef CONTEXTE_H_INCLUDED
#define CONTEXTE_H_INCLUDED

#include <iostream>
#include <map>

using namespace std;

class Contexte
{
public:
    typedef map<string, bool> MapDeBool;
    void affecter(string key, bool val){value.insert(MapDeBool::value_type(key, val));};
    bool consulter(string key){return value[key];};
protected:
    MapDeBool value;

};

#endif // CONTEXTE_H_INCLUDED
