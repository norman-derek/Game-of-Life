/*
1)  
    a) Derek Norman, Michael Woodward
    b) 2364922, 2340070
    c) norman@chapman.edu, mwoodward@chapman.edu
    d) CPSC-350-03, CPSC-350-02
    e) Assignment 3
2)
    Creates the Grid for the game
3)
    a) Grid() - constructor
    b) ~Grid() - destructor
    c) createGrid() 
        - creates a grid given height, width, and populationDensity.
        - no return statement
        - three parameters: width, height, and population density for the grid
        - N/A
    d) randomGrid() 
        - generates random parameters of height, width, and populationDensity for grid.
        - no return statement
        - N/A
        - N/A
    e) manuallyCreateGrid() 
        - creates a grid with a given map file that is a txt file
        - no return statement
        - N/A
        - N/A
    f) getHeight() 
        - returns height of grid
        - returns an integer
        - N/A
        - N/A
    g) getWidth() 
        - returns width of grid
        - returns an integer
        - N/A
        - N/A
    h) getGrid() 
        - returns grid
        - returns a char array
        - N/A
        - N/A
    i) printArray() 
        - prints grid
        - returns an integer
        - N/A
        - N/A
    j) isAlive() 
        - check to see if grid is alive
        - returns a bool
        - Two parameters - int height and width
        - N/A
    k) isStable() 
        - check to see if grid is stable
        - returns a bool
        - one parameter, Grid*
        - N/A
    l) isEmpty() 
        - check to see if grid is alive
        - returns a bool
        - n/a
        - N/A
    m) copyGrid() 
        - create a copy of the grid
        - N/A
        - Takes in a Grid parameter
        - N/A
    n) alive() 
        - adds a new X to the cell
        - n/a
        - Two parameters - int height and width
        - N/A
    o) dead() 
        - changes a cell to '-'
        - n/a
        - Two parameters - int height and width
        - N/A
    p) loc() 
        - finds the location of the char
        - returns a char
        - Two parameters - int height and width
        - N/A
*/

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
    private:
        char **grid; //grid pointer
        int width; //width of grid
        int height; //height of grid
        double populationDensity; //how much of grid is populated with 'alive' cells. 

};

#endif