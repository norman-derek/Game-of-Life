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
        void createGrid(int width, int height, double populationDensity);
        void randomGrid();
        void manuallyCreateGrid();
        int getHeight();
        int getWidth();
        char** getGrid();
        void setGrid(char** grid);
        void printArray();
        bool isAlive(int h, int w); //check to see if a grid is alive
        bool isStable(Grid* other);
        bool isEmpty();
        void alive(int h, int w); //add a new 'X' to a cell
        void dead(int h, int w); //sets a cell to dead by changing 'X' to '-'
        //virtual void searchGrid() = 0; //this is implemented elsewhere (classic, donut, mirror)
    private:
        char **grid;
        int width;
        int height;
        double populationDensity;

};

#endif