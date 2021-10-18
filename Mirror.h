#ifndef MIRROR_H
#define MIRROR_H

#include "Grid.h"
#include <iostream>
#include <exception>

using namespace std;

class Mirror {                       
    public:
        Mirror();
        ~Mirror();
        void searchGridMirror(Grid* grid); //searches grid and looks for alive locations

};

#endif