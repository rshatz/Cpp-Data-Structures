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

    // push_back inserts value at end of list
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    
    // display integers 1 - 5
    cout << "v: ";
    v.displayVect();
    cout << endl;

    // utilize vector copy constructor
    vector vc(v);
    // now vc has the same elements as v
    cout << "vc: ";
    vc.displayVect();
    cout << endl;

    // pop_back deletes last element in the list
    vc.pop_back();
    vc.pop_back();
    vc.pop_back();

    // vc now displays 1 - 2
    cout << "vc: ";
    vc.displayVect();
    cout << endl;

    vector n;
    // utilize overloaded = operator. n has same elements as vc
    n = vc;
    // add some more elements to n
    n.push_back(-1);
    n.push_back(-2);
    n.push_back(-3);

    cout << "n: ";
    n.displayVect();
    cout << endl;
}
