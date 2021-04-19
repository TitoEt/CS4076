#include "clues.h"

clues::clues(string name, string description)
{
    this->name = name;
    this->description = description;
}

bool clues::operator==(clues &i)
{
    int test = 0;

    if (this->getDescription() == i.getDescription())
    {
        test = 1;
    }
    return test;
}

string clues::getDescription()
{
    return description;
}

string clues::getName()
{
    return name;
}
