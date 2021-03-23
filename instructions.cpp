#include "instructions.h"

instructions::instructions(string firstWord, string secondWord)
{
    this->instruction = firstWord;
    this->secondWord = secondWord;

}

string instructions::getInstructions(){
    return this->instruction;
}

string instructions::getSecondWord(){
    return this->secondWord;
}

bool instructions::isUnknown(){
    return (instruction.empty());
}

bool instructions::hasSecondWord(){
    return (!secondWord.epty());
}
