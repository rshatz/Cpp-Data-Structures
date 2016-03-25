//
//  main.cpp
//  Assignment2
//
//  Created by ritchie on 3/24/16.
//  Copyright © 2016 ritchie. All rights reserved.
//

#include <iostream>
#include "SimpleVector.h"

int main()
{
    SimpleVector simpleVect;

    simpleVect.appendNode(6);
    simpleVect.appendNode(8);
    simpleVect.appendNode(2);
    simpleVect.appendNode(9);
    simpleVect.appendNode(1);
    simpleVect.insertNode(7);
    simpleVect.displayVect();

    return 0;

}
