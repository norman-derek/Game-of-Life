#ifndef CLASSIC_H
#define CLASSIC_H

#include "Grid.h"
#include <iostream>
#include <exception>

using namespace std;

class Classic {                       //:public Grid{ //classic is a subclass of grid
    private:
        Grid* currGrid;  //current grid pointer
        Grid* nextGrid; //previous grid pointer

    public:
        Classic();
        ~Classic();

        Grid* searchGrid(Grid* grid); //searches grid and looks for alive locations
        void printNextGrid();
        void createNextGrid();

};

#endif