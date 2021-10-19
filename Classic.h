/*
1)  
    a) Derek Norman, Michael Woodward
    b) 2364922, 2340070
    c) norman@chapman.edu, mwoodward@chapman.edu
    d) CPSC-350-03, CPSC-350-02
    e) Assignment 3
2)
    Runs the classic game mode
3)
    a) Classic() - constructor
    b) ~Classic() - destructor
    c) searchGridClassic(Grid* grid) 
        - search the grid, checking each individual cell to see what is alive and what isn't
        - no return statement
        - takes in one parameter, the grid from the grid class
        - N/A
*/

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