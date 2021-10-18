#ifndef CLASSIC_H
#define CLASSIC_H

#include "Grid.h"
#include <iostream>
#include <exception>

using namespace std;

class Classic {                       //:public Grid{ //classic is a subclass of grid
    public:
        Classic();
        ~Classic();
        void searchGrid(Grid* grid); //searches grid and looks for alive locations

};

#endif