#include "clues.h"

clues::clues(string name, string description)
{
    this->name = name;
    this->description = description;
}

bool clues::operator==(clues &i)
{
    bool test = false;

    if (this->getDescription() == i.getDescription())
    {
        test = true;
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
