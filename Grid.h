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
        Grid(); //constructor
        ~Grid(); //destructor
        void createGrid(int width, int height, double populationDensity); //creates a grid given height, width, and populationDensity.
        void randomGrid(); //generates random parameters of height, width, and populationDensity for grid.
        void manuallyCreateGrid(); //creates a grid with a given map file that is a txt file
        int getHeight(); //returns the height of grid
        int getWidth(); //returns the width of grid
        char** getGrid(); //returns the grid
        void printArray(); //prints the grid 
        bool isAlive(int h, int w); //check to see if a grid is alive
        bool isStable(Grid* other); //checks if a grid is equal to another grid which means it is stable
        bool isEmpty(); //checks if a grid is empty meaning all cells are dead
        void copyGrid(Grid* grid);
        void alive(int h, int w); //add a new 'X' to a cell
        void dead(int h, int w); //sets a cell to dead by changing 'X' to '-'
        char loc(int h, int w); //returns the char at a location
        //virtual void searchGrid() = 0; //this is implemented elsewhere (classic, donut, mirror)
    private:
        char **grid; //grid pointer
        int width; //width of grid
        int height; //height of grid
        double populationDensity; //how much of grid is populated with 'alive' cells. 

};

#endif