#include "Classic.h"

Classic::Classic(){
    h = -1;
    w = -1;

}

Classic::~Classic(){
    for(int i = 0; i < height; ++i){ //fix variable, should not be height
        delete[] originalGrid[i];
    }

    for(int i = 0; i < height; ++i){ //fix variable, should not be height
        delete[] copyGrid[i];
    }

    delete[] originalGrid;
    delete[] copyGrid;
}

void Classic::alive(h, w){ //set a cell to be alive
    originalGrid[h][w] = 'X';
}

bool Classic::isAlive(h, w){ //check to see if a cell is alive
    if(originalGrid[h][w] == 'X'){
        return true;
    }
}

void Classic::searchGrid(h, w){ //search the grid, checking each individual cell to see what is alive and what isn't
    int count = 0;
    for(int i = 0; i < h; ++i){ //rows
        for(int j = 0; j < w; ++j){ //columns
            //Search each neighbor around (i,j)
            if(isAlive(i-1, j-1)){
                count += 1;
            }
            else if(isAlive(i-1, j)){
                count += 1;
            }
            else if(isAlive(i-1, j+1)){
                count += 1;
            }
            else if(isAlive(i, j-1)){
                count += 1;
            }
            else if(isAlive(i, j+1)){
                count += 1;
            }
            else if(isAlive(i+1, j-1)){
                count += 1;
            }
            else if(isAlive(i+1, j)){
                count += 1;
            }
            else if(isAlive(i+1, j+1)){
                count += 1;
            }
        }
    }
}

