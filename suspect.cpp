#include "suspect.h"
#include <iostream>
using namespace std;

suspect::suspect(const suspect  &suspect)
{
   int a; int b; int c; int d;
   int suspecta(a);
   int suspectb(b);
   int suspectc(c);
   int suspectd(d);
}

template <class T>
T Large(T n1, T n2)
{
    return (n1 > n2) ? n1 : n2;
}

int main(){
    suspect s2(int e, int f, int g,int h);
    suspect s1(int a, int b, int c, int d);

    int i1, i2;
    int f1, f2;
    char c1, c2;

    cout << "Get suspect details: \n";
    cin >> i1 >> i2;
    cout << Large(i1, i2) <<" enough evididence" << endl;

    cout << "\nEnter all clues so far:\n";
    cin >> f1 >> f2;
    cout << Large(f1, f2) <<" even more evidence" << endl;

    cout << "\nCompare the suspects:\n";
    cin >> c1 >> c2;
    cout << Large(c1, c2) << " this is definitely the culprit";

    return 0;
}
