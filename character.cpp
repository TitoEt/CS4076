#include "character.h"

Character::Character(string name, string description) : entities(name, description) {
}
void Character::addClues(clues &clue) {
    inventory.push_back(clue);
}

void Character::addClues(clues *clue) {
    inventory.push_back(*clue);
    delete clue;
}

string Character::getNameAndDesc() {
    return name + " " + description;
}

bool Character::cluesCollected(){
    int collection = 0;

    if(collection >= 0){
        return true;
    }else{
        return false;
    }
}
