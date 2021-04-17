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
    string longDescription;

public:
    clues();
    clues(string description);
    string getShortDescription();
    bool operator==(clues &i);
    string getLongDescription();
    string addClue();
    int thisIsAGlobalVariable = 4;
};

#endif // CLUES_H
