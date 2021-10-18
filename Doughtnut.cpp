#include "Doughnut.h"

Doughnut::Doughnut(){
}

Doughnut::~Doughnut(){
}

void Doughnut::searchGrid(Grid* grid){ //search the grid, checking each individual cell to see what is alive and what isn't
    int count = 0;
    Grid* temp = new Grid();
    temp->copyGrid(grid);
        for(int i = 0; i < grid->getHeight(); ++i){ //rows
            for(int j = 0; j < grid->getWidth(); ++j){ //columns
                //Search each neighbor around (i,j)
                if (i == 0 && j == 0){ //checks if location is top left corner
                    if(temp->isAlive(i, j + 1)){  //checks cell to the right of it
                        count += 1;
                    } 
                    if (temp->isAlive(i + 1, j + 1)){ //checks cell diagonally bottom right to it
                        count += 1;
                    } 
                    if (temp->isAlive(i + 1, j)){ //checks cell under it
                        count += 1;
                    }
                    if (temp->isAlive(grid->getHeight()-1, j)){ //checks bottom row, same column
                        count += 1;
                    }
                    if (temp->isAlive(grid->getHeight() - 1, j+1)){ //checks bottom row, right column
                        count += 1;
                    }
                    if (temp->isAlive(i, grid->getWidth()-1)){ //checks same row, left column (far right)
                        count += 1;
                    }
                    if (temp->isAlive(i+1, grid->getWidth()-1)){ //checks diagonally bottom left
                        count += 1;
                    }
                    if (temp->isAlive(grid->getHeight()-1, grid->getWidth()-1)){ //checks opposite diagonal
                        count += 1;

                    }
                    

                    //cout << "count is " << count << endl;
                    if(count <= 1){
                        grid->dead(i, j);
                    } else if (count == 3){
                        grid->alive(i, j);
                    } else if (count >= 4){
                        grid->dead(i, j);
                    }
                    
                    count = 0;

                } else if (i == 0 && j == grid->getWidth() - 1){ //checks if location is top right corner
                    //cout << "(" << i << ", " << j << ")" << ": Is top right corner" << endl;
                    if (temp->isAlive(i + 1, j)){ //checks cell under it
                        count += 1;
                    } 
                    if (temp->isAlive(i + 1, j - 1)){ //checks cell diagonally bottom left of it
                        count += 1;
                    } 
                    if (temp->isAlive(i, j - 1)){ //checks cell to the left of it
                        count += 1;
                    }
                    if (temp->isAlive(grid->getHeight() - 1, j)){ //checks bottom row, same column
                        count += 1;
                    }
                    if (temp->isAlive(grid->getHeight() - 1, j-1)){ //checks bottom row, left column
                        count += 1;
                    }
                    if (temp->isAlive(0, 0)){ //check same row, right column
                        count += 1;
                    }
                    if (temp->isAlive(i+1, 0)){ //check row below, right column
                        count += 1;
                    }
                    if (temp->isAlive(grid->getHeight()-1, 0)){ //check opposite diagonal
                        count += 1;
                    }

                    if(count <= 1){
                        grid->dead(i, j);
                    } else if (count == 3){
                        grid->alive(i, j);
                    } else if (count >= 4){
                        grid->dead(i, j);
                    }
                    
                    count = 0;

                } else if (i == grid->getHeight() - 1 && j == 0) { //checks if location is a bottom left corner
                    //cout << "(" << i << ", " << j << ")" << ": Is bottom left corner" << endl;
                    if(temp->isAlive(i - 1, j)){ //checks cell above it
                        count += 1;
                    } 
                    if (temp->isAlive(i - 1, j + 1)){ //checks cell diagonally up right 
                        count += 1;
                    } 
                    if (temp->isAlive(i, j + 1)){ //checks cell to the right
                        count += 1;
                    }
                    if (temp->isAlive(0, 0)){ //checks first row, same column
                        count += 1;
                    }
                    if (temp->isAlive(0, j+1)){ //checks first row, right column
                        count += 1;
                    }
                    if (temp->isAlive(grid->getHeight()-1, grid->getWidth()-1)){ //same row, left column
                        count += 1;
                    }
                    if (temp->isAlive(i-1, grid->getWidth()-1)){ //check diagonally upper left
                        count += 1;
                    }
                    if (temp->isAlive(0, grid->getWidth()-1)){ //check diagonally lower left
                        count += 1;
                    }

                    if(count <= 1){
                        grid->dead(i, j);
                    } else if (count == 3){
                        grid->alive(i, j);
                    } else if (count >= 4){
                        grid->dead(i, j);
                    }
                    
                    count = 0;

                } else if (i == grid->getHeight() - 1 && j == grid->getWidth() - 1){ //checks if location is bottom right corner
                    //cout << "(" << i << ", " << j << ")" << ": Is bottom right corner" << endl;
                    if(temp->isAlive(i - 1, j)){ //checks cell above it
                        count += 1;
                    } 
                    if (temp->isAlive(i - 1, j - 1)){ //checks cell diagonally up left 
                        count += 1;
                    } 
                    if (temp->isAlive(i, j - 1)){ //checks cell to the left of it
                        count += 1;
                    }
                    if (temp->isAlive(0, j)){ //check directly below
                        count += 1;
                    }
                    if (temp->isAlive(0, j-1)){ //check diagonal lower left
                        count += 1;
                    }
                    if (temp->isAlive(i, 0)){ //check right column, same row
                        count += 1;
                    }
                    if (temp->isAlive(i-1, 0)){ //check diagonal right
                        count += 1;
                    }
                    if (temp->isAlive(0, 0)){ //check diagonal right
                        count += 1;
                    }


                    if(count <= 1){
                        grid->dead(i, j);
                    } else if (count == 3){
                        grid->alive(i, j);
                    } else if (count >= 4){
                        grid->dead(i, j);
                    }
                    
                    count = 0;
                }
                else if ((i == 0) && (j != 0 || j != grid->getWidth() - 1)){ //checks if current location is on the top edge of grid

                    if(temp->isAlive(i, j-1)){ //checks cell to the left
                        count += 1;
                    }
                    if(temp->isAlive(i, j+1)){ //checks cell to the right
                        count += 1;
                    }
                    if(temp->isAlive(i+1, j-1)){ //checks cell diagonally down left 
                        count += 1;
                    }
                    if(temp->isAlive(i+1, j)){ // checks cell under 
                        count += 1;
                    }
                    if(temp->isAlive(i+1, j+1)){ //checks cell diagonally down right
                        count += 1;
                    }
                    /*if(temp->isAlive(grid->getHeight()-1, j)){ //checks bottom row, same column
                        count += 1;
                    } 
                    if(temp->isAlive(grid->getHeight()-1, j-1)){ //checks bottom row, column to the left
                        count += 1;
                    } 
                    if(temp->isAlive(grid->getHeight()-1, j+1)){ //checks bottom row, column column to the right
                        count += 1;
                    } */

                    if(count <= 1){
                        grid->dead(i, j);
                    } else if (count == 3){
                        grid->alive(i, j);
                    } else if (count >= 4){
                        grid->dead(i, j);
                    }
                    
                    count = 0;

                } else if (i == grid->getHeight() - 1 && (j != 0 || j != grid->getWidth() - 1)) { // checks if current location is on bottom edge of grid
                    if(temp->isAlive(i-1, j-1)){ //checks cell diagonally up left
                        count += 1;
                    }
                    if(temp->isAlive(i-1, j)){ //checks cell above 
                        count += 1;
                    }
                    if(temp->isAlive(i-1, j+1)){ //cehcks cell diagonally up right
                        count += 1;
                    }
                    if(temp->isAlive(i, j-1)){ //checks cell to the left
                        count += 1;
                    }
                    if(temp->isAlive(i, j+1)){ //checks cell to the right
                        count += 1;
                    }
                    /*if(temp->isAlive(0, j)){ //checks top row, same column
                        count += 1;
                    }
                    if(temp->isAlive(0, j-1)){ //checks top row, column to the left
                        count += 1;
                    }
                    if(temp->isAlive(0, j+1)){ //checks top row, column to the right
                        count += 1;
                    }*/

                    if(count <= 1){
                        grid->dead(i, j);
                    } else if (count == 3){
                        grid->alive(i, j);
                    } else if (count >= 4){
                        grid->dead(i, j);
                    }
                    
                    count = 0;

                } else if (j == 0 && (i != 0 || i != grid->getHeight() - 1)){ //checks if current location is on left edge of grid
                    //cout << "(" << i << ", " << j << ")" << ": Is a left edge" << endl;
                    if(temp->isAlive(i-1, j)){ //checks cell above 
                        count += 1;
                    }
                    if(temp->isAlive(i-1, j+1)){ //checks cell diagonally up right 
                        count += 1;
                    }
                    if(temp->isAlive(i, j+1)){ //checks cell to the right
                        count += 1;
                    }
                    if(temp->isAlive(i+1, j)){ //checks cell under
                        count += 1;
                    }
                    if(temp->isAlive(i+1, j+1)){ //checks cell diagonally down right
                        count += 1;
                    }
                   /* if(temp->isAlive(i, grid->getHeight() - 1)){ //checks cell to the left, same row
                        count += 1;
                    }
                    if(temp->isAlive(i+1, grid->getHeight() - 1)){ //checks cell to the left, row above
                        count += 1;
                    }
                    if(temp->isAlive(i-1, grid->getHeight() - 1)){ //checks cell to the left, row below
                        count += 1;
                    }*/

                    if(count <= 1){
                        grid->dead(i, j);
                    } else if (count == 3){
                        grid->alive(i, j);
                    } else if (count >= 4){
                        grid->dead(i, j);
                    }
                    
                    count = 0;
                } else if (j == grid->getWidth() - 1 && (i != 0 || i != grid->getHeight() - 1)){ //checks if current location is on right edge of grid
                    //cout << "(" << i << ", " << j << ")" << ": Is a right edge" << endl;
                    if(temp->isAlive(i-1, j-1)){ //checks cell diagonally up left
                        count += 1;
                    }
                    if(temp->isAlive(i-1, j)){ //checks cell above 
                        count += 1;
                    }
                    if(temp->isAlive(i, j-1)){ //checks cell to the left
                        count += 1;
                    }
                    if(temp->isAlive(i+1, j-1)){ //checks cell diagonally down left 
                        count += 1;
                    }
                    if(temp->isAlive(i+1, j)){ // checks cell under 
                        count += 1;
                    }
                   /* if(temp->isAlive(i, 0)){ //checks cell to the right, same row
                        count += 1;
                    }
                    if(temp->isAlive(i+1, 0)){ //checks cell to the right, row above
                        count += 1;
                    }
                    if(temp->isAlive(i-1, 0)){ //checks cell to the right, row below
                        count += 1;
                    }*/

                    if(count <= 1){
                        grid->dead(i, j);
                    } else if (count == 3){
                        grid->alive(i, j);
                    } else if (count >= 4){
                        grid->dead(i, j);
                    }
                    
                    count = 0;

                } else if ((i > 0) && (j > 0) && (i < grid->getHeight() - 1) && (j < grid->getWidth() - 1)) { //checks if not in corner and not on edge
                    //cout << "(" << i << ", " << j << ")" << ": Can check all neighbors" << endl;
                    if(temp->isAlive(i-1, j-1)){ //checks cell diagonally up left
                        count += 1;
                    }
                    if(temp->isAlive(i-1, j)){ //checks cell above 
                        count += 1;
                    }
                    if(temp->isAlive(i-1, j+1)){ //cehcks cell diagonally up right
                        count += 1;
                    }
                    if(temp->isAlive(i, j-1)){ //checks cell to the left
                        count += 1;
                    }
                    if(temp->isAlive(i, j+1)){ //checks cell to the right
                        count += 1;
                    }
                    if(temp->isAlive(i+1, j-1)){ //checks cell diagonally down left 
                        count += 1;
                    }
                    if(temp->isAlive(i+1, j)){ // checks cell under 
                        count += 1;
                    }
                    if(temp->isAlive(i+1, j+1)){ //checks cell diagonally down right
                        count += 1;
                    }

                    if(count <= 1){
                        grid->dead(i, j);
                    } else if (count == 3){
                        grid->alive(i, j);
                    } else if (count >= 4){
                        grid->dead(i, j);
                    }
                    
                    count = 0;

                }
            }
        }
}

