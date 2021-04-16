#include "character.h"

Character::Character(string description) {
    this->description = description;
}
void Character::addClues(clues &clue) {
    cluesInCharacter.push_back(clue);
}
void Character::addClues(clues *clue) {
    cluesInCharacter.push_back(*clue);
    delete clue;
}
string Character::longDescription()
{
  string ret = this->description;
  ret += "\n Item list:\n";
  for (vector<clues>::iterator i = cluesInCharacter.begin(); i != cluesInCharacter.end(); i++)
    ret += "\t"+ (*i).getLongDescription() + "\n";
  return ret;
}
