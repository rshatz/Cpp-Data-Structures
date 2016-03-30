//
//  main.cpp
//  Assignment2
//
//  Created by ritchie on 3/24/16.
//  Copyright © 2016 ritchie. All rights reserved.
//

#include <iostream>
#include "Vector.h"

int main()
{
    Vector simpleVect;

    simpleVect.appendNode(6);
    simpleVect.insertNode(2);

    simpleVect.appendNode(8);
    simpleVect.appendNode(2);
    simpleVect.appendNode(9);
    simpleVect.appendNode(1);
    simpleVect.insertNode(7);
    
    simpleVect.displayVect();
    
    std::cout << std::endl;
    
    Vector copy(simpleVect);
    copy.displayVect();

    std::cout << std::endl;

    copy.appendNode(0);
    copy.insertNode(4);
    copy.insertNode(8);

    copy.displayVect();

    return 0;
}
