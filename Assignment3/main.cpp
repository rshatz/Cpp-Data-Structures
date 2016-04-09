#include "vector.h"
#include <iostream>

int main()
{
    vector<std::string> vString;

    vString.push_back("1.1");
    vString.push_back("2.2");
    vString.push_back("3.3");
    vString.push_back("4.4");
    vString.push_back("5.5");

    vString.insert(0, "hello");
    vString.push_back("1.1");
    vString.push_back("2.2");
    vString.pop_back();
    vString.pop_back();
    vString.erase(0);
    vString.displayVect();

    vector<double> v2(10);
    v2.insert(0, 3.33);
    v2.displayVect();

    vector<double> v3(v2);
    v3.erase(0);
    v3.insert(0, 5.5);
    v3.push_back(9.9);
    v3.displayVect();

    vector<double> v4 = v3;

//    v4.displayVect();
//    for (int i = 0; i < 100; i++) {
//        v4.push_back(i + 1);
//    }
//    v4.displayVect();
//    int size = v4.size;
//    for (int i = 0; i < size; i++) {
//        v4.erase(0);
//    }
//    v4.displayVect();
}
