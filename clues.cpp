#include "clues.h"

clues::clues(string description)
{
    this->description = description;
}

bool clues::operator==(clues &i)
{
    int test = 0;

    if (this->getShortDescription() == i.getShortDescription())
    {
        test = 1;
    }

    return test;
}

string clues::getShortDescription()
{
    return description;
}

string clues::getLongDescription()
{
    return " clues(s), " + description + ".\n";
}
