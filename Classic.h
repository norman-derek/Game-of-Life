#ifndef CLASSIC_H
#define CLASSIC_H

#include "Grid.h"
#include <iostream>
#include <exception>

using namespace std;

class Classic {                     
    public:
        Classic();
        ~Classic();
        void searchGridClassic(Grid* grid); //searches grid and looks for alive locations

};

#endif