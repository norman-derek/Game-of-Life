/* 
Derek Norman, Michael Woodward
2364922, 
norman@chapman.edu, 
CPSC-350-03, 
Assignment 3
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