//
//  function.cpp
//  Practice_CPP
//
//  Created by Nathan Hall on 8/6/19.
//  Copyright © 2019 NathanHall. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

void doSomething()
{
#ifdef PRINT
    cout << "PRINTING!";
#endif
    
#ifndef PRINT
    cout << "Not Printing!";
#endif
}
