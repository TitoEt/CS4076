#ifndef SUSPECT_H
#define SUSPECT_H


class suspect
{

private:
    int* ptr;

public:
    int suspecta, suspectb, suspectc, suspectd;
    suspect(int a = 0, int b= 0, int c = 0, int d = 0) {suspecta = a; suspectb = b; suspectc = c; suspectd = d;};

    suspect(const suspect &suspect); //{suspecta = suspect.suspecta; suspectb = suspect.suspectb; suspectc = suspect.suspectc; suspectd = suspect.suspectd;}

    int getSusA()    { return suspecta;}
    int getSusB()    { return suspectb;}
    int getSusC()    { return suspectc;}
    int getSusD()    { return suspectd;}

};

#endif // SUSPECT_H
