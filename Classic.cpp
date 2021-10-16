#include "Classic.h"

Classic::Classic(){
    h = 0;
    w = 0;
    
}

Classic::~Classic(){
    for(int i = 0; i < getHeight(); ++i){ //fix variable, should not be height
        delete[] currGrid[i];
    }

    for(int i = 0; i < getHeight(); ++i){ //fix variable, should not be height
        delete[] prevGrid[i];
    }

    delete[] currGrid;
    delete[] prevGrid;
}

void Classic::alive(int h, int w){ //set a cell to be alive
    currGrid[h][w] = 'X';
}

void Classic::dead(int h, int w){ //sets a cell to be dead
    currGrid[h][w] = '-';
}

bool Classic::isAlive(int h, int w){ //check to see if a cell is alive
    return (currGrid[h][w] == 'X');
}

void Classic::createPrevGrid(){ //Creates the previous grid and saves it to prevGrid
    this->prevGrid = new char*[getHeight()];
    for (int i =0; i < getHeight(); ++i){
        prevGrid[i] = new char[getWidth()];
    }
    for(int i = 0; i < getHeight(); ++i){ //rows
        for(int j = 0; j < getWidth(); ++j){ //columns
            //Search each neighbor around (i,j)
            if(isAlive(i, j)){
                prevGrid[i][j] = 'X';

            } else if (!isAlive(i, j)){
                prevGrid[i][j] = '-';
            }
        }
    }
}

void Classic::searchGrid(){ //search the grid, checking each individual cell to see what is alive and what isn't
    currGrid = getGrid();
    createPrevGrid();
    int count = 0;
    cout << "=============== SEARCHING GRID ==============" << endl;
    for(int i = 0; i < getHeight(); ++i){ //rows
        for(int j = 0; j < getWidth(); ++j){ //columns
            //Search each neighbor around (i,j)
            if (i == 0 && j == 0){ //checks if location is top left corner
                cout << "(" << i << ", " << j << ")" << ": Is top left corner" << endl;

            } else if (i == 0 && j == getWidth() - 1){ //checks if location is top right corner
                cout << "(" << i << ", " << j << ")" << ": Is top right corner" << endl;
            } else if (i == getHeight() - 1 && j == 0) { //checks if location is a bottom left corner
                cout << "(" << i << ", " << j << ")" << ": Is bottom left corner" << endl;
            } else if (i == getHeight() - 1 && j == getWidth() - 1){ //checks if location is bottom right corner
                cout << "(" << i << ", " << j << ")" << ": Is bottom right corner" << endl;
            }
            else if ((i == 0)){ //checks if current location is on the top edge of grid
                cout << "(" << i << ", " << j << ")" << ": Is a top edge" << endl;

            } else if (i == getHeight() - 1) { // checks if current location is on bottom edge of grid
                cout << "(" << i << ", " << j << ")" << ": Is a bottom edge" << endl;

            } else if (j == 0){ //checks if current location is on left edge of grid
                cout << "(" << i << ", " << j << ")" << ": Is a left edge" << endl;

            } else if (j == getWidth() - 1){ //checks if current location is on right edge of grid
                cout << "(" << i << ", " << j << ")" << ": Is a right edge" << endl;

            } else if ((i > 0) && (j > 0) && (i < getHeight() - 1) && (j < getWidth() - 1)) { //checks if not in corner and not on edge
                cout << "(" << i << ", " << j << ")" << ": Can check all neighbors" << endl;
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

    cout << "Count is " << count << endl;
}

void Classic::printPrevGrid(){
    for (int i = 0; i < getHeight(); ++i){
        for (int j = 0; j < getWidth()  ; ++j){
            cout << "[" << prevGrid[i][j] << "], ";
        }
        cout << endl;
    } //prints out grid filled with populated spots
}

