#include "vector.h"
#include <iostream>

using namespace std;

//void printVector(std::vector<int>& vec)
//{
//    for (int a : vec)
//    {
//        std::cout << a << " ";
//    }
//}

int main()
{
    vector v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    v.insert(2, 99);
    v.displayVect();
}
