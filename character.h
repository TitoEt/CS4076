#ifndef CHARACTER_H_
#define CHARACTER_H_
#include "ZorkUL.h"

#include <string>
using namespace std;
#include <vector>
using std::vector;//sequence containers that store elements for dynamic data - long way of saying storage managment


class Character {
private:
    string description;
     vector < string > cluesInCharacter;
public:
    void addClues(string Clue);
public:
    Character(string description);
    string shortDescription();
    string longDescription();

};

#endif CHARACTER_H_
