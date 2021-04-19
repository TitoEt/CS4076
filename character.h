#ifndef CHARACTER_H_
#define CHARACTER_H_
#include "zorkul.h"
#include "clues.h"
#include "entities.h"

#include <string>
using namespace std;
#include <vector>
using std::vector;//sequence containers that store elements for dynamic data - long way of saying storage managment

class Character : public entities {

    //<Rach> friend class allows friend(zorkul) access to this classes(character) private members
    friend class ZorkUL;
private:
    vector < clues > inventory;

public:
    void addClues(clues &clue);
    void addClues(clues *clue);
    Character(string name, string description);
    string getNameAndDesc();

protected:
    bool cluesCollected();
};

#endif// CHARACTER_H_
