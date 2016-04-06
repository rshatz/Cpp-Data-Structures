#include "vector.h"
#include <iostream>

using namespace std;
int main()
{
    vector v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    v.displayVect();

    vector n(3);

    n.displayVect();
}
