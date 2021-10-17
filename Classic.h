#ifndef CLASSIC_H
#define CLASSIC_H

#include "Grid.h"
#include <iostream>
#include <exception>

using namespace std;

class Classic: public Grid {                       //:public Grid{ //classic is a subclass of grid
    private:
        int h; //specific row location
        int w; //specific column location
        char **currGrid;  //current grid pointer
        char **nextGrid; //previous grid pointer

    public:
        Classic();
        ~Classic();

        bool isAlive(int h, int w); //check to see if a grid is alive
        bool isStable();
        bool isEmpty();
        void searchGrid(); //searches grid and looks for alive locations
        void alive(int h, int w); //add a new 'X' to a cell
        void dead(int h, int w); //sets a cell to dead by changing 'X' to '-'
        void printNextGrid();
        void createNextGrid();

};

#endif