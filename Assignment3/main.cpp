#include "vector.h"
#include <iostream>

using namespace std;

int main()
{
    vector v1;

    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(5);

    v1.insert(0, 5);
    v1.pop_back();
    v1.displayVect();

    vector v2(v1);
    v2.displayVect();

    vector v3 = v2;
    v3.erase(0);
    v3.insert(0, 55);
    v3.push_back(9999);
    v3.displayVect();
    cout << v3.size() << "\n";

    vector v4;

    for (int i = 0; i < 100; i++) {
        v4.push_back(i + 1);
    }
    v4.displayVect();
    for (int i = 0; i < 100; i++) {
        v4.erase(0);
    }
    v4.displayVect();
}
