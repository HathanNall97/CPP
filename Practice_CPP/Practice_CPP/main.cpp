//
//  main.cpp
//  Practice_CPP
//
//  Created by Nathan Hall on 8/6/19.
//  Copyright © 2019 NathanHall. All rights reserved.
//

#include <iostream>
#include "AddOn.hpp"

#define PRINT

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    std::cout << "Enter x: ";
    int x { 0 };
    std::cin >> x;
    
    std::cout << "Enter y: ";
    int y { 0 };
    std::cin >> y;
    
    int z{ adder(x, y) }; //Using AddOn.cpp >> adder()
    std::cout << x << " + " << y << " = " << z << "\n";
    
    int s{ subtracter(x, y) }; //Using AddOn.cpp >> adder()
    std::cout << x << " - " << y << " = " << s << "\n";
    
    int m{ multer(x, y) }; //Using AddOn.cpp >> multer()
    std::cout << x << " * " << y << " = " << m << "\n";
    
    int d{ divider(x, y) }; //Using AddOn.cpp >> divider()
    std::cout << x << " / " << y << " = " << d << "\n";
    
    return 0;
}
