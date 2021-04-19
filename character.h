#ifndef CHARACTER_H_
#define CHARACTER_H_
#include "zorkul.h"
#include "clues.h"

#include <string>
using namespace std;
#include <vector>
using std::vector;//sequence containers that store elements for dynamic data - long way of saying storage managment

class Character {

    //friend class allows friend(zorkul) access to this classes(character) private members
    friend class ZorkUL;
private:
    string description;
    vector < clues > inventory;

public:
    void addClues(clues &clue);
    void addClues(clues *clue);
    Character(string description);

protected:
    bool cluesCollected();
};

#endif// CHARACTER_H_
