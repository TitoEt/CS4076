#include "character.h"

Character::Character(string description) {
    this->description = description;
}
void Character::addClues(clues &clue) {
    inventory.push_back(clue);
}
void Character::addClues(clues *clue) {
    inventory.push_back(*clue);
    delete clue;
}

bool Character::cluesCollected(){
    int collection = 0;

    if(collection >= 0){
        return true;
    }else{
        return false;
    }
}
