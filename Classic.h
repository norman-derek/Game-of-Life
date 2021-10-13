#ifndef CLASSIC_H
#define CLASSIC_H

#include "Grid.h"
#include <iostream>

using namespace std;

class Classic:public Grid{ //classic is a subclass of grid
    public:
        void searchGrid();
}