#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
using namespace std;

class Grid{
    public:
        Grid();
        ~Grid();
        Grid(int width, int height, double populationDensity);
        char** createGrid(int width, int height, double populationDensity);
        void randomGrid();
        void manuallyCreateGrid(int width, int height, double populationDensity);
        bool placeCell(double populationDensity);
        void printArray();
    private:
        char **grid;
        unsigned int width;
        unsigned int height;
        double populationDensity;

};

#endif