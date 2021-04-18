#ifndef CLUES_H
#define CLUES_H

#include <map>
#include <string>
#include <iostream>
using namespace std;

class clues
{
protected:
    string description;
    string name;

public:
    clues();
    clues(string name, string description);
    string getDescription();
    string getName();
    bool operator==(clues &i);
    string addClue();
    int thisIsAGlobalVariable = 4;
};

#endif // CLUES_H
