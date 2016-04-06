//
//  main.cpp
//  Assignment2
//
//  Created by ritchie on 3/24/16.
//  Copyright © 2016 ritchie. All rights reserved.
//

#include <iostream>
#include "vector.h"
using namespace std;

int main()
{
    vector v;

    v.push_back(7);
    v.push_back(8);
    v.push_back(2);
    v.push_back(9);
    v.push_back(1);
    
    v.displayVect();
    cout << endl << v.size() << endl;

    vector q;
    cout << q.size() << endl;

//    vector vc(v);
//    vc.displayVect();
//    std::cout << std::endl;

//    vc.pop_back();
//    vc.pop_back();
//    vc.pop_back();

//    vc.displayVect();

//    std::cout << std::endl;
//    vector n;
//    n.pop_back();
//    n.pop_back();
//    n.displayVect();
//    n.push_back(9);
//    n.displayVect();
}
