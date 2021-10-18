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
        void searchGrid(Grid* grid); //searches grid and looks for alive locations

};

#endif