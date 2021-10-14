#ifndef CLASSIC_H
#define CLASSIC_H

#include "Grid.h"


class Classic{                       //:public Grid{ //classic is a subclass of grid
    private:
        int h; //specific row location
        int w; //specific column location
        char **originalGrid; 
        char **copyGrid; 

    public:
        Classic();
        ~Classic();

        bool isAlive(); //check to see if a grid is alive
        void searchGrid();
        void alive(h, w); //add a new 'X' to a cell

       
};

#endif