/*
1)  
    a) Derek Norman, Michael Woodward
    b) 2364922, 2340070
    c) norman@chapman.edu, mwoodward@chapman.edu
    d) CPSC-350-03, CPSC-350-02
    e) Assignment 3
2)
    Header for the doughnut game mode
3)
    a) Doughnut() - constructor
    b) ~Doughnut() - destructor
    c) searchGridDoughnut(Grid* grid) 
        - search the grid, checking each individual cell to see what is alive and what isn't
        - no return statement
        - takes in one parameter, the grid from the grid class
        - N/A
*/


#ifndef DOUGHNUT_H
#define DOUGHNUT_H

#include "Grid.h"
#include <iostream>
#include <exception>

using namespace std;

class Doughnut {                       
    public:
        Doughnut();
        ~Doughnut();
        void searchGridDoughnut(Grid* grid); //searches grid and looks for alive locations

};

#endif