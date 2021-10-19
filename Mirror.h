/*
1)  
    a) Derek Norman, Michael Woodward
    b) 2364922, 2340070
    c) norman@chapman.edu, mwoodward@chapman.edu
    d) CPSC-350-03, CPSC-350-02
    e) Assignment 3
2)
    Header for the mirror game mode
3)
    a) Mirror() - constructor
    b) ~Mirror() - destructor
    c) searchGridMirror(Grid* grid) 
        - search the grid, checking each individual cell to see what is alive and what isn't
        - no return statement
        - takes in one parameter, the grid from the grid class
        - N/A
*/

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