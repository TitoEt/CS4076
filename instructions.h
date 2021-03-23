#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include <string>
using namespace std;

class instructions
{
private:
    string instuction;
    string secondWord;

public:
    instructions(string instruction, string secondWord);
    string getInstructions();
    string getSecondWord();
    bool isUnkown();
    bool hasSecondWord();
};

#endif // INSTRUCTIONS_H
