#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
//#include <vector>
using namespace std;

class Grid{
    public:
        Grid();
        ~Grid();
        Grid(int width, int height, double populationDensity);
        void createGrid(int width, int height, double populationDensity);
        void randomGrid(int width, int height, double populationDensity);
        void manuallyCreateGrid(int width, int height, double populationDensity);
        bool placeCell(double populationDensity);
    private:
        unsigned int width;
        unsigned int height;
        double populationDensity;

};

#endif