#include "Character.h"

Character::Character(string description) {
    this->description = description;
}
void Character::addClue(Clue &clue) {
    cluesInCharacter.push_back(clue);
}
void Character::addClue(Clue *clue) {
    cluesInCharacter.push_back(*clue);
    delete clue;
}
string Character::longDescription()
{
  string ret = this->description;
  ret += "\n Item list:\n";
  for (vector<Clue>::iterator i = cluesInCharacter.begin(); i != cluesInCharacter.end(); i++)
    ret += "\t"+ (*i).getLongDescription() + "\n";
  return ret;
}
