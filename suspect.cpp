#include "suspect.h"
#include <iostream>
using namespace std;

//deep copy constructor
suspect::suspect(const suspect  &susp)
{

   ptr = new int;
   *ptr = *susp.ptr; // copy the value
}

template <typename T>
T Large(T n1, T n2)
{
    return (n1 > n2) ? n1 : n2;
}

struct S{
    unsigned int b : 3;
};

 S s= {6};
    ++s.b;
    std::cout << s.b << '\n';
    ++s.b;
    std::cout << s.b << '\n';
