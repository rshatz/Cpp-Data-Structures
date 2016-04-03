//
//  main.cpp
//  Assignment2
//
//  Created by ritchie on 3/24/16.
//  Copyright © 2016 ritchie. All rights reserved.
//

#include <iostream>
#include "vector.h"

int main()
{
    vector v;

    v.appendNode(6);
    v.insertNode(2);

    v.appendNode(8);
    v.appendNode(2);
    v.appendNode(9);
    v.appendNode(1);
    v.insertNode(7);
    
    v.displayVect();
    
    std::cout << std::endl;
    
    vector copy(v);
    copy.displayVect();

    std::cout << std::endl;

    //copy.appendNode(0);
    //copy.insertNode(4);
    //copy.insertNode(8);

    //copy.displayVect();

    return 0;
}
