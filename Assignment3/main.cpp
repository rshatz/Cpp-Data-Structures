#include "vector.h"
#include <iostream>

template <typename T>
void print(vector<T>& vec)
{
    for (size_t i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << "\n";
}

int main()
{
    vector<std::string> vs;

    vs.push_back("0.0");
    vs.push_back("1.1");
    vs.push_back("2.2");
    vs.push_back("3.3");
    vs.push_back("4.4");
    vs.push_back("5.5");
    vs.push_back("6.6");

    vs.erase(0);

    vs.insert(4, "||");
    print(vs);

    //vector<std::string> vsc;
    //vsc = vs;

    //print(vsc);

    vector<double> vd(25);

    for (size_t i = 0; i < vd.size(); i++) {
        vd.erase(i);
        vd.insert(i, i * 1.01);
    }
    print(vd);
    vector<double> vdc(vd);
}
