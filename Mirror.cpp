#include "Mirror.h"

Mirror::Mirror(){
}

Mirror::~Mirror(){
}

/*
* This method is called searchGridMirror which searches each spot on a grid and updates the spot according to mirror game of life rules 
* This method takes a parameter of Grid* which represents the grid to search and update
*/
void Mirror::searchGridMirror(Grid* grid){ //search the grid, checking each individual cell to see what is alive and what isn't
    int count = 0;
    Grid* temp = new Grid();
    temp->copyGrid(grid);
        for(int i = 0; i < grid->getHeight(); ++i){ //rows
            for(int j = 0; j < grid->getWidth(); ++j){ //columns
                //Search each neighbor around (i,j)
                if (i == 0 && j == 0){ //checks if location is top left corner
                    if(temp->isAlive(i, j + 1)){  //checks cell to the right of it, also checks diagonally up right because it is a mirror of right cell
                        count += 2;
                    } 
                    if (temp->isAlive(i + 1, j + 1)){ //checks cell diagonally bottom right to it
                        count += 1;
                    } 
                    if (temp->isAlive(i + 1, j)){ //checks cell under it, also cehcks cell diagonally left down because it is a mirror of cell under
                        count += 2;
                    }
                    if(temp->isAlive(i, j)){ //if the corner isAlive in mirror mode then it will have 3 more alive neighbors
                        count += 3;
                    }

                    if(count <= 1){
                        grid->dead(i, j);
                    } else if (count == 3){
                        grid->alive(i, j);
                    } else if (count >= 4){
                        grid->dead(i, j);
                    }
                    
                    count = 0;

                } else if (i == 0 && j == grid->getWidth() - 1){ //checks if location is top right corner
                    if(temp->isAlive(i + 1, j)){ //checks cell under it, checks diagonally down right cell because it is a mirror of cell under 
                        count += 2;
                    } 
                    if (temp->isAlive(i + 1, j - 1)){ //checks cell diagonally bottom left of it
                        count += 1;
                    } 
                    if (temp->isAlive(i, j - 1)){ //checks cell to the left of it, also checks diagonally up left cell because it is a mirror of left cell
                        count += 2;
                    }
                    if (temp->isAlive(i, j)){ //if the corner isAlive in mirror mode then it will have 3 more alive neighbors
                        count += 3;
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
                    if(temp->isAlive(i - 1, j)){ //checks cell above it, also checks diagonally up left because it will be the same
                        count += 2;
                    } 
                    if (temp->isAlive(i - 1, j + 1)){ //checks cell diagonally up right 
                        count += 1;
                    } 
                    if (temp->isAlive(i, j + 1)){ //checks cell to the right, also checks diagonlly down right because it will also be alive if right is alive
                        count += 2;
                    }
                    if (temp->isAlive(i, j)){ //if the corner isAlive in mirror mode then it will have 3 more alive neighbors
                        count += 3;
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
                    if(temp->isAlive(i - 1, j)){ //checks cell above it, also checks diagonlly up right cell becuase it is a reflection of this cell
                        count += 2;
                    } 
                    if (temp->isAlive(i - 1, j - 1)){ //checks cell diagonally up left 
                        count += 1;
                    } 
                    if (temp->isAlive(i, j - 1)){ //checks cell to the left of it, also checks cell diagonlly down left because it is mirror of left cell
                        count += 2;
                    }
                    if (temp->isAlive(i, j)){ //if the corner isAlive in mirror mode then it will have 3 more alive neighbors
                        count += 3;
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
                    if(temp->isAlive(i, j-1)){ //checks cell to the left and diagonally top left would have same cell in mirror so we add 2 to count
                        count += 2;
                    }
                    if(temp->isAlive(i, j+1)){ //checks cell to the right and diagonally up right would have same value so we add 2 to count in mirror
                        count += 2;
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
                    if (temp->isAlive(i, j)){ //if current location is alive then the cell above is a mirror of current location and also alive so added to count
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
                    if(temp->isAlive(i, j-1)){ //checks cell to the left, cell is mirrored to diagonally down left cell. so we can add 2 to count if left is alive
                        count += 2;
                    }
                    if(temp->isAlive(i, j+1)){ //checks cell to the right, cell is mirrored to diagonally down right cell. so if right cell is alive we can add 2 to count
                        count += 2;
                    }
                    if (temp->isAlive(i, j)){ //checks cell under in mirror, if cell at current location is alive then since the cell under is mirrored then it is also alive
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

                } else if (j == 0 && (i != 0 || i != grid->getHeight() - 1)){ //checks if current location is on left edge of grid
                    if(temp->isAlive(i-1, j)){ //checks cell above, diagonally up left is mirrored from cell above so 2 can be added to count if above is alive
                        count += 2;
                    }
                    if(temp->isAlive(i-1, j+1)){ //checks cell diagonally up right 
                        count += 1;
                    }
                    if(temp->isAlive(i, j+1)){ //checks cell to the right
                        count += 1;
                    }
                    if(temp->isAlive(i+1, j)){ //checks cell under, since diagonally down left cell is mirrored from this cell 2 can be added because if cell under is alive so is diagonally down left cell
                        count += 2;
                    }
                    if(temp->isAlive(i+1, j+1)){ //checks cell diagonally down right
                        count += 1;
                    }
                    if (temp->isAlive(i, j)){ //cell to left is mirrored from current cell so if current cell is alive then left cell is alive
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
                } else if (j == grid->getWidth() - 1 && (i != 0 || i != grid->getHeight() - 1)){ //checks if current location is on right edge of grid
                    if(temp->isAlive(i-1, j-1)){ //checks cell diagonally up left
                        count += 1;
                    }
                    if(temp->isAlive(i-1, j)){ //checks cell above, diagonally up right is a mirror of this cell so 2 can be added to count if this cell is alive
                        count += 2;
                    }
                    if(temp->isAlive(i, j-1)){ //checks cell to the left
                        count += 1;
                    }
                    if(temp->isAlive(i+1, j-1)){ //checks cell diagonally down left 
                        count += 1;
                    }
                    if(temp->isAlive(i+1, j)){ // checks cell under, diagonally down right is a mirror of this cell so 2 can be added to count if this cell is alive
                        count += 2;
                    }
                    if (temp->isAlive(i, j)){ //checks right cell, right cell is mirror of current cell so if current cell is alive then right cell is alive
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

                } else if ((i > 0) && (j > 0) && (i < grid->getHeight() - 1) && (j < grid->getWidth() - 1)) { //checks if not in corner and not on edge
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

    delete temp;
}

