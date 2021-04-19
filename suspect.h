#ifndef SUSPECT_H
#define SUSPECT_H


class suspect
{
public:
    int suspecta, suspectb, suspectc, suspectd;
    suspect(int a, int b, int c, int d) {suspecta = a; suspectb = b; suspectc = c; suspectd = d;};

    suspect(const suspect &suspect) {suspecta = suspect.suspecta; suspectb = suspect.suspectb; suspectc = suspect.suspectc; suspectd = suspect.suspectd;}

    int getSusA()    { return suspecta;}
    int getSusB()    { return suspectb;}
    int getSusC()    { return suspectc;}
    int getSusD()    { return suspectd;}

};

#endif // SUSPECT_H
