#ifndef ENTITIES_H
#define ENTITIES_H
#include <string>
using namespace std;

class entities
{
public:
    entities(string name, string description);
    virtual ~entities() = default;
    string getName();
    string getDescription();
    virtual string getNameAndDesc() = 0; //<rach> pure virtual function, making it an abstract class

protected:
    string description;
    string name;
};

#endif // ENTITIES_H
