#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <fstream>

using namespace std;

class Grid{
    public:
        Grid();
        ~Grid();
        Grid(int width, int height, double populationDensity);
        char** createGrid(int width, int height, double populationDensity);
        void randomGrid();
        void manuallyCreateGrid();
        bool placeCell(double populationDensity);
        void printArray();
       // virtual void searchGrid() = 0; //this is implemented elsewhere (classic, donut, mirror)
    private:
        char **grid;
        int width;
        int height;
        double populationDensity;

};

#endif