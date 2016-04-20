#include "vector.h"
#include <iostream>

template <typename T>
void print(List<T>& vec)
{
    for (size_t i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << "\n";
}

int main()
{
    List<std::string> stringVect;

    stringVect.push_back("0.0");
    stringVect.push_back("1.1");
    stringVect.push_back("2.2");
    stringVect.push_back("3.3");
    stringVect.push_back("4.4");
    stringVect.push_back("5.5");
    stringVect.push_back("6.6");
    stringVect.push_back("7.7");

    stringVect.erase(0);

    stringVect.insert(4, "||");
    print(stringVect);

    List<double> dblVect(10);

    for (size_t i = 0; i < dblVect.size(); i++) {
        dblVect.erase(i);
        dblVect.insert(i, (i + 1) * 1.01);
    }
    print(dblVect);
    List<int> intVect(10);

    intVect.insert(5, 5);
    intVect.insert(0, 1);
    print(intVect);

    List<int> copy(intVect);

    copy.push_back(17);
    copy.insert(0, 1);
    copy.erase(0);
    print(copy);

    List<int> assignment;
    assignment = copy;
    std::cout << "= copy: ";
    print(assignment);
}
