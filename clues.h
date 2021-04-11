#ifndef CLUES_H
#define CLUES_H

#include <map>
#include <string>
#include <iostream>
using namespace std;

class clues
{
private:
    string description;
    string longDescription;

public:
    clues();
    clues(string description);
    string getShortDescription();
    bool operator==(clues &i);
    string getLongDescription();
    string addClue();
};

#endif // CLUES_H
